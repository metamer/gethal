#include "ui/UI.hpp"
#include "ui/SimpleUI.hpp"
#include "runner/Runner.hpp"
#include "runner/SimpleRunner.hpp"
#include "frontend/UIState.hpp"

int main(){
	ui::SimpleUI sui = ui::SimpleUI() ;
	runner::SimpleRunner sr = runner::SimpleRunner(sui);

	sr.run_game();
}
