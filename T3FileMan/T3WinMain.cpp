#include "windows.h"
#include "T3FileMan.h"
#include "T3UpdateLog.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

T3Object T3DemoO;
T3Object T3DemoM[10];


int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
        PSTR szCmdLine, int iCmdShow)
{

	static TCHAR szAppName[] = TEXT ("T3") ;
    HWND   hwnd ;
    MSG    msg ;
    WNDCLASS wndclass ;
    wndclass.style        = CS_HREDRAW | CS_VREDRAW ;
    wndclass.lpfnWndProc  = WndProc ;
    wndclass.cbClsExtra   = 0 ;
    wndclass.cbWndExtra   = 0 ;
    wndclass.hInstance    = hInstance ;
    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground= (HBRUSH) GetStockObject (WHITE_BRUSH) ;
    wndclass.lpszMenuName  = NULL ;
    wndclass.lpszClassName= szAppName ;
    if (!RegisterClass (&wndclass))
    {
        MessageBox (  NULL, TEXT ("This program requires Windows NT!"),
			szAppName, MB_ICONERROR) ;
        return 0 ;
    }
    hwnd = CreateWindow( 
		szAppName,      // window class name
		TEXT ("blabla...–¥∏ˆWindows≥Ã–Úª·À¿∞°"),   // window caption
		WS_OVERLAPPEDWINDOW,  // window style
		CW_USEDEFAULT,// initial x position
		CW_USEDEFAULT,// initial y position
		800,// initial x size
		600,// initial y size
		NULL,                 // parent window handle
		NULL,            // window menu handle
		hInstance,   // program instance handle
		NULL) ;      // creation parameters
    ShowWindow (hwnd, iCmdShow) ;
    UpdateWindow (hwnd) ;
	T3UpdateLog();
	T3Load(T3DemoO,"p1f.txt");
	int numOfModel;
	T3LoadMap(T3DemoM,"amap1.txt",numOfModel);


	SetTimer (hwnd, 1, 15, NULL) ;
	SetTimer (hwnd, 2, 1000, NULL) ;

    while (GetMessage (&msg, NULL, 0, 0))
    {
		TranslateMessage (&msg) ;
        DispatchMessage (&msg) ;
    }
    return msg.wParam ;
}
        

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC     hdc;
	static HDC buffer_hdc = CreateCompatibleDC(NULL);
	HBITMAP bmp;
    PAINTSTRUCT ps ;
    static RECT    rect ;
	static int FlagDone=1,Frame=0;
	static TCHAR TFrame[7]=L"FPS:  ";
    switch (message)
    {
		case WM_CREATE:
			return 0 ;
        case WM_PAINT:
			hdc = BeginPaint (hwnd, &ps) ;
			GetClientRect (hwnd, &rect) ;
			EndPaint (hwnd, &ps) ;
			return 0 ;
		case WM_DESTROY:
			PostQuitMessage (0) ;
			return 0;
		case WM_LBUTTONDOWN:
			hdc=GetDC(hwnd);	

/*			bmp = CreateCompatibleBitmap(hdc,800,600);
			SelectObject(buffer_hdc,bmp);
			BitBlt(buffer_hdc,0,0,800,600,hdc,0,0,SRCCOPY);

			COLORREF DColor;
			DColor=RGB(255,255,0);
			T3Draw(buffer_hdc,hwnd,T3Demo,DColor);

			BitBlt(hdc,0,0,800,600,buffer_hdc,0,0,SRCCOPY);
			DeleteObject(bmp);
*/			ReleaseDC(hwnd,hdc);
			return 0 ;
		case WM_RBUTTONDOWN:

			return 0 ;
		case   WM_TIMER :
			switch (wParam)
			{
			case 1:
			if(FlagDone)
			{
				FlagDone=0;
				hdc=GetDC(hwnd);

/*				bmp = CreateCompatibleBitmap(hdc,800,600);
				SelectObject(buffer_hdc,bmp);
				BitBlt(buffer_hdc,0,0,800,600,hdc,0,0,SRCCOPY);

				TextOut(buffer_hdc,700,200,TFrame,6);
				T3Refresh(buffer_hdc,hwnd);
				POINT RO;COLORREF RColor;
				RO.x=400;RO.y=300;
				RColor=RGB(255,255,255);
				T3Revolve(buffer_hdc,hwnd,T3Demo,RO,RColor);

				BitBlt(hdc,0,0,800,600,buffer_hdc,0,0,SRCCOPY);
				DeleteObject(bmp);
*/
				ReleaseDC(hwnd,hdc);
				Frame++;
				FlagDone=1;
			}
			return 0;
			case 2:
				if (Frame<10)
				{
					TFrame[4]=L'0';
					_itow_s(Frame,&TFrame[5], 2, 10);
				}
				else
					_itow_s(Frame,&TFrame[4], 3, 10);
				Frame=0;

				return 0;
			}
    }
	return DefWindowProc (hwnd, message, wParam, lParam) ;     
}
