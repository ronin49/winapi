#pragma once
#include "WindowManager.h"
namespace my {
	struct EdgeSearchBar {
		EdgeSearchBar(my::WindowManager&);
		IUIAutomationElement* p;
		IUIAutomationValuePattern* val;
		my::WindowManager& wm;
	private:
		void initSearchBar(IUIAutomationElement*);
	};
}