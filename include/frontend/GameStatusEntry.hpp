/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef FRONTEND_GAMESTATUSENTRY_HPP
#define FRONTEND_GAMESTATUSENTRY_HPP

#include <string>
#include "frontend/GameStatusType.hpp"

namespace frontend{
		class GameStatusEntry{
				public:
						GameStatusEntry(std::string name, std::string abbrev, GameStatusType status_type);
						std::string name;
						std::string abbrev;
						GameStatusType status_type;
						virtual ~GameStatusEntry();
						virtual bool is_numeric() const;
						virtual bool has_maximum() const;
						virtual int current_value() const;
						virtual int maximum_value() const;
		};

}
#endif
