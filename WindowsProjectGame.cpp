// WindowsProjectGame.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WindowsProjectGame.h"

LRESULT CALLBACK Winproc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg){ 

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}


int APIENTRY wWinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,_In_ int nCmdShow){

	const wchar_t* name = L"Windows game";

	WNDCLASSEXW wnd = {0};

	wnd.lpszClassName = name;
	wnd.hInstance = hInstance;
	wnd.cbSize = sizeof(WNDCLASSEXW);
	wnd.lpfnWndProc = Winproc;
	wnd.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassExW(&wnd)) {

		MessageBoxExW(
			nullptr,
			L"WNDCLASSEXW was not created successfully",
			L"Error", MB_OK | MB_ICONERROR,0 );

		return -1;
	}

	HWND hwnd = CreateWindowExW(

		WS_EX_OVERLAPPEDWINDOW,
		name,
		L"Game",
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		1500,
		800,
		nullptr,
		nullptr,
		hInstance,
		nullptr );

	if (hwnd == nullptr) {

		MessageBoxExW(
			nullptr,
			L"HWND was not created successfully",
			L"Error", 
			MB_OK | MB_ICONERROR, 
			0);

		return -1;

	}

	//----------------------------------------------------------------------------------------------------------------------//

	const D3D_FEATURE_LEVEL level[] = { 

		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_11_1 };

	IDXGIAdapter* adapterPtr = nullptr;
	IDXGISwapChain* swapChainPtr = nullptr;
	ID3D11DeviceContext* deviceContextPtr;
	








	//----------------------------------------------------------------------------------------------------------------------//

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg = { 0 };

	while (GetMessageW(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return (int)msg.wParam;

}
