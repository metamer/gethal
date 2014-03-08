/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_UISTATE_HPP
#define FRONTEND_UISTATE_HPP

#include "frontend/GameMap.hpp"


namespace frontend{
		class UIState{
				private:
				public:
					const GameMap& gameMap;
					UIState(const GameMap& gameMap);
						
		}
}
#endif
