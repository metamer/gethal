#include "frontend/ColoredString.hpp"
namespace frontend{
		ColoredString::ColoredString(const std::string& str, GameMapEntryColor color_fg, GameMapEntryColor color_bg, GameMapEntryAttribute attribute){
			this->str = std::string(str);
			this->color_fg = color_fg;
			this->color_bg = color_bg;
			this->attribute = attribute;
		}
}
