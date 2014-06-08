#include "frontend/ColorMapperUtil.hpp"

namespace frontend{
		ColorMapperUtil::ColorMapperUtil(){
				type_color_map = {
						{all::GameMessageType::SYSTEM, ColoredTextObject(GameMapEntryColor::YELLOW, GameMapEntryColor::BLACK,GameMapEntryAttribute::NORMAL)},
						{all::GameMessageType::GOOD, ColoredTextObject(GameMapEntryColor::GREEN, GameMapEntryColor::BLACK,GameMapEntryAttribute::NORMAL)},
						{all::GameMessageType::BAD, ColoredTextObject(GameMapEntryColor::RED, GameMapEntryColor::BLACK,GameMapEntryAttribute::NORMAL)},
						{all::GameMessageType::NEUTRAL, ColoredTextObject(GameMapEntryColor::WHITE, GameMapEntryColor::BLACK,GameMapEntryAttribute::NORMAL)},
						{all::GameMessageType::BETTER, ColoredTextObject(GameMapEntryColor::GREEN, GameMapEntryColor::YELLOW,GameMapEntryAttribute::NORMAL)},
						{all::GameMessageType::WORSE, ColoredTextObject(GameMapEntryColor::RED, GameMapEntryColor::YELLOW,GameMapEntryAttribute::NORMAL)},
						{all::GameMessageType::BEST, ColoredTextObject(GameMapEntryColor::BLACK, GameMapEntryColor::GREEN,GameMapEntryAttribute::NORMAL)},
						{all::GameMessageType::WORST, ColoredTextObject(GameMapEntryColor::BLACK, GameMapEntryColor::RED,GameMapEntryAttribute::NORMAL)}
				};
		}

		ColoredTextObject ColorMapperUtil::get_color_object_for_message_type(const all::GameMessageType& gmt){
				return type_color_map[gmt];
		}
}
