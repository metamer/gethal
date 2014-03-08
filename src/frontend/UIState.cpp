#include "frontend/UIState.hpp"

namespace frontend{
	UIState::UIState(const GameMap& gameMap){
		this->gameMap = &gameMap;
	}
}
