#include "runner/SimpleRunner.hpp"

namespace runner{

	SimpleRunner::SimpleRunner(ui::UI& ui){
		this->ui = &ui;
	}

	void SimpleRunner::run_game(){
	    frontend::GameMapEntry def = frontend::GameMapEntry();
		const frontend::GameMap& gm = frontend::ArrayGameMap(10,10, def);
		frontend::UIState uis = frontend::UIState(gm);
		(*ui).set_uiState(uis);
		(*ui).draw_uiState();
	}
}
