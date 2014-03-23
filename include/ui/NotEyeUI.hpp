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


namespace ui{
		extern "C" void errorHandler(int id, const char *b1, const char *b2, int param);
		class NotEyeUI : public UI{

				public:
						NotEyeUI(std::string noteye_dir,std::string noteye_user_dir);
						virtual void set_uiState(const frontend::UIState& uiState);
						virtual void draw_uiState();
						virtual void init();
						virtual void init(bool for_restart);
						virtual void finish();
						virtual void finish(bool for_restart);
						virtual void restart();
						virtual bool process_input();
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
