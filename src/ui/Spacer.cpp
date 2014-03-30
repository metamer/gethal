#include "ui/Spacer.hpp"

namespace ui{
	Spacer::Spacer(const all::Coordinate& start_coord, int height, int width){
		this->start_coord= all::Coordinate(start_coord.x, start_coord.y); 
		this->height = height;
		this->width = width;
		this->needsRedraw = true;
	}
}
