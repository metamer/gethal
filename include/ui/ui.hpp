/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_UI_HPP
#define UI_UI_HPP

#include "frontend/uistate.hpp"

namespace ui{
		class ui{
				public:
						virtual void set_uistate(const uistate&) =0;
						virtual void draw_uistate() =0;
						virtual void init_uistate() =0;
		};
}
#endif
