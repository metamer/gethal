#ifndef FRONTEND_INPUTMAPPER_HPP
#define FRONTEND_INPUTMAPPER_HPP

#include <map>
#include "frontend/UIAction.hpp"
#include "all/GameAction.hpp"

namespace frontend{
		class InputMapper {

			public:
				InputMapper();
				void clear_mappings();
				std::map<char,all::GameAction> game_action_map;
				std::map<char,frontend::UIAction> ui_action_map;


		};


}
#endif
