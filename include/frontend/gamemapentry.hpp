/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_GAMEMAPENTRY_HPP
#define FRONTEND_GAMEMAPENTRY_HPP

#include "frontend/gamemapentrycolor.hpp"
#include "frontend/gamemapentryattribute.hpp"


namespace frontend{
		class gamemapentry{
				public:
						int xdim, ydim;
						char symbol;
						gamemapentryColor color_fg, color_bg;
						gamemapentryAttribute attribute;
						gamemapentry(int xdim, int ydim, char symbol, gamemapentryColor color_fg, gamemapentryColor color_bg);
						gamemapentry(int xdim, int ydim, char symbol, gamemapentryColor color_fg, gamemapentryColor color_bg, gamemapentryAttribute attribute);
		}

}
#endif
