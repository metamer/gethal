/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_COLOREDTEXTOBJECT_HPP
#define FRONTEND_COLOREDTEXTOBJECT_HPP

#include "frontend/GameMapEntryColor.hpp"
#include "frontend/GameMapEntryAttribute.hpp"


namespace frontend{
		class ColoredTextObject{
				public:
						GameMapEntryColor color_fg, color_bg;
						GameMapEntryAttribute attribute ;
						ColoredTextObject();
						ColoredTextObject(GameMapEntryColor color_fg, GameMapEntryColor color_bg, GameMapEntryAttribute attribute);
		};

}
#endif
