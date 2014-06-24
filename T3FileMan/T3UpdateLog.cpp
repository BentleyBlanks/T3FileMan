#include "windows.h"
#include "stdio.h"
#include "T3UpdateLog.h"
#define T3UPDATE /*是否更新日志*/true
#define T3VERSION /*引号内输入版本号*/"版本号：\n"
#define T3UPDATEINFORMATION /*引号内输入更新内容*/"更新内容：\n"
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