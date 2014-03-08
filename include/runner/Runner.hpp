/*
 *
 * Author:insidiousnoxious
 *
*/

#ifndef RUNNER_RUNNER_HPP
#define RUNNER_RUNNER_HPP

#include "ui/UI.hpp"

namespace runner{
	class Runner{
			public:
					virtual void run_game() = 0;
			private:
					ui::UI& ui;
					
	}
}
#endif
