/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_CURSESUI_HPP
#define UI_CURSESUI_HPP

#include "ui/UI.hpp" 
#include "ui/Spacer.hpp" 
#include "frontend/UIState.hpp" 
#include "all/Coordinate.hpp" 
#include "frontend/GameStatusEntry.hpp" 
#include "frontend/GameNumericStatusEntry.hpp" 
#include "frontend/ColoredString.hpp" 
#include "ui/CursesColorMap.hpp" 
#include <curses.h>
#include <iostream>
#include <algorithm>
#include <vector>

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
						void create_status_line(std::vector<const frontend::GameStatusEntry*> entry_vec, all::Coordinate start_coord, int len_limit);
						void drawMessageContainer(const frontend::GameMessageContainer& mc, all::Coordinate c, int height, int width);
						void clear_bounds(all::Coordinate c, int height, int width);
						std::string get_status_entry_string(const frontend::GameStatusEntry& se);
						void drawStatusEntryContainer(const frontend::GameStatusEntryContainer& mc, all::Coordinate c, int height, int width);
						bool recalculate_layout();
						void draw_spacer(const Spacer& s);
						void draw_colored_string(const frontend::ColoredString& cs);

						bool state_set;
						bool ui_initialized;
						bool layout_calc_needed;

						int max_x;
						int max_y;

						int margin_top_bot_left;
						int margin_top_bot_right;

						int margin_top;
						int margin_bot;
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
						std::string spacer_char;

						CursesColorMap ccm;
		};

}
#endif
