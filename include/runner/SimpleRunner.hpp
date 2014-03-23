/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef RUNNER_SIMPLERUNNER_HPP
#define RUNNER_SIMPLERUNNER_HPP

#include "runner/Runner.hpp"
#include "frontend/ArrayGameMap.hpp"
#include "frontend/GameMapEntry.hpp"
#include "frontend/UIState.hpp"
#include "all/GameMessage.hpp"
#include "all/GameMessageType.hpp"

namespace runner{
	class SimpleRunner : public Runner{
		public:
				virtual void run_game();
				SimpleRunner(ui::UI& ui);	
	};

}
#endif
