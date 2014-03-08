/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_CURSESUI_HPP
#define UI_CURSESUI_HPP

#include "ui/UI.hpp" 

namespace UI{
		class CursesUI : public UI{
				public:
						void set_uistate();
						void draw_uistate();
						void init_uistate();
				private:
						void clear();

		}
}
#endif
