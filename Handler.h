#pragma once
#include <UIAutomation.h>
namespace my {
	struct Handler : IUIAutomationEventHandler {
        LONG _refCount;
        int _eventCount;
        Handler();
        ULONG STDMETHODCALLTYPE AddRef();
        ULONG STDMETHODCALLTYPE Release();
        HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppInterface);
	};
}