#include "ReactOnChange.h"
#include <wchar.h>
my::ReactOnChange::ReactOnChange(my::EdgeSearchBar& url) : url(url) {}
HRESULT STDMETHODCALLTYPE my::ReactOnChange::HandleAutomationEvent(
	IUIAutomationElement* p,
	EVENTID ev) {
	BSTR current{};
	url.val->get_CurrentValue(&current);
	size_t current_len = wcslen(current);
	wchar_t google[] = L"https://www.google.com/search?q=";
	size_t google_len = wcslen(google);
	wchar_t test[] = L"test:";
	size_t test_len = wcslen(test);
	wchar_t* pos = wcsstr(current, google);
	if (pos && !wcsstr(current, test)) {
		wchar_t* modified = new wchar_t[wcslen(current) + test_len + 1];
		wcscpy(modified, google);
		wcscpy(modified+google_len, test);
		wcscpy(modified + google_len + test_len, pos + google_len);
		url.val->SetValue(modified);
	}
	return S_OK;
}