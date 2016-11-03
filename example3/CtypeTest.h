/*
 * CtypeTest.h
 *
 *  Created on: 2014年08月17日
 *      Author: kyj
 */

#ifndef CTYPETEST_H_
#define CTYPETEST_H_

typedef struct _DataStruct {
	int	id;
	char name[16];
	char *purl;
	void *pridata;
}DataStruct;

extern DataStruct * DataStruct_Create();
extern void DataStruct_Destroy(DataStruct *pdata);
extern char * DataStruct_GetName(DataStruct *pdata);
extern void DataStruct_SetName(DataStruct *pdata, char *name);
extern char * DataStruct_GetUrl(DataStruct *pdata);
extern void DataStruct_SetUrl(DataStruct *pdata, char *url);
extern void * DataStruct_GetPriData(DataStruct *pdata);


extern int sub_test(int a, int b);
extern int add2_test(int a, int *b);
extern int add_test(int a, int b, int *sum);
extern int sum2_test(int a, void *pc);
extern int sum3_test(int a, int *pb, void *pc);
extern int char1_test(char *retval, int ret);
extern void char2_test(const char * app_id, const char * asr_res_path);

#endif /* CTYPETEST_H_ */
