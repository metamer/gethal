#include "frontend/UIState.hpp"

namespace frontend{
	UIState::UIState(const GameMap& gameMap, std::string current_message){
		this->gameMap = &gameMap;
		this->current_message.game_messages.push_back(new all::GameMessage(current_message));
	}
}
