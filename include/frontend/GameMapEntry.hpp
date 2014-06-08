/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_GAMEMAPENTRY_HPP
#define FRONTEND_GAMEMAPENTRY_HPP

#include "frontend/GameMapEntryColor.hpp"
#include "frontend/GameMapEntryAttribute.hpp"
#include "frontend/ColoredTextObject.hpp"


namespace frontend{
		//POD type
		class GameMapEntry: public ColoredTextObject{
				public:
						char symbol;
						GameMapEntry();
						GameMapEntry(char symbol, GameMapEntryColor color_fg, GameMapEntryColor color_bg, GameMapEntryAttribute attribute);
		};

}
#endif
