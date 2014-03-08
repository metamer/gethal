/*
 *
 * Author:insidiousnoxious
 *
 */

#ifndef UI_UI_HPP
#define UI_UI_HPP

#include "frontend/UIState.hpp"

namespace ui{
		class UI{
				public:
						virtual void set_uiState(const frontend::UIState uiState&) =0;
						virtual void draw_uiState() =0;
						virtual void init() =0;
				protected:
						const frontend::UIState& uiState;
		};
}
#endif
