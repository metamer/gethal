#include "ui/UI.hpp"
#include "ui/CursesUI.hpp"
#include "runner/Runner.hpp"
#include "runner/SimpleRunner.hpp"
#include "frontend/UIState.hpp"

int main(){
	ui::CursesUI ui = ui::CursesUI() ;
	runner::SimpleRunner sr = runner::SimpleRunner(ui);

	ui.init();

	sr.run_game();

	ui.finish();
}
