/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_UISTATE_HPP
#define FRONTEND_UISTATE_HPP

#include "frontend/GameMap.hpp"
#include "all/GameMessage.hpp"
#include <vector>

namespace frontend{
		class UIState{
				private:
				public:
					const GameMap* gameMap;
					std::vector<const all::GameMessage*> game_messages;
					UIState(const GameMap& gameMap);
						
		};
}
#endif
