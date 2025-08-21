

#ifndef FRAME3D311
#define FRAME3D311

#include <d3d11.h>
#include <dxgi.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")


class d3d11 {

private:

	void frameD3D11(

		HWND hwnd,
		D3D_FEATURE_LEVEL levels[],
		IDXGIAdapter* adapterPtr,
	    IDXGISwapChain* swapChainPtr,
		ID3D11Device* devicePtr,
		ID3D11DeviceContext* deviceContextPtr


	) {

		HRESULT h;

	    DXGI_SWAP_CHAIN_DESC chain_desc = {0};

		chain_desc.BufferCount = 1;
		chain_desc.SampleDesc.Count = 1;
		chain_desc.SampleDesc.Quality = 0;
		chain_desc.BufferDesc.Width = 1500;
		chain_desc.BufferDesc.Height = 800;
		chain_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		chain_desc.BufferDesc.RefreshRate.Denominator = 1;
		chain_desc.BufferDesc.RefreshRate.Numerator = 60;
		chain_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		chain_desc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		chain_desc.OutputWindow = hwnd;
		chain_desc.Windowed = TRUE;

		h = D3D11CreateDeviceAndSwapChain(

			adapterPtr,
			D3D_DRIVER_TYPE_HARDWARE,
			0,
			0,
			levels,
			0,
			D3D11_SDK_VERSION,
			&chain_desc,
			&swapChainPtr,
			&devicePtr,
			levels,
			&deviceContextPtr);

		if (FAILED(h)) {

			MessageBoxExW(

				hwnd,
				L"D3D11CreateDeviceAndSwapChain not created successfully",
				L"Error",
				MB_OK |MB_ICONERROR,
				0);

			exit(-1); // cierra todo el programa inmediatamente
		}

		D3D11_VIEWPORT viewport = {0};

		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.MinDepth = 0.0f;
		viewport.Width = 1500.0f;
		viewport.Height = 800.0f;

		deviceContextPtr->RSSetViewports(1, &viewport);




	}

	void renderGraphic() {


	}

	void view() {




	}
};











#endif 
