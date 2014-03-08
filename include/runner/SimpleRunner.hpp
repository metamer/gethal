/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef RUNNER_SIMPLERUNNER_HPP
#define RUNNER_SIMPLERUNNER_HPP

#include "runner/Runner.hpp"
#include "frontend/GameMapEntry.hpp"
#include "frontend/UIState.hpp"
#include "ui/UI.hpp"

namespace runner{
	class SimpleRunner : Runner{
		public:
				virtual void run_game();
				SimpleRunner(ui::UI& ui);	
	};

}
#endif
