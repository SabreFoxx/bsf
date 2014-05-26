#pragma once

#include "CmD3D11Prerequisites.h"
#include "CmVideoModeInfo.h"

namespace BansheeEngine
{
	/**
	 * @copydoc	VideoMode
	 */
	class CM_D3D11_EXPORT D3D11VideoMode : public VideoMode
	{
	public:
		D3D11VideoMode(UINT32 width, UINT32 height, float refreshRate, UINT32 outputIdx, UINT32 refreshRateNumerator,
			UINT32 refreshRateDenominator, DXGI_MODE_DESC mode);

		/**
		 * @brief	Returns an internal DXGI representation of this video mode.
		 */
		const DXGI_MODE_DESC& getDXGIModeDesc() const { return mD3D11Mode; }

	private:
		friend class D3D11VideoOutputInfo;

		UINT32 refreshRateNumerator;
		UINT32 refreshRateDenominator;
		DXGI_MODE_DESC mD3D11Mode;
	};

	/**
	* @copydoc	VideoOutputInfo
	*/
	class CM_D3D11_EXPORT D3D11VideoOutputInfo : public VideoOutputInfo
	{
	public:
		D3D11VideoOutputInfo(IDXGIOutput* output, UINT32 outputIdx);
		~D3D11VideoOutputInfo();

		/**
		 * @brief	Returns the internal DXGI object representing an output device.
		 */
		IDXGIOutput* getDXGIOutput() const { return mDXGIOutput;  }

	private:
		IDXGIOutput* mDXGIOutput;
	};

	/**
	* @copydoc	VideoModeInfo
	*/
	class CM_D3D11_EXPORT D3D11VideoModeInfo : public VideoModeInfo
	{
	public:
		D3D11VideoModeInfo(IDXGIAdapter* dxgiAdapter);
	};
}