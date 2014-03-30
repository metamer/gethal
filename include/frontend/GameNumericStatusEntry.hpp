/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_GAMENUMERICSTATUSENTRY_HPP
#define FRONTEND_GAMENUMERICSTATUSENTRY_HPP

#include "frontend/GameStatusEntry.hpp"

namespace frontend{
		class GameNumericStatusEntry: public GameStatusEntry{
				public:
						GameNumericStatusEntry(std::string name, std::string abbrev, GameStatusType status_type,int cur_val,bool has_max=false,int max_val=0);
						int cur_val, max_val;
						bool has_max;
						bool is_numeric() const;
						bool has_maximum() const;
						int current_value() const;
						int maximum_value() const;
		};

}
#endif
