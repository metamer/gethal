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
				uis.status_entries.status_entries.push_back(new frontend::GameNumericStatusEntry("Hit Points","HP", frontend::STATUS, 50, true, 50));
				uis.status_entries.status_entries.push_back(new frontend::GameNumericStatusEntry("Mana Points","MP", frontend::STATUS, 47, true, 150));
				uis.status_entries.status_entries.push_back(new frontend::GameNumericStatusEntry("Stamina Points","SP", frontend::STATUS, 1090, true, 2000));
				uis.status_entries.status_entries.push_back(new frontend::GameNumericStatusEntry("Level","LV", frontend::ATTRIBUTE, 76));

				do{
						ui->draw_uiState();
				}
				while(ui->process_input());

		}
}
