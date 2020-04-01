#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("오목");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		480, 50, 917, 940,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}


#include<math.h>
#define BSIZE 25
double LengthPts(int x1, int y1, int x2, int y2)//두 점의 거리를 구하는 함수
{
	return(sqrt((float)((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))));//두 점 사이의 거리를 구함
}

BOOL InCircle(int x, int y, int mx, int my)
{
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;//두 점 사이의 거리가 반지름 이하일 경우 트루 리턴
	else return FALSE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rc;
	static int room[18][18];
	static int mx, my;
	static int count = 1;
	HBRUSH white, black;
	static int wincnt;

	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &rc);//화면크기받아옴
		return 0;
	case WM_LBUTTONDOWN:
		if (LOWORD(lParam) % 50 < 25) mx = LOWORD(lParam) / 50;
		else mx = LOWORD(lParam) / 50 + 1;
		if (HIWORD(lParam) % 50 < 25) my = HIWORD(lParam) / 50;
		else my = HIWORD(lParam) / 50 + 1;
		if (mx == 0) mx = 1;
		else if (mx == 18) mx = 17;
		if (my == 0) my = 1;
		else if (my == 18) my = 17;
		if (room[mx][my] == 0)
		{
			room[mx][my] = count % 2 + 1;
			InvalidateRect(hWnd, NULL, TRUE);
			for (int i = 0;i < 14;i++)//가로
			{
				for (int j = 0;j < 14;j++)
				{
					if (room[i][j] == count % 2 + 1)
					{
						wincnt = 0;
						for (int k = 1;k < 5;k++)
						{
							if (room[i + k][j] == room[i][j])
							{
								wincnt++;
							}
							else break;
							if (wincnt == 4)
							{
								if (count % 2 + 1 == 1)
								{
									MessageBox(hWnd, TEXT("백 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("흑 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								exit(0);//프로그램 종료
							}
						}
					}
				}
			}
			for (int i = 0;i < 14;i++)//세로
			{
				for (int j = 0;j < 14;j++)
				{
					if (room[i][j] == count % 2 + 1)
					{
						wincnt = 0;
						for (int k = 1;k < 5;k++)
						{
							if (room[i][j + k] == room[i][j])
							{
								wincnt++;
							}
							else break;
							if (wincnt == 4)
							{
								if (count % 2 + 1 == 1)
								{
									MessageBox(hWnd, TEXT("백 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("흑 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								exit(0);//프로그램 종료
							}
						}
					}
				}
			}
			for (int i = 0;i < 14;i++)//우대각
			{
				for (int j = 0;j < 14;j++)
				{
					if (room[i][j] == count % 2 + 1)
					{
						wincnt = 0;
						for (int k = 1;k < 5;k++)
						{
							if (room[i + k][j + k] == room[i][j])
							{
								wincnt++;
							}
							else break;
							if (wincnt == 4)
							{
								if (count % 2 + 1 == 1)
								{
									MessageBox(hWnd, TEXT("백 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("흑 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								exit(0);//프로그램 종료
							}
						}
					}
				}
			}
			for (int i = 4;i < 18;i++)//좌대각
			{
				for (int j = 0;j < 14;j++)
				{
					if (room[i][j] == count % 2 + 1)
					{
						wincnt = 0;
						for (int k = 1;k < 5;k++)
						{
							if (room[i - k][j + k] == room[i][j])
							{
								wincnt++;
							}
							else break;
							if (wincnt == 4)
							{
								if (count % 2 + 1 == 1)
								{
									MessageBox(hWnd, TEXT("백 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("흑 승리"), TEXT("종료"), MB_OK);//메세지 출력
								}
								exit(0);//프로그램 종료
							}
						}
					}
				}
			}
			count++;
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		white = CreateSolidBrush(RGB(255, 255, 255));
		black = CreateSolidBrush(RGB(0, 0, 0));
			for (int i = rc.left; i < rc.right; i += 50)//화면의 왼쪽부터 50크기씩 오른쪽으로 가면서 줄그음
			{
				MoveToEx(hdc, i, rc.top, NULL);
				LineTo(hdc, i, rc.bottom);
			}
			for (int i = rc.top; i < rc.bottom; i += 50)//화면의 위부터 50크기씩 내려가면서 줄그음
			{
				MoveToEx(hdc, rc.left, i, NULL);
				LineTo(hdc, rc.right, i);
			}
			for (int i = 0;i < 18;i++)
			{
				for (int j = 0;j < 18;j++)
				{
					if (room[i][j] == 1)
					{
						SelectObject(hdc, white);
						Ellipse(hdc, i * 50 - BSIZE, j * 50 - BSIZE, i * 50 + BSIZE, j * 50 + BSIZE);
					}
					else if (room[i][j] == 2)
					{
						SelectObject(hdc, black);
						Ellipse(hdc, i * 50 - BSIZE, j * 50 - BSIZE, i * 50 + BSIZE, j * 50 + BSIZE);
					}
				}
			}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
