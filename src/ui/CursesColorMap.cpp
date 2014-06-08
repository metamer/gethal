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
				type_color_map = {
						{all::GameMessageType::SYSTEM, COLOR_YELLOW},
						{all::GameMessageType::GOOD, COLOR_GREEN},
						{all::GameMessageType::BAD, COLOR_RED},
						{all::GameMessageType::NEUTRAL, COLOR_WHITE},
						{all::GameMessageType::BETTER, COLOR_GREEN},
						{all::GameMessageType::WORSE, COLOR_RED},
						{all::GameMessageType::BEST, COLOR_GREEN},
						{all::GameMessageType::WORST, COLOR_RED}
				};
		}

		short CursesColorMap::get_curses_color(const frontend::GameMapEntryColor& gmc){
				return color_map[gmc];
		}

		short CursesColorMap::get_curses_attribute(const frontend::GameMapEntryAttribute& gma){
				return attribute_map[gma];
		}
		short CursesColorMap::get_curses_color_for_message_type(const all::GameMessageType& gmt){
				return type_color_map[gmt];
		}

}
