#include "ReactOnChange.h"
#include <wchar.h>
#include <stdio.h>
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
		wcscpy_s(modified, wcslen(current) + test_len + 1, google);
		wcscpy_s(modified+google_len, wcslen(current) + test_len + 1,test);
		wcscpy_s(modified + google_len + test_len, wcslen(current) + test_len + 1, pos + google_len);
		url.val->SetValue(modified);
		printf("changed url: %S\n\n", modified);
	}
	return S_OK;
}