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
		bool v = platInputGlobal->sub_10003210(hwnd, a3, a4, a5, &v10);
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

bool Plat::Win32InputDevice::sub_10003210(HWND hwnd, unsigned int a3, unsigned int a4, int a5, char* a6) {
	bool result;
	if (!in2 || (result = in2->sub_10003210(hwnd, a3, a4, a5, a6), !*a6)) {
		if (in) {
			in->sub_10003210(hwnd, a3, a4, a5, a6);
		}
		result = (*a6 == 0);
		if (!*a6) {
			if (a3 == 32) {
				if (not_cursor == -1) {
					*a6 = 0;
					return false;
				}
				else {
					SetCursor(*cursor);
					*a6 = 1;
					return true;
				}
			}
		}
		if (*(char*)(a3 - 512) < 0xD && a3 != 522) {
			short high = HIWORD(a5);
			float v30 = ((double)a5 / (PlatInputRectRight - 1));
			float v31 = ((double)a5 / (PlatInputRectBottom - 1));
			// sub_10002690((int)&v30);
			float v28 = v30 - PreviousFloatRight;
			float v29 = v31 - PreviousFloatBottom;
			float v10 = 0.0f;
			float v11 = 0.0f;
			if (ByteGlobal1) {
				v10 = FloatGlobal1;
				v11 = FloatGlobal2;
			}
			else {
				PreviousFloatRight = v30;
				PreviousFloatBottom = v31;
				v11 = v31;
				v10 = v30;
			}
		}
	}

}