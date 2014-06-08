#include "ui/CursesColorMap.hpp"

namespace ui{
		CursesColorMap::CursesColorMap(){
				color_map = {
						{frontend::GameMapEntryColor::BLACK,COLOR_BLACK},
						{frontend::GameMapEntryColor::WHITE,COLOR_WHITE},
						{frontend::GameMapEntryColor::RED,COLOR_RED},
						{frontend::GameMapEntryColor::BLUE,COLOR_BLUE},
						{frontend::GameMapEntryColor::YELLOW,COLOR_YELLOW},
						{frontend::GameMapEntryColor::GREEN,COLOR_GREEN},
						{frontend::GameMapEntryColor::CYAN,COLOR_CYAN},
						{frontend::GameMapEntryColor::MAGENTA,COLOR_MAGENTA}
				};

				attribute_map = {
						{frontend::GameMapEntryAttribute::BOLD, A_BOLD},
						{frontend::GameMapEntryAttribute::REVERSE, A_REVERSE},
						{frontend::GameMapEntryAttribute::NORMAL, A_NORMAL}
				};

		}

		short CursesColorMap::get_curses_color(const frontend::GameMapEntryColor& gmc){
				return color_map[gmc];
		}

		short CursesColorMap::get_curses_attribute(const frontend::GameMapEntryAttribute& gma){
				return attribute_map[gma];
		}

}
