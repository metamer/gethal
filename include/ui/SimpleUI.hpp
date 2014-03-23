/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_SIMPLEUI_HPP
#define UI_SIMPLEUI_HPP

#include "ui/UI.hpp"
#include <iostream>

namespace ui{
		class SimpleUI: public UI{
				public:
						virtual void set_uiState(const frontend::UIState& uiState);
						virtual void draw_uiState();
						virtual void init();
						virtual void finish();
						virtual bool process_input();

		};

}
#endif
