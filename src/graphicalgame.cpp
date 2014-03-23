#include "ui/UI.hpp"
#include "ui/NotEyeUI.hpp"
#include "runner/Runner.hpp"
#include "runner/SimpleRunner.hpp"
#include "frontend/UIState.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){
		std::cout<<"Start Graphical Game"<<std::endl;
		std::vector<std::string> args(argv+1, argv+argc);

		std::string noteye_dir;
		std::string noteye_user_dir;
		char* noteye_dir_env=std::getenv("NOTEYE_HOME");
		char* noteye_user_dir_env=std::getenv("NOTEYE_USER_HOME");
		char* user_home_dir_env=std::getenv("HOME");

		//Set noteye config variables

		//where noteye was installed
		noteye_dir="/usr/share/noteye";
		//location of config.noe

		if(argc>1 ){
				noteye_dir=args[0];
		}else if (noteye_dir_env!=0){
				noteye_dir.assign(noteye_dir_env);	
		}

		std::cout<<"Setting noteye_dir to "<<noteye_dir<<std::endl;


		if(argc>2 ){
				noteye_user_dir=args[1];
		}else if (noteye_user_dir_env!=0){
				noteye_user_dir.assign(noteye_user_dir_env);	
		}else if (user_home_dir_env!=0){//default install location
				noteye_user_dir.assign(user_home_dir_env);
				noteye_user_dir+=("/.config/noteye");
		}else{//if user home is not set
				noteye_user_dir=noteye_dir+"/user";
		}
		std::cout<<"Setting noteye_user_dir to "<<noteye_user_dir<<std::endl;	

		ui::NotEyeUI sui = ui::NotEyeUI(noteye_dir,noteye_user_dir) ;
		sui.init();

		runner::SimpleRunner sr = runner::SimpleRunner(sui);
		sr.run_game();
		
		// tell the script that the game is finished
		sui.finish();
		std::cout<<"End Graphical Game"<<std::endl;
}
