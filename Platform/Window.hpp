#pragma once
#include "Platform.hpp"

bool quitOnDestroy = false;
bool windowShutdownRequested = false;

namespace Plat {
	class Window {
		HWND hwnd;
	public:
		bool Setup(HWND a2);
		void SetQuitOnDestroy(bool a2);
		BOOL Attach(HWND a2);
		char SubclassWindow(HWND hwnd, void** func, int n);
	};

}