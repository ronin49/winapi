#pragma once
#include "Handler.h"
#include "EdgeSearchBar.h"
namespace my {
	struct ReactOnChange : my::Handler {
		ReactOnChange(my::EdgeSearchBar&);
		HRESULT STDMETHODCALLTYPE HandleAutomationEvent(
			IUIAutomationElement*,
			EVENTID);
		my::EdgeSearchBar& url;
	};
}