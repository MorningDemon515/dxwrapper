/**
* Copyright (C) 2023 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "..\ddraw.h"

HRESULT m_IDirectDrawSurface::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	if (!ProxyInterface)
	{
		if (ppvObj)
		{
			*ppvObj = nullptr;
		}
		return E_NOINTERFACE;
	}
	return ProxyInterface->QueryInterface(ReplaceIIDUnknown(riid, WrapperID), ppvObj, DirectXVersion);
}

ULONG m_IDirectDrawSurface::AddRef()
{
	if (!ProxyInterface)
	{
		return 0;
	}
	return ProxyInterface->AddRef(DirectXVersion);
}

ULONG m_IDirectDrawSurface::Release()
{
	if (!ProxyInterface)
	{
		return 0;
	}
	return ProxyInterface->Release(DirectXVersion);
}

HRESULT m_IDirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->AddAttachedSurface((LPDIRECTDRAWSURFACE7)a);
}

HRESULT m_IDirectDrawSurface::AddOverlayDirtyRect(LPRECT a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->AddOverlayDirtyRect(a);
}

HRESULT m_IDirectDrawSurface::Blt(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDBLTFX e)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDRECT;	// Just return invalid rect
	}
	return ProxyInterface->Blt(a, (LPDIRECTDRAWSURFACE7)b, c, d, e);
}

HRESULT m_IDirectDrawSurface::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->BltBatch(a, b, c);
}

HRESULT m_IDirectDrawSurface::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE c, LPRECT d, DWORD e)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->BltFast(a, b, (LPDIRECTDRAWSURFACE7)c, d, e);
}

HRESULT m_IDirectDrawSurface::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->DeleteAttachedSurface(a, (LPDIRECTDRAWSURFACE7)b);
}

HRESULT m_IDirectDrawSurface::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->EnumAttachedSurfaces(a, b, DirectXVersion);
}

HRESULT m_IDirectDrawSurface::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK c)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->EnumOverlayZOrders(a, b, c, DirectXVersion);
}

HRESULT m_IDirectDrawSurface::Flip(LPDIRECTDRAWSURFACE a, DWORD b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->Flip((LPDIRECTDRAWSURFACE7)a, b, DirectXVersion);
}

HRESULT m_IDirectDrawSurface::GetAttachedSurface(LPDDSCAPS a, LPDIRECTDRAWSURFACE FAR * b)
{
	if (!ProxyInterface)
	{
		if (b)
		{
			*b = nullptr;
		}
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetAttachedSurface(a, (LPDIRECTDRAWSURFACE7*)b, DirectXVersion);
}

HRESULT m_IDirectDrawSurface::GetBltStatus(DWORD a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetBltStatus(a);
}

HRESULT m_IDirectDrawSurface::GetCaps(LPDDSCAPS a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetCaps(a);
}

HRESULT m_IDirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
	if (!ProxyInterface)
	{
		if (a)
		{
			*a = nullptr;
		}
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetClipper(a);
}

HRESULT m_IDirectDrawSurface::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetColorKey(a, b);
}

HRESULT m_IDirectDrawSurface::GetDC(HDC FAR * a)
{
	if (!ProxyInterface)
	{
		if (a)
		{
			*a = nullptr;
		}
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetDC(a);
}

HRESULT m_IDirectDrawSurface::GetFlipStatus(DWORD a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetFlipStatus(a);
}

HRESULT m_IDirectDrawSurface::GetOverlayPosition(LPLONG a, LPLONG b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetOverlayPosition(a, b);
}

HRESULT m_IDirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
	if (!ProxyInterface)
	{
		if (a)
		{
			*a = nullptr;
		}
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetPalette(a);
}

HRESULT m_IDirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetPixelFormat(a);
}

HRESULT m_IDirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->GetSurfaceDesc(a);
}

HRESULT m_IDirectDrawSurface::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->Initialize(a, b);
}

HRESULT m_IDirectDrawSurface::IsLost()
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->IsLost();
}

HRESULT m_IDirectDrawSurface::Lock(LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d)
{
	if (!ProxyInterface)
	{
		if (b)
		{
			b->lpSurface = nullptr;
		}
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->Lock(a, b, c, d, DirectXVersion);
}

HRESULT m_IDirectDrawSurface::ReleaseDC(HDC a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->ReleaseDC(a);
}

HRESULT m_IDirectDrawSurface::Restore()
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->Restore();
}

HRESULT m_IDirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->SetClipper(a);
}

HRESULT m_IDirectDrawSurface::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->SetColorKey(a, b);
}

HRESULT m_IDirectDrawSurface::SetOverlayPosition(LONG a, LONG b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->SetOverlayPosition(a, b);
}

HRESULT m_IDirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->SetPalette(a);
}

HRESULT m_IDirectDrawSurface::Unlock(LPVOID a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->Unlock((LPRECT)a);
}

HRESULT m_IDirectDrawSurface::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->UpdateOverlay(a, (LPDIRECTDRAWSURFACE7)b, c, d, e);
}

HRESULT m_IDirectDrawSurface::UpdateOverlayDisplay(DWORD a)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->UpdateOverlayDisplay(a);
}

HRESULT m_IDirectDrawSurface::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE b)
{
	if (!ProxyInterface)
	{
		return DDERR_INVALIDOBJECT;
	}
	return ProxyInterface->UpdateOverlayZOrder(a, (LPDIRECTDRAWSURFACE7)b);
}
