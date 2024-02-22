#include "EdgeSearchBar.h"
static void initSearchBar(IUIAutomationElement*);
my::EdgeSearchBar::EdgeSearchBar(my::WindowManager&wm) : wm(wm) {
    IUIAutomationElement* pRoot = NULL;
    wm.p->GetRootElement(&pRoot);
    try { initSearchBar(pRoot); } catch (...) {}
}
void my::EdgeSearchBar::initSearchBar(IUIAutomationElement*p) {
    if (p == NULL)
        return;
    IUIAutomationTreeWalker* pControlWalker = NULL;
    wm.p->get_ControlViewWalker(&pControlWalker);
    pControlWalker->GetFirstChildElement(p, &p);
    while (p) {
        BSTR desc;
        p->get_CurrentAutomationId(&desc);
        if (0 == wcscmp(desc, L"view_1022")) {
            this->p = p;
            p->GetCurrentPatternAs(UIA_ValuePatternId, __uuidof(IUIAutomationValuePattern),
                reinterpret_cast<void**>(&val));
            throw 777;
        }
        initSearchBar(p);
        IUIAutomationElement* pNext;
        pControlWalker->GetNextSiblingElement(p, &pNext);
        p->Release();
        p = pNext;
    }
}