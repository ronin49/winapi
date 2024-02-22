#pragma once
#include "WindowManager.h"
#include "EdgeSearchBar.h"
#include "ReactOnChange.h"
namespace my {
	void connect(const my::WindowManager&,
		const my::EdgeSearchBar&,
		const my::ReactOnChange&);
}