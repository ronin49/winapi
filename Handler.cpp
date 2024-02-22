#include "Handler.h"
my::Handler::Handler() : _refCount(1), _eventCount(0){}
ULONG STDMETHODCALLTYPE my::Handler::AddRef() {
    return InterlockedIncrement(&_refCount);
}
ULONG STDMETHODCALLTYPE my::Handler::Release() {
    ULONG ret = InterlockedDecrement(&_refCount);
    if (ret == 0)delete this;
    return ret;
}
HRESULT STDMETHODCALLTYPE my::Handler::QueryInterface(
    REFIID riid,
    void** ppInterface) {
    if (riid == __uuidof(IUnknown))
        *ppInterface = static_cast<IUIAutomationEventHandler*>(this);
    else if (riid == __uuidof(IUIAutomationEventHandler))
        *ppInterface = static_cast<IUIAutomationEventHandler*>(this);
    else {
        *ppInterface = NULL;
        return E_NOINTERFACE;
    }
    this->AddRef();
    return S_OK;
}