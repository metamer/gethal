/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef FRONTEND_GAMESTATUSENTRYCONTAINER_HPP
#define FRONTEND_GAMESTATUSENTRYCONTAINER_HPP

#include <vector>
#include "frontend/GameStatusEntry.hpp"
#include "frontend/UIComponent.hpp"

namespace frontend{

	class GameStatusEntryContainer:public UIComponent{
			public:
				GameStatusEntryContainer();
				std::vector<const GameStatusEntry*> status_entries;
				~GameStatusEntryContainer();
	};

}
#endif
