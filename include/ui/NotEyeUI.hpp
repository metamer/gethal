/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_NOTEYEUI_HPP
#define UI_NOTEYEUI_HPP

#include "ui/UI.hpp" 
#include <noteye-curses.h>
#include <noteye.h>
#include <iostream>
#include "all/GameAction.hpp" 

namespace ui{
		extern "C" void errorHandler(int id, const char *b1, const char *b2, int param);
		class NotEyeUI : public UI{

				public:
						NotEyeUI(std::string noteye_dir,std::string noteye_user_dir);
						void set_uiState(const frontend::UIState& uiState);
						void draw_uiState();
						void init();
						void init(bool for_restart);
						void finish();
						void finish(bool for_restart);
						void restart();
						all::GameAction process_input();
						virtual ~NotEyeUI(){}
				private:
						std::string noteye_dir;
						std::string noteye_user_dir;
						static int HEADER_ROW_OFFSET;
						static int HEADER_COLUMN_OFFSET;
						static int MESSAGE_LIMIT;
						static int MESSAGE_MAP_COLUMN_OFFSET;
		};
}
#endif
