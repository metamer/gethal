#include "all/GameMessage.hpp"

namespace all{
		GameMessage::GameMessage(std::string message_text, GameMessageType message_type){
				this->message_text=message_text;
				this->message_type=message_type;
		}
}
