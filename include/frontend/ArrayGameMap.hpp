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
						virtual void set_entry(int row, int col, const GameMapEntry& gm ); 
						virtual const GameMapEntry& get_entry(int row, int col) const; 
						ArrayGameMap(int width, int height, const GameMapEntry& defaultGme);
						virtual ~ArrayGameMap();
				private:
						const GameMapEntry* defaultGme;
						std::vector < std::vector <const GameMapEntry*> > map;
						bool check_bounds(int row, int col) const;
		};
}
#endif
