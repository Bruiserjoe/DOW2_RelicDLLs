#include "Window.hpp"

bool style = false;
bool destroy = false;
DWORD dwNewLong = 0;
DWORD dwStyle = 0;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	bool result = TRUE;
	if (uMsg > WM_SETCURSOR) {
		if (uMsg > WM_POWERBROADCAST) {
			if (uMsg == WM_WTSSESSION_CHANGE && wParam == 2) {
				windowShutdownRequested = TRUE;
				return FALSE;
			}
		}
		else {
			if (uMsg == WM_POWERBROADCAST) {
				return 1112363332;
			}
			if (uMsg == WM_SYSCOMMAND) {
				if ((wParam & 0xFFF0) == 61536)
				{
					windowShutdownRequested = TRUE;
					return FALSE;
				}
			}
			else if (uMsg == WM_HSCROLL && HIWORD(lParam)) {
				PostMessageA(hwnd, 0x1F, 0, 0);
				return FALSE;
			}
		}
		return DefWindowProcA(hwnd, uMsg, wParam, lParam);
	}
	else if (uMsg == WM_SETCURSOR) {
		return TRUE;
	}
	switch (uMsg) {
		case WM_DESTROY:
			hwnd = nullptr;
			if (!quitOnDestroy) {
				return FALSE;
			}
			PostQuitMessage(0);
			result = FALSE;
		break;
		case WM_CLOSE:
			windowShutdownRequested = TRUE;
			return FALSE;
		case WM_QUERYENDSESSION:
			if ((lParam & 1) != 0) {
				return TRUE;
			}
			return DefWindowProcA(hwnd, uMsg, wParam, lParam);
		case WM_ENDSESSION:
			if ((lParam & 1) == 0) {
				return DefWindowProcA(hwnd, uMsg, wParam, lParam);
			}
			result = FALSE;
			windowShutdownRequested = TRUE;
			break;
		default:
			return DefWindowProcA(hwnd, uMsg, wParam, lParam);
	}

	return result;
}

void Plat::Window::SetQuitOnDestroy(bool a2) {
	quitOnDestroy = a2;
}

bool Plat::Window::Setup(HWND hwnd) {
	if (!IsWindow(hwnd)) {
		return FALSE;
	}
	if (hwnd) {
		return FALSE;
	}
	WNDCLASSA WndClass;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.style = CS_HREDRAW | CS_OWNDC;
	WndClass.lpfnWndProc = WindowProc;
	WndClass.hInstance = GetModuleHandleA(0);
	HMODULE ModuleHandleA = GetModuleHandleA(0);
	WndClass.hIcon = LoadIconA(ModuleHandleA, (LPCSTR)0x65);
	WndClass.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(5);
	WndClass.lpszMenuName = 0;
	WndClass.lpszClassName = "Plat::Window {DB3DC0D7-BBA3-4d06-BCD8-40CD448B4AE3}";
	RegisterClassA(&WndClass);
	HMODULE module = GetModuleHandleA(0);
	HWND window = CreateWindowExA(
		dwNewLong,
		"Plat::Window{ DB3DC0D7 - BBA3 - 4d06 - BCD8 - 40CD448B4AE3 }",
		"DOW2",
		dwStyle,
		0,
		0,
		800,
		600,
		NULL,
		NULL,
		module,
		NULL
	);
	if (!window || !Attach(window)) {
		return FALSE;
	}
	hwnd = window;
	style = true;
	destroy = true;
	return TRUE;
}




BOOL Plat::Window::Attach(HWND a2) {
	if (!IsWindow(a2)) {
		return FALSE;
	}
	HWND v2 = a2;
	HWND parent = a2;
	if (a2) {
		do {
			v2 = parent;
			parent = GetParent(parent);
		} while (parent);
	}
	return FALSE;
}

char Plat::Window::SubclassWindow(HWND hwnd, void** func, int n) {
	return false;
}