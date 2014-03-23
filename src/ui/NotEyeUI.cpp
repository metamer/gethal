#include "ui/NotEyeUI.hpp"
using namespace noteye;

namespace ui{

		NotEyeUI::NotEyeUI(std::string noteye_dir,std::string noteye_user_dir){
				this->noteye_dir=noteye_dir;
				this->noteye_user_dir=noteye_user_dir;
		}

		void NotEyeUI::set_uiState(const frontend::UIState& uiState){
				this->uiState = &uiState;
		}

		void NotEyeUI::draw_uiState(){

				const frontend::GameMap* gm  = uiState->gameMap;

				if(gm->needsRedraw){

						int maxRows = gm->width;
						int maxCols = gm->height;

						for(int i = 0; i< maxRows; i++){
								for(int j = 0; j< maxCols; j++){
										noteye_move(i,j);
										const char c = gm->get_entry(i,j).symbol;
										noteye_addch(c);
								}
						}
				}
		}
		bool NotEyeUI::process_input(){
				bool should_continue = true;
				int ch = noteye_getch();
				switch (ch){

						case 'w':
								printf("You have won!\n");
								should_continue = false;
								break;

						case  NOTEYEERR:

								// in some cases, noteye_getch() will return NOTEYEERR
								// after the script causes an error.
								// Restart NotEye is the only thing we can do then

								printf("NotEye error detected, restarting NotEye\n");

								restart();

								printf("restart OK\n");

								break;
						default:
								break;
				}

				return should_continue;

		}

		void NotEyeUI::init(){
				init(false);
		}

		void NotEyeUI::init(bool for_restart){

				int argc=0;
				char** argv=0;
				noteye_args(argc,argv);  

				noteye_init();

				noteye_globalstr("noteyedir", (noteye_dir+"/").c_str());
				noteye_globalstr("userdir", (noteye_user_dir+"/").c_str());
				noteye_handleerror(errorHandler);


				noteye_run((noteye_dir+"/games/sample.noe").c_str(), true);


				if(!for_restart){

						setTextAttr(10, 0);
						noteye_move(0, 25);
						noteye_addstr("Welcome to gethal!");
						noteye_move(23, 15);
						noteye_addstr("Press Ctrl+M for NotEye options, 'w' to win.");
						noteye_move(24, 15);
						noteye_addstr("F8 causes the NotEye script to crash.");
				}else{
						draw_uiState();
				}

		}

		void  NotEyeUI::restart(){
				finish(true);
				init(true);
		}



		void  NotEyeUI::finish(){
			finish(false);
		}

		void  NotEyeUI::finish(bool for_restart){
				if(!for_restart){
						noteye_finishinternal(1);
						noteye_uifinish();
				}
				noteye_halt();
		}

		void errorHandler(int id, const char *b1, const char *b2, int param) {
				fprintf(stderr, "handling NotEye error #%d: %s", id, b1);
				if(b2) fprintf(stderr, " [%s]", b2);
				if(param != NOPARAM) fprintf(stderr, " [%d]", param);
				fprintf(stderr, "\n");
		}
}
