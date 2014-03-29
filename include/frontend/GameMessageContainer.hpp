/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef FRONTEND_GAMEMESSAGECONTAINER_HPP
#define FRONTEND_GAMEMESSAGECONTAINER_HPP

#include <vector>
#include "all/GameMessage.hpp"
#include "frontend/UIComponent.hpp"

namespace frontend{
	class GameMessageContainer : public UIComponent{
			public:
					std::vector<const all::GameMessage*> game_messages;
					GameMessageContainer();
					~GameMessageContainer();
	};

}
#endif
