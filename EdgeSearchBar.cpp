#include "EdgeSearchBar.h"
#include <stdio.h>
static void initSearchBar(IUIAutomationElement*);
my::EdgeSearchBar::EdgeSearchBar(my::WindowManager&wm) : wm(wm) {
    IUIAutomationElement* pRoot = NULL;
    wm.p->GetRootElement(&pRoot);
    if (!initSearchBar(pRoot)) {
        printf("ERROR: cannot find edge url field, make sure edge is running and then relaunch this app");
        exit(1);
    }
}
bool my::EdgeSearchBar::initSearchBar(IUIAutomationElement*p) {
    if (p == NULL)
        return false;
    IUIAutomationTreeWalker* pControlWalker = NULL;
    wm.p->get_ControlViewWalker(&pControlWalker);
    pControlWalker->GetFirstChildElement(p, &p);
    while (p) {
        BSTR desc;
        p->get_CurrentClassName(&desc);
        if (0 == wcscmp(desc, L"OmniboxViewViews")) {
            this->p = p;
            p->GetCurrentPatternAs(UIA_ValuePatternId, __uuidof(IUIAutomationValuePattern),
                reinterpret_cast<void**>(&val));
            return true;
        }
        if (initSearchBar(p)) return true;
        IUIAutomationElement* pNext;
        pControlWalker->GetNextSiblingElement(p, &pNext);
        p->Release();
        p = pNext;
    }
    return false;
}