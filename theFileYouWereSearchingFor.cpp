#include "WindowManager.h"
#include "EdgeSearchBar.h"
#include "ReactOnChange.h"
#include "connect.h"
int main() {
	my::WindowManager wm;
	my::EdgeSearchBar edgeSearchBar(wm);
	my::ReactOnChange reactOnChange(edgeSearchBar);
	my::connect(wm, edgeSearchBar, reactOnChange);
	for (;;);
}