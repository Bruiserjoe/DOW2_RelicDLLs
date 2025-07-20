#include "Input.hpp"


bool PlatInputUpdate(int* a1, HWND hwnd, int a3, int a4, int a5) {
	if (a3 == 5 || a3 == 126) {
		RECT rect;
		GetClientRect(hwnd, &rect);
		PlatInputRectRight = rect.right;
		PlatInputRectBottom = rect.bottom;
		if (MouseCapture) {
			platInputGlobal->CaptureCursor();
		}
	}
	if (platInputGlobal) {
		// sub_10003210 called here
		char v10 = 0;
		int* v = platInputGlobal->sub_10003210(hwnd, a3, a4, a5, &v10);
		*a1 = (int)v;
		if (!(v10 == 0)) {
			return true;
		}
	}
	if (a3 == 7) {
		// Plat::Input::InputAcquire (1, v9)
	}
	else if (a3 == 8) {
		// Plat::Input::InputAcquire (0, v9)
		return false;
	}
	return false;
}


BOOL Plat::Win32InputDevice::CaptureCursor() {
	if (!this->capture) {
		RECT rect;
		POINT point;
		GetClientRect(hwndGlobal, &rect);
		point.x = rect.left;
		point.y = rect.top;
		ClientToScreen(hwndGlobal, &point);
		LONG x = point.x;
		rect.top = point.y;
		point.x = rect.right;
		rect.left = x;
		ClientToScreen(hwndGlobal, &point);
		rect.right = point.x;
		rect.bottom = point.y;
		return ClipCursor(&rect);
	}
	return true;
}


void Plat::Input::InputAcquire(bool a2) {

}

int* Plat::Win32InputDevice::sub_10003210(HWND hWnd, unsigned int a3, unsigned int a4, int a5, char* a6) {
	
}