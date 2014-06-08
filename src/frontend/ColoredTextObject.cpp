#include "frontend/ColoredTextObject.hpp"

namespace frontend{
		ColoredTextObject::ColoredTextObject(){
			this->color_fg = GameMapEntryColor::WHITE;
			this->color_bg = GameMapEntryColor::BLACK;
			this->attribute = GameMapEntryAttribute::NORMAL;
		};		
		
		ColoredTextObject::ColoredTextObject(GameMapEntryColor color_fg, GameMapEntryColor color_bg, GameMapEntryAttribute attribute){
			this->color_fg = color_fg;
			this->color_bg = color_bg;
			this->attribute = attribute;
		};
}
