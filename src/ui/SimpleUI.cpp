#include "ui/UI.hpp"

namespace ui{
		void UI::set_uiState(const uiState&){
			this.uiState = uiState;
		}

		void UI::draw_uiState(){

			const frontend::GameMap& gm  = uiState->gameMap;
			
			if(gm.needsRedraw){

					int maxRows = gm.width;
					int maxCols = gm.height;

					for(int i = 0; i< maxRows; i++){
							for(int j = 0; j< maxRows; j++){
								char c = gm.get_entry(i,j).symbol;
								std::cout<<c;
							}
							std::cout<<std::endl;
					}
			}

		}

		void UI::init(){
		}

}
