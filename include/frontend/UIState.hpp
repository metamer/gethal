/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_UISTATE_HPP
#define FRONTEND_UISTATE_HPP

#include "frontend/GameMap.hpp"
#include "frontend/GameMessageContainer.hpp"
#include "frontend/GameStatusEntryContainer.hpp"
#include "all/GameMessage.hpp"
#include <vector>
#include <iostream>

namespace frontend{
		class UIState{
				private:
				public:
					const GameMap* gameMap;
					GameMessageContainer message_list;
					GameMessageContainer current_message;
					GameMessageContainer current_hint;
					GameStatusEntryContainer status_entries;
					UIState(const GameMap& gameMap, std::string current_message);
		};
}
#endif
