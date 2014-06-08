/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_COLOREDSTRING_HPP
#define FRONTEND_COLOREDSTRING_HPP

#include <string>
#include "frontend/GameMapEntryColor.hpp"
#include "frontend/GameMapEntryAttribute.hpp"
#include "frontend/ColoredTextObject.hpp"

namespace frontend{

		class ColoredString : public ColoredTextObject {
				public:
						std::string str;
						ColoredString(const std::string& str, GameMapEntryColor color_fg, GameMapEntryColor color_bg, GameMapEntryAttribute attribute);
		};

}
#endif
