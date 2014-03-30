#include "frontend/GameMessageContainer.hpp"

namespace frontend{

		GameMessageContainer::GameMessageContainer():UIComponent(){
			needsRedraw=true;
		}
		
		GameMessageContainer::~GameMessageContainer(){
				//delete remaining messages
				for(auto &p : game_messages){
						delete (p);
				}
		}

}
