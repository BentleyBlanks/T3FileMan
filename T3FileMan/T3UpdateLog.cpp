#include "windows.h"
#include "stdio.h"
#include "T3UpdateLog.h"
#define T3UPDATE /*�Ƿ������־*/true
#define T3VERSION /*����������汾��*/"�汾�ţ�\n"
#define T3UPDATEINFORMATION /*�����������������*/"�������ݣ�\n"
int T3UpdateLog()
{
	if(T3UPDATE)
	{
		FILE * puf;
		SYSTEMTIME upt;
		GetLocalTime(&upt); 
		if(fopen_s(&puf,"./log/updatelog.txt","a")==0)
		{
			fprintf(puf,"%d-%d-%d %d:%d:%d : ",
		upt.wYear,upt.wMonth,upt.wDay,upt.wHour,upt.wMinute,upt.wSecond);
			fprintf(puf,T3VERSION);
			fprintf(puf,T3UPDATEINFORMATION);
			fclose(puf);
		}
	}
	return 0;
}