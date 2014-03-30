#include "frontend/GameNumericStatusEntry.hpp"

namespace frontend{
		GameNumericStatusEntry::GameNumericStatusEntry(std::string name, std::string abbrev, GameStatusType status_type,int cur_val,bool has_max, int max_val)
				: GameStatusEntry(name, abbrev, status_type){
					this->cur_val=cur_val;
					this->max_val=max_val;
					this->has_max=has_max;
		}

		bool GameNumericStatusEntry::is_numeric() const{
				return true;
		}

		bool GameNumericStatusEntry::has_maximum() const{
				return has_max;
		}

		int GameNumericStatusEntry::current_value() const{
				return cur_val;
		}

		int GameNumericStatusEntry::maximum_value() const{
				return max_val;
		}


}
