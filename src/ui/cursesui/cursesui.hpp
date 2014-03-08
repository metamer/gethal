/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_CURSESUI_HPP
#define UI_CURSESUI_HPP

#include "ui/ui.hpp" 

namespace ui{
		class cursesui : public ui{
				public:
						void set_uistate();
						void draw_uistate();
						void init_uistate();
				private:
						void clear();

		}
}
#endif
