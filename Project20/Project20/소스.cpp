#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("����");

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
double LengthPts(int x1, int y1, int x2, int y2)//�� ���� �Ÿ��� ���ϴ� �Լ�
{
	return(sqrt((float)((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))));//�� �� ������ �Ÿ��� ����
}

BOOL InCircle(int x, int y, int mx, int my)
{
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;//�� �� ������ �Ÿ��� ������ ������ ��� Ʈ�� ����
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
		GetClientRect(hWnd, &rc);//ȭ��ũ��޾ƿ�
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
			for (int i = 0;i < 14;i++)//����
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
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								exit(0);//���α׷� ����
							}
						}
					}
				}
			}
			for (int i = 0;i < 14;i++)//����
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
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								exit(0);//���α׷� ����
							}
						}
					}
				}
			}
			for (int i = 0;i < 14;i++)//��밢
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
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								exit(0);//���α׷� ����
							}
						}
					}
				}
			}
			for (int i = 4;i < 18;i++)//�´밢
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
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								else if (count % 2 + 1 == 2)
								{
									MessageBox(hWnd, TEXT("�� �¸�"), TEXT("����"), MB_OK);//�޼��� ���
								}
								exit(0);//���α׷� ����
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
			for (int i = rc.left; i < rc.right; i += 50)//ȭ���� ���ʺ��� 50ũ�⾿ ���������� ���鼭 �ٱ���
			{
				MoveToEx(hdc, i, rc.top, NULL);
				LineTo(hdc, i, rc.bottom);
			}
			for (int i = rc.top; i < rc.bottom; i += 50)//ȭ���� ������ 50ũ�⾿ �������鼭 �ٱ���
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
