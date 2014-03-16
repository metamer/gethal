#include "runner/SimpleRunner.hpp"

namespace runner{

	SimpleRunner::SimpleRunner(ui::UI& ui){
		this->ui = &ui;
	}

	void SimpleRunner::run_game(){
	    frontend::GameMapEntry def = frontend::GameMapEntry();
		def.symbol='.';
		const frontend::GameMap& gm = frontend::ArrayGameMap(12,18, def);
		frontend::UIState uis = frontend::UIState(gm);
		ui->init();
		ui->set_uiState(uis);
		ui->draw_uiState();
	}
}
