#pragma once
#include "Platform.hpp"


namespace Plat {
	class Input {
	protected:
		bool capture;
		Input* in;
		Input* in2;
	public:
		virtual BOOL CaptureCursor();
		virtual bool sub_10003210(HWND hWnd, unsigned int a3, unsigned int a4, int a5, char* a6);
		void InputAcquire(bool a2);
	};
	class Win32InputDevice : Input {
	private:

	public:
		BOOL CaptureCursor();
		bool sub_10003210(HWND hWnd, unsigned int a3, unsigned int a4, int a5, char* a6);
	};
}


extern Plat::Input* platInputGlobal = nullptr;
extern LONG PlatInputRectRight = 0;
extern LONG PlatInputRectBottom = 0;
extern bool MouseCapture = false;

bool PlatInputUpdate(int* a1, HWND hWnd, int a3, int a4, int a5);
