/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_CURSESCOLORMAP_HPP
#define FRONTEND_CURSESCOLORMAP_HPP


#include <map>
#include <curses.h>
#include "frontend/GameMapEntryColor.hpp"
#include "frontend/GameMapEntryAttribute.hpp"
#include "all/GameMessageType.hpp"

namespace ui{

		class CursesColorMap{
				public:
						CursesColorMap();
						short get_curses_color(const frontend::GameMapEntryColor& gmc);
						short get_curses_attribute(const frontend::GameMapEntryAttribute& gma);
				private:
						std::map<const frontend::GameMapEntryColor, short> color_map;	
						std::map<const frontend::GameMapEntryAttribute, short> attribute_map;

		};

}
#endif
