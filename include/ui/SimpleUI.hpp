/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_SIMPLEUI_HPP
#define UI_SIMPLEUI_HPP

#include "ui/UI.hpp"
#include "all/GameAction.hpp"
#include <iostream>

namespace ui{
		class SimpleUI: public UI{
				public:
						virtual void set_uiState(const frontend::UIState& uiState);
						virtual void draw_uiState();
						virtual void init();
						virtual void finish();
						virtual all::GameAction process_input();

		};

}
#endif
