﻿#include "core.h"

const char* g_contentMain =
	"#include \"pch.h\"\n"
	"#include \"main.h\"\n"
	"\n"
	"LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);\n"
	"\n"
	"int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)\n"
	"{\n"
	"	UNREFERENCED_PARAMETER(hPrevInstance);\n"
	"	UNREFERENCED_PARAMETER(lpCmdLine);\n"
	"\n"
	"	WNDCLASSEXW wcex;\n"
	"	wcex.cbSize = sizeof(WNDCLASSEX);\n"
	"	wcex.style          = CS_HREDRAW | CS_VREDRAW;\n"
	"	wcex.lpfnWndProc    = WndProc;\n"
	"	wcex.cbClsExtra     = 0;\n"
	"	wcex.cbWndExtra     = 0;\n"
	"	wcex.hInstance      = hInstance;\n"
	"	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP));\n"
	"	wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);\n"
	"	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);\n"
	"	wcex.lpszMenuName   = nullptr;\n"
	"	wcex.lpszClassName  = L\"WinAppClass\";\n"
	"	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));\n"
	"	if ( RegisterClassExW(&wcex)==0 )\n"
	"		return 0;\n"
	"\n"
	"	HWND hWnd = CreateWindowW(L\"WinAppClass\", L\"Title\", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);\n"
	"	if ( hWnd==NULL )\n"
	"		return 0;\n"
	"\n"
	"	ShowWindow(hWnd, nCmdShow);\n"
	"	UpdateWindow(hWnd);\n"
	"\n"
	"	MSG msg;\n"
	"	while ( GetMessage(&msg, nullptr, 0, 0) )\n"
	"	{\n"
	"		TranslateMessage(&msg);\n"
	"		DispatchMessage(&msg);\n"
	"	}\n"
	"\n"
	"#ifdef _DEBUG\n"
	"	_CrtDumpMemoryLeaks();\n"
	"#endif\n\n"
	"	return 0;\n"
	"}\n"
	"\n"
	"LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)\n"
	"{\n"
	"	switch (message)\n"
	"	{\n"
	"		case WM_COMMAND:\n"
	"		{\n"
	"			int id = LOWORD(wParam);\n"
	"			int notif = HIWORD(wParam);\n"
	"			return DefWindowProc(hWnd, message, wParam, lParam);\n"
	"			break;\n"
	"		}\n"
	"		case WM_PAINT:\n"
	"		{\n"
	"			PAINTSTRUCT ps;\n"
	"			HDC hdc = BeginPaint(hWnd, &ps);\n"
	"			EndPaint(hWnd, &ps);\n"
	"			break;\n"
	"		}\n"
	"		case WM_DESTROY:\n"
	"		{\n"
	"			PostQuitMessage(0);\n"
	"			break;\n"
	"		}\n"
	"		default:\n"
	"		{\n"
	"			return DefWindowProc(hWnd, message, wParam, lParam);\n"
	"			break;\n"
	"		}\n"
	"	}\n"
	"	return 0;\n"
	"}\n";

const char* g_contentMain2 =
	"#include \"pch.h\"\n"
	"#include \"main.h\"\n"
	"\n"
	"int main()\n"
	"{\n"
	"#ifdef _DEBUG\n"
	"	_CrtDumpMemoryLeaks();\n"
	"#endif\n\n"
	"	return 0;\n"
	"}\n";

