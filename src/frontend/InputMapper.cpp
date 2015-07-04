/*
 * InputMapper.cpp
 *
 *  Created on: Jul 4, 2015
 *      Author: vk
 */
#include "frontend/InputMapper.hpp"

namespace frontend{
	InputMapper::InputMapper(){
	};

	void InputMapper::clear_mappings(){
		game_action_map.clear();
		ui_action_map.clear();
	};
}



