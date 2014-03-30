#include "frontend/GameStatusEntry.hpp"

namespace frontend{
		GameStatusEntry::GameStatusEntry(std::string name, std::string abbrev, GameStatusType status_type){
				this->name=name;
				this->abbrev=abbrev;
				this->status_type=status_type;
		}

		bool GameStatusEntry::is_numeric() const{
			return false;
		}

		bool GameStatusEntry::has_maximum() const{
			return false;
		}

		int GameStatusEntry::current_value() const{
			return 0;
		}

		int GameStatusEntry::maximum_value() const{
			return 0;
		}

		GameStatusEntry::~GameStatusEntry(){
		}
}
