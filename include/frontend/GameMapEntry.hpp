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
		class GameMapEntry{
				public:
						int xdim, ydim;
						char symbol;
						GameMapEntryColor color_fg, color_bg;
						GameMapEntryAttribute attribute;
						GameMapEntry(int xdim, int ydim, char symbol, GameMapEntryColor color_fg, GameMapEntryColor color_bg);
						GameMapEntry(int xdim, int ydim, char symbol, GameMapEntryColor color_fg, GameMapEntryColor color_bg, GameMapEntryAttribute attribute);
		}

}
#endif
