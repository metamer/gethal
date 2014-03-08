#include "frontend/ArrayGameMap.hpp"

namespace frontend{
	ArrayGameMap::ArrayGameMap(int width, int height, const GameMapEntry& defaultGme){
		this->width=width;
		this->height=height;
		this->map(width,std::vector <const GameMapEntry*> (height));
		this->defaultGme = &defaultGme;
	}

	void ArrayGameMap::set_entry(int row, int col, const GameMapEntry& gm){
		if(!check_bounds(row,col)){
			throw all::FrontendException();
		}
		this->map[row][col] =  &gm;
	}


	const GameMapEntry& ArrayGameMap::get_entry(int row, int col){ 
		if(!check_bounds(row,col)){
			throw all::FrontendException();
		}
		return *(this->map[row][col]);
	}
	
	bool ArrayGameMap::check_bounds(int row, int col){
			return (height >= row  || width >= col);
	}
}
