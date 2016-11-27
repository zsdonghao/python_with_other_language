/*
 * pipe_c.c
 *
 *  Created on: 2016年11月21日
 *      Author: kyj
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pipe_service.h"

static int pipe_init(const char *path, int mode) {
    int res, fd;

    if(path == NULL)
    	return -1;

    /*check pipe exist*/
    if(access(path, F_OK) == 0)
    	unlink(path);
    /*create pipe*/
    if( (res = mkfifo(path, O_CREAT|O_EXCL|0755)) < 0)
       return -2;
    /*open pipe*/
    fd = open(path, mode);
    if(fd < 0){
        unlink(path);
        return -3;
    }
    return fd;
}

int CPipeTest_Init(CPipeTest *pipe) {
	int fd;

	if(pipe == NULL)
		return -1;

	fd = pipe_init(WRITE_FIFO_PATH, O_RDWR);
	if(fd < 0) {
		printf("create write pipe failed, errcode=%d\n", fd);
		return -2;
	}
	pipe->pipe_write = fd;

	fd = pipe_init(READ_FIFO_PATH, O_RDWR);
	if(fd < 0) {
		printf("create read pipe failed, errcode=%d\n", fd);
		return -3;
	}
	pipe->pipe_read = fd;
	return 0;
}

void CPipeTest_Cleanup(CPipeTest *pipe) {
	if(pipe != NULL) {
		if(pipe->pipe_write > 0) {
			close(pipe->pipe_write);
			unlink(WRITE_FIFO_PATH);
		}
		if(pipe->pipe_read > 0) {
			close(pipe->pipe_read);
			unlink(READ_FIFO_PATH);
		}
	}
}

CPipeTest * CPipeTest_Create() {
	CPipeTest *pipe = (CPipeTest *)malloc(sizeof(CPipeTest));
	if(pipe != NULL) {
		memset(pipe, 0, sizeof(CPipeTest));
		if(CPipeTest_Init(pipe) < 0) {
			free(pipe);
			pipe = NULL;
		}
	}
	return pipe;
}

void CPipeTest_Destroy(CPipeTest *pipe) {
	if(pipe != NULL) {
		CPipeTest_Cleanup(pipe);
		free(pipe);
	}
}

void CPipeTest_Service(CPipeTest *pipe) {
    char sendbuff[MAXLINE];
    char recvbuff[MAXLINE];

	while(1) {
		memset(recvbuff, 0, sizeof(recvbuff));
		if(read(pipe->pipe_read, recvbuff, sizeof(recvbuff)) < 0) {
			printf("read from pipe error\n");
		}
		printf("receive message from sender:%s\n", recvbuff);
		memset(sendbuff, 0, sizeof(sendbuff));
		snprintf(sendbuff, sizeof(sendbuff), "receive message from sneder:%s", recvbuff);
		if(write(pipe->pipe_write, sendbuff, strlen(sendbuff)) < 0) {
			printf("write to pipe error\n");
		}
	}
}

int CPipeTest_Test() {
	CPipeTest *pipe = NULL;

	pipe = CPipeTest_Create();
	if(pipe == NULL) {
		printf("create and init CPipeTest fail\n");
		return -1;
	}
	CPipeTest_Service(pipe);
	CPipeTest_Destroy(pipe);
	return 0;
}






