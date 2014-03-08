/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_GAMEMAPENTRY_HPP
#define FRONTEND_GAMEMAPENTRY_HPP

#include "frontend/GameMapEntryColor.hpp"
#include "frontend/GameMapEntryAttribute.hpp"


namespace frontend{
		//POD type
		class GameMapEntry{
				public:
						char symbol;
						GameMapEntryColor color_fg, color_bg;
						GameMapEntryAttribute attribute ;
						GameMapEntry(char symbol, GameMapEntryColor color_fg, GameMapEntryColor color_bg, GameMapEntryAttribute attribute);
		}

}
#endif