const char* g_contentRc =
	"//Microsoft Visual C++ generated resource script.\n"
	"//\n"
	"#include \"resource.h\"\n"
	"\n"
	"/////////////////////////////////////////////////////////////////////////////\n"
	"//\n"
	"// Icon\n"
	"//\n"
	"\n"
	"// Icon with lowest ID value placed first to ensure application icon\n"
	"// remains consistent on all systems.\n"
	"\n"
	"IDI_APP       ICON         \"app.ico\"\n"
	"IDI_SMALL               ICON         \"small.ico\"\n"
	"\n"
	"/////////////////////////////////////////////////////////////////////////////\n"
	"//\n"
	"// Menu\n"
	"//\n"
	"\n"
	"IDC_APP MENU\n"
	"BEGIN\n"
	"    POPUP \"&File\"\n"
	"    BEGIN\n"
	"        MENUITEM \"E&xit\",                IDM_EXIT\n"
	"    END\n"
	"    POPUP \"&Help\"\n"
	"    BEGIN\n"
	"        MENUITEM \"&About ...\",           IDM_ABOUT\n"
	"    END\n"
	"END\n"
	"\n"
	"\n"
	"/////////////////////////////////////////////////////////////////////////////\n"
	"//\n"
	"// Accelerator\n"
	"//\n"
	"\n"
	"IDC_APP ACCELERATORS\n"
	"BEGIN\n"
	"    \"?\",            IDM_ABOUT,              ASCII,  ALT\n"
	"    \"/\",            IDM_ABOUT,              ASCII,  ALT\n"
	"END\n"
	"\n"
	"\n"
	"/////////////////////////////////////////////////////////////////////////////\n"
	"//\n"
	"// DESIGNINFO\n"
	"//\n"
	"\n"
	"#ifdef APSTUDIO_INVOKED\n"
	"GUIDELINES DESIGNINFO\n"
	"BEGIN\n"
	"    IDD_ABOUTBOX, DIALOG\n"
	"    BEGIN\n"
	"        LEFTMARGIN, 7\n"
	"        RIGHTMARGIN, 163\n"
	"        TOPMARGIN, 7\n"
	"        BOTTOMMARGIN, 55\n"
	"    END\n"
	"END\n"
	"#endif    // APSTUDIO_INVOKED\n"
	"\n"
	"\n"
	"/////////////////////////////////////////////////////////////////////////////\n"
	"//\n"
	"// String Table\n"
	"//\n"
	"\n"
	"STRINGTABLE\n"
	"BEGIN\n"
	"   IDC_APP   \"APP\"\n"
	"   IDS_APP_TITLE       \"App\"\n"
	"END\n"
	"\n"
	"/////////////////////////////////////////////////////////////////////////////\n"
	"\n"
	"\n"
	"\n";

const char* g_contentRes =
	"//{{NO_DEPENDENCIES}}\n"
	"// Microsoft Visual C++ generated include file.\n"
	"// Used by WindowsProject1solgen.rc\n"
	"\n"
	"#define IDS_APP_TITLE			103\n"
	"\n"
	"#define IDR_MAINFRAME			128\n"
	"#define IDD_APP_DIALOG	102\n"
	"#define IDD_ABOUTBOX			103\n"
	"#define IDM_ABOUT				104\n"
	"#define IDM_EXIT				105\n"
	"#define IDI_APP			107\n"
	"#define IDI_SMALL				108\n"
	"#define IDC_APP			109\n"
	"#define IDC_MYICON				2\n"
	"#ifndef IDC_STATIC\n"
	"#define IDC_STATIC				-1\n"
	"#endif\n"
	"// Next default values for new objects\n"
	"//\n"
	"#ifdef APSTUDIO_INVOKED\n"
	"#ifndef APSTUDIO_READONLY_SYMBOLS\n"
	"\n"
	"#define _APS_NO_MFC					130\n"
	"#define _APS_NEXT_RESOURCE_VALUE	129\n"
	"#define _APS_NEXT_COMMAND_VALUE		32771\n"
	"#define _APS_NEXT_CONTROL_VALUE		1000\n"
	"#define _APS_NEXT_SYMED_VALUE		110\n"
	"#endif\n"
	"#endif\n";

const char* g_contentPch =
	"#ifdef _DEBUG\n"
	"#include <crtdbg.h>\n"
    "#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )\n"
    "#define new DEBUG_NEW\n"
	"#endif\n";
