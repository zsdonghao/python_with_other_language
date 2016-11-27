#ifndef _PIPE_SERVICE_H_HEADER
#define _PIPE_SERVICE_H_HEADER
/*
 * pipe_c.h
 *
 *  Created on: 2016年11月21日
 *      Author: kyj
 */


#define WRITE_FIFO_PATH	"/tmp/write_fifo"
#define READ_FIFO_PATH	"/tmp/read_fifo"
#define MAXLINE 512


typedef struct _CPipeTest {
	int pipe_write;
	int pipe_read;
}CPipeTest;

extern CPipeTest * CPipeTest_Create();
extern void CPipeTest_Destroy(CPipeTest *pipe);
extern void CPipeTest_Service(CPipeTest *pipe);
extern int CPipeTest_Test();

#endif







