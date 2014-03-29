/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_CURSESUI_HPP
#define UI_CURSESUI_HPP

#include "ui/UI.hpp" 
#include "frontend/UIState.hpp" 
#include "all/Coordinate.hpp" 
#include <curses.h>
#include <iostream>
#include <algorithm>

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
						void draw_game_map(all::Coordinate c);
						void drawMessageContainer(const frontend::GameMessageContainer& mc, all::Coordinate c, int height, int width);
						bool recalculate_layout();

						bool state_set;
						bool ui_initialized;
						bool layout_calc_needed;

						int max_x;
						int max_y;

						int margin_top_bot_left;
						int margin_top_bot_right;

						int margin_left;
						int margin_right;

						int gamemap_spacer_north;
						int gamemap_spacer_south;

						int gamemap_spacer_east;

						int info_spacer_north;
						int info_spacer_south;
						int info_max_width;
						int info_max_height;
						
						int message_height;
						int status_height;
						int hint_height;

						int top_bottom_width;

						WINDOW* p_window;

						int gm_w, gm_h;
		};

}
#endif
