/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_SPACER_HPP
#define UI_SPACER_HPP

#include <string>
#include "all/Coordinate.hpp"
#include "frontend/UIComponent.hpp"

namespace ui{
		class Spacer : public frontend::UIComponent{
				public:
					Spacer(const all::Coordinate& start_coord, int height, int width);
					all::Coordinate start_coord;
		};

}
#endif
