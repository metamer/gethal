/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_GAMEMAP_HPP
#define FRONTEND_GAMEMAP_HPP

#include "frontend/GameMapEntry.hpp"

namespace frontend{
		class gamemap{
				public:
					virtual void set_entry(int row, int col, const GameMapEntry& gm ); 
					virtual const GameMapEntry& get_entry(int row, int col); 
				protected:
					int width, height;
						
		}
}
#endif
