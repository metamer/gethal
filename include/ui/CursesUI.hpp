/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_CURSESUI_HPP
#define UI_CURSESUI_HPP

#include "ui/UI.hpp" 

namespace ui{
		class CursesUI : public UI{
				public:
						void set_uiState();
						void draw_uiState();
						void init_uiState();
				private:
						void clear();

		};
}
#endif
