#include "frontend/GameMapEntry.hpp"

namespace frontend{

		GameMapEntry::GameMapEntry(){
			symbol=' ';
		}

		GameMapEntry::GameMapEntry(char symbol='x', GameMapEntryColor color_fg = WHITE, GameMapEntryColor color_bg = BLACK, GameMapEntryAttribute attribute = NORMAL){
				this->symbol = symbol;
				this->color_fg = color_fg;
				this->color_bg = color_bg;
				this->attribute = attribute;
		}
}
