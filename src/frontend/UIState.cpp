#include "frontend/UIState.hpp"

namespace frontend{
	UIState::UIState(const GameMap& gameMap){
		this->gameMap = &gameMap;
	}
	UIState::~UIState(){
			//delete remaining messages
			for(std::vector<const all::GameMessage*>::iterator it =game_messages.begin() ; it != game_messages.end(); it++){
					delete (*it);
			}
	}
}
