#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>


extern HWND hwndGlobal;


// setuphwnd blockers
//  - decompile sub_10003210
//  - decompile Plat::Input::InputAcquire

/*
DOW2Imports = [
    // Atomic
    "Plat::AtomicDecrement(int volatile *)",
    "Plat::AtomicCompareExchange(int volatile *,int,int)",
    "Plat::AtomicExchange(int volatile *,int)",
    "Plat::AtomicIncrement(int volatile *)",

    // App
    "Plat::App::Application::Application(void)",
    "Plat::App::GetApplication(void)",

    // File
    "Plat::File::GetPathExe(void)",
    "Plat::File::GetPathUserStorage(void)",
    "Plat::File::Shutdown(void)",
    "Plat::File::Setup(char const *)",

    // Input
    "Plat::Input::PumpEvent(Plat::InputEvent &)",
    "Plat::Input::CreateCursorInputEvent(float,float,float cons.",
    "Plat::Input::SetCursor(int)",
    "Plat::Input::GetComboKeyFromName(char const *)",
    "Plat::Input::GetComboKeyName(Plat::ComboKey const &",
    "Plat::Input::KeyChar(Plat::InputKey)",
    "Plat::Input::IsComboKeyPressed(Plat::ComboKey const..",
    "Plat::Input::CompareComboKey(Plat::ComboKey const &",
    "Plat::Input::GetComboKeyName(Plat::ComboKe..",
    "Plat::Input::UnLockCursor(void)",
    "Plat::Input::GetDragStart(Plat::InputKey,float &,float &)",
    "Plat::Input::FreezeCursor(void)",
    "Plat::Input::IsCursorVisible(void)",
    "Plat::Input::UnfreezeCursor(void)",
    "Plat::Input::GetCursorPos(float &,float &)",
    "Plat::Input::SetCursor(float)",
    "Plat::Input::SetCursorVisible(bool)",
    "Plat::Input::GetCursorVisibilityCount(void)",
    "Plat::Input::FlushCursorVisibility(bool)",
    "Plat::Input::HideCursor(void)",
    "Plat::Input::ShowCursor(void)",
    "Plat::Input::DisableIME(void)",
    "Plat::Input::Shutdown(void)",
    "Plat::Input::Poll(void)",

    // Interlocked
    "Plat::InterlockedExchange(Plat::InterlockedLockReader *)",
    "Plat::InterlockedList::Push(Plat::InterlockedListReader *)",
    "Plat::InterlockedList::Pop(Plat::InterlockedListReader *)",
    "Plat::InterlockedList::~InterlockedList(void)",
    "Plat::InterlockedList::Create(void)",
    "Plat::InterlockedList::Item::~Item(void)",
    "Plat::InterlockedList::Item::Item(void)",

    // Logger
    "Plat::Logger::DebugPrintWindowCreate(int,int,int,int)",
    "Plat::Logger::DebugPrint(char const *)",

    // Network
    "Plat::Network::GetMacAddress{STL::basic_string<char,...",

    // Options
    "Plat::Options::GetChar const *,STL::basic_string<char,...",
    "Plat::Options::Exists(char const *)",
    "Plat::Options::Setup(char const *)",
    "Plat::Options::Shutdown(void)",
    "Plat::Options::GetChar const *,int &)",
    "Plat::Options::GetOptionsAsString{STL::basic_string<ch..",
    "Plat::Options::GetChar const *,char *,uint)",

    // RecursiveMutex
    "Plat::RecursiveMutex::RecursiveMutex(void)",
    "Plat::RecursiveMutex::Leave(void)",
    "Plat::RecursiveMutex::Enter(void)",

    // System
    "Plat::System::GetFirstDiskInUse(int &)",
    "Plat::System::GetUsersLoadable{STL::basic_string<char,...",
    "Plat::System::GetCOMPort(uint &)",
    "Plat::System::GetMacAddressSpaceAvailable(int &)",
    "Plat::System::GetPhysicalMemoryAvailable(int &)",
    "Plat::System::GetPhysicalMemoryTotal(int &)",
    "Plat::System::GetPhysicalMemoryTotalAligned16(int &)",
    "Plat::System::GetVirtualAddressSpaceTotal(int &)",
    "Plat::System::GetSimulatedMemoryRatio(void)",
    "Plat::System::InitWindowsWithGoodVideoMemoryMapping.",
    "Plat::System::InitWindows32bit(void)",
    "Plat::System::GetClipboardText{STL::basic_string<char..",
    "Plat::System::RelaunchWindowsMediaCenter(void)",
    "Plat::System::InitWindowsMediaCenter(void)",

    // Timer
    "Plat::Timer::Timer(void)",
    "Plat::Timer::GetDeltaTime(void)",
    "Plat::Timer::GetCycleCount()",
    "Plat::Timer::ResetClock(void)",
    "Plat::Timer::TimeInNanos(Plat::Timer::SystemTime &)",
    "Plat::Timer::GetTimeMilliseconds(void)",
    "Plat::Timer::GetFullscreenMs(long,long)",
    "Plat::Timer::TimeStamp(Plat::Timer::SystemTime &)",
    "Plat::Timer::TakeTimeFocus(void)",

    // ThreadWatchdog
    "Plat::ThreadWatchdog::ThreadWatchdog(void)",

    // Window
    "Plat::Window::SetTitle(char const *)",
    "Plat::Window::ShutdownRequested(void)",
    "Plat::Window::ShowWindow(char const *,wchar_t c",
    "Plat::Window::Restore(void)",
    "Plat::Window::IsActive(void)",
    "Plat::Window::GetHandle(void)",
    "Plat::Window::GetWidth(void)",
    "Plat::Window::GetAspectRatio(void)",
    "Plat::Window::SetDisable(bool)",
    "Plat::Window::SetWindowPos(long,long,long,long)",
    "Plat::Window::UnSuccessfulWindowHWND__(void *)",
    "Plat::Window::SetupHWND__()", 
    "Plat::Window::ProcessMessages(void)", 
    "Plat::Window::ClassInitWindow(HWND__(void *) *,void *setde",

    // Win32
    "Plat::Win32::SetPlaylistToINSTANCE__()",

    // GUID
    "GUIDNull(void)",
    "GUIDFromString(GUID &,char const *)",
    "GUIDGenerate(void)",
    "GUIDToString(char *,uint,GUID const &,bool)",
]
*/
