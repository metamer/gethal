#include "frontend/ArrayGameMap.hpp"

namespace frontend{
	ArrayGameMap::ArrayGameMap(int width, int height, const GameMapEntry& defaultGme){
		this->needsRedraw=true;
		this->width=width;
		this->height=height;
		this->map= std::vector< std::vector <const GameMapEntry*> >(width);

		for(int i = 0 ; i< width ; i++){
			std::vector<const GameMapEntry*> column(height);
			map[i]=column;
		}

		//instantiate gamemapentries
		for(int i = 0; i<width; i++){
			for(int j = 0; j<height; j++){
				GameMapEntry* gme_p = new GameMapEntry(defaultGme);
				set_entry(i,j,*gme_p);
			}
		}


		this->defaultGme = &defaultGme;
	}

	ArrayGameMap::~ArrayGameMap(){
		//delete gamemapentries that were created upon construction
		for(int i = 0; i<width; i++){
			for(int j = 0; j<height; j++){
				delete (map[i][j]);
			}
		}
	}

	void ArrayGameMap::set_entry(int row, int col, const GameMapEntry& gm){
		if(!check_bounds(row,col)){
			throw all::FrontendException();
		}
		this->map[row][col] =  &gm;
	}


	const GameMapEntry& ArrayGameMap::get_entry(int row, int col) const{ 
		if(!check_bounds(row,col)){
			throw all::FrontendException();
		}
		return *(map[row][col]);
	}
	
	bool ArrayGameMap::check_bounds(int row, int col) const{
			return (height >= row  || width >= col);
	}
}
