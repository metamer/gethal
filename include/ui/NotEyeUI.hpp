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
		class NotEyeUI : public UI{

				public:
						NotEyeUI(std::string noteye_dir,std::string noteye_user_dir);
						virtual void set_uiState(const frontend::UIState& uiState);
						virtual void draw_uiState();
						virtual void init();
				private:
						std::string noteye_dir;
						std::string noteye_user_dir;
		};
}
#endif
