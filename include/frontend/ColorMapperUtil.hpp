/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef FRONTEND_COLORMAPPERUTIL_HPP
#define FRONTEND_COLORMAPPERUTIL_HPP

#include <map>
#include "frontend/GameMapEntryColor.hpp"
#include "frontend/ColoredTextObject.hpp"
#include "all/GameMessageType.hpp"

namespace frontend{

class ColorMapperUtil{
	public:
			ColorMapperUtil();
			ColoredTextObject get_color_object_for_message_type(const all::GameMessageType& gmt);
	private:
			
			std::map<const all::GameMessageType, ColoredTextObject> type_color_map;

};

}
#endif
