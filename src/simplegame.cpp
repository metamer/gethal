#include "ui/SimpleUI.hpp"
#include "runner/SimpleRunner.hpp"

int main(){
	std::cout<<"test start"<<std::endl;
	ui::SimpleUI sui = ui::SimpleUI() ;
	runner::SimpleRunner sr(sui);

	sr.run_game();

	std::cout<<"test complete"<<std::endl;
}
