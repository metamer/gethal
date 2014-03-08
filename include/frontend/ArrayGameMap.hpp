/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef FRONTEND_ARRAYGAMEMAP_HPP
#define FRONTEND_ARRAYGAMEMAP_HPP

#include <vector>
#include "frontend/GameMap.hpp" 
#include "frontend/GameMapEntry.hpp" 
#include "all/Exception.hpp" 

namespace frontend{
		class ArrayGameMap : public GameMap{
				public:
						ArrayGameMap(int width, int height, const GameMapEntry& defaultGme);
				private:
						const GameMapEntry& defaultGme;
						std::vector < std::vector <GameMapEntry&> > map;
						bool check_bounds(int row, int col);
		}
}
#endif
