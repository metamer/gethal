/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef ALL_GAMEMESSAGE_HPP
#define ALL_GAMEMESSAGE_HPP
#include <iostream>
#include "all/GameMessageType.hpp"


namespace all{

	class GameMessage{

		public:
			GameMessage(std::string message_text, GameMessageType message_type);

		private:
			std::string message_text;
			GameMessageType message_type;
			
	};

}
#endif
