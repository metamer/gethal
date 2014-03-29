/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_CURSESUI_HPP
#define UI_CURSESUI_HPP

#include "ui/UI.hpp" 
#include <curses.h>
#include <iostream>

namespace ui{
		class CursesUI : public UI{

				public:
						CursesUI();
						void set_uiState(const frontend::UIState& uiState);
						void draw_uiState();
						void init();
						void finish();
						void restart();
						bool process_input();
				private:
						static int HEADER_ROW_OFFSET;
						static int HEADER_COLUMN_OFFSET;
						static int MESSAGE_LIMIT;
						static int MESSAGE_MAP_COLUMN_OFFSET;
						WINDOW* p_window;
		};

}
#endif
