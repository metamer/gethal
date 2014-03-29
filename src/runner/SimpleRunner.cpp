#include "runner/SimpleRunner.hpp"

namespace runner{

		SimpleRunner::SimpleRunner(ui::UI& ui){
				this->ui = &ui;
		}

		void SimpleRunner::run_game(){
				frontend::GameMapEntry def = frontend::GameMapEntry();
				def.symbol='.';
				const frontend::GameMap& gm = frontend::ArrayGameMap(24,36, def);
				frontend::UIState uis = frontend::UIState(gm, "You are unmanifest");
				ui->set_uiState(uis);
				uis.message_list.game_messages.push_back(new all::GameMessage("Welcome to gethal",all::SYSTEM));
				uis.current_hint.game_messages.push_back(new all::GameMessage("Press q to quit",all::SYSTEM));

				do{
						ui->draw_uiState();
				}
				while(ui->process_input());

		}
}
