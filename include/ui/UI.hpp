/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_UI_HPP
#define UI_UI_HPP

#include "frontend/UIState.hpp"
#include "all/GameAction.hpp"

namespace ui{
		class UI{
				public:
						virtual void set_uiState(const frontend::UIState& uiState) =0;
						virtual void draw_uiState() =0;
						virtual void init() =0;
						virtual void finish() =0;
						virtual all::GameAction process_input() =0;
						const frontend::UIState* uiState ;
						virtual ~UI(){}
		};
}
#endif
