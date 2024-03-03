#include "connect.h"
#include <stdio.h>
void my::connect(const WindowManager& wm,
	const my::EdgeSearchBar& search,
	const my::ReactOnChange& handler) {
	wm.p->AddAutomationEventHandler(
		UIA_Text_TextChangedEventId,
		search.p,
		TreeScope_Element,
		NULL,
		(IUIAutomationEventHandler*)&handler);
	BSTR url;
	search.val->get_CurrentValue(&url);
	printf("current link: %S\n\n", url);
}