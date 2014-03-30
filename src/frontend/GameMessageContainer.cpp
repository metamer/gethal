#include "frontend/GameMessageContainer.hpp"

namespace frontend{

		GameMessageContainer::GameMessageContainer():UIComponent(){
			needsRedraw=true;
		}
		
		GameMessageContainer::~GameMessageContainer(){
				//delete remaining messages
				for(std::vector<const all::GameMessage*>::iterator it =game_messages.begin() ; it != game_messages.end(); it++){
						delete (*it);
				}
		}

}
