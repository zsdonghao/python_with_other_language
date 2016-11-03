/*
 * CtypeTest.c
 *
 *  Created on: 2014年08月17日
 *      Author: kyj
 */
#include "CtypeTest.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DataStruct * DataStruct_Create() {
	DataStruct *pdata = (DataStruct *)malloc(sizeof(DataStruct));
	if(pdata != NULL) {
		memset(pdata, 0, sizeof(DataStruct));
		pdata->purl = (char *)malloc(32);
		if(pdata->purl == NULL) {
			free(pdata);
			pdata = NULL;
		}
		else {
			memset(pdata->purl, 0, 32);
		}
	}
	printf("%s start\n", __func__);
	return pdata;
}

void DataStruct_Destroy(DataStruct *pdata) {
	printf("%s start\n", __func__);
	if(pdata != NULL) {
		free(pdata->purl);
		free(pdata);
		pdata = NULL;
	}
}

char * DataStruct_GetName(DataStruct *pdata) {
	printf("%s start\n", __func__);
	return pdata==NULL?NULL:pdata->name;
}

void DataStruct_SetName(DataStruct *pdata, char *name) {
	printf("%s start\n", __func__);
	if(pdata != NULL) {
		memset(pdata->name, 0, sizeof(pdata->name));
		strncpy(pdata->name, name, strlen(name));
	}
}

char * DataStruct_GetUrl(DataStruct *pdata) {
	printf("%s start\n", __func__);
	return pdata==NULL?NULL:pdata->purl;
}

void DataStruct_SetUrl(DataStruct *pdata, char *purl) {
	printf("%s start\n", __func__);
	if(pdata != NULL) {
		memset(pdata->purl, 0, 32);
		strncpy(pdata->purl, purl, strlen(purl));
	}
}

void * DataStruct_GetPriData(DataStruct *pdata) {
	printf("%s start\n", __func__);
	return pdata==NULL?NULL:pdata->pridata;
}





int add_test(int a, int b, int *sum) {
	*(int *)sum = a + b;
	return 0;
}

int add2_test(int a, int *b) {
	return a + *b;
}

int sub_test(int a, int b) {
	return a-b;
}

int sum2_test(int a, void *pc) {
	return a + *(int *)pc;
}

int sum3_test(int a, int *pb, void *pc) {
	return a + *pb + *(int *)pc;
}

int char1_test(char *retval, int ret) {
	strncpy(retval, "test", strlen("test"));
	return ret < 0? -1:0;
}

void char2_test(const char * app_id, const char * asr_res_path) {
	printf("app_id=%s asr_res_path=%s\n", app_id, asr_res_path);
}


