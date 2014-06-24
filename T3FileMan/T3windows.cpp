#include "T3Windows.h"

int T3ErrorMGS(int errnum)
{
	switch (errnum)
	{
	case 1:
		MessageBox (NULL, TEXT ("ERROR IN OPEN FILE"), TEXT ("ERROR"), 0);
		exit(0);
		return 0;
	case 2:
		MessageBox (NULL, TEXT ("ERROR IN FILE"), TEXT ("ERROR"), 0);
		exit(0);
		return 0;
	}
}

int T3GetTime(
		int & Year,
		int & Month,
		int & Day,
		int & Hour,
		int & Minute,
		int & Second)
{
	SYSTEMTIME errt;
	GetLocalTime(&errt); 
	Year=errt.wYear;
	Month=errt.wMonth;
	Day=errt.wDay;
	Hour=errt.wHour;
	Minute=errt.wMinute;
	Second=errt.wSecond;
	return 0;
}