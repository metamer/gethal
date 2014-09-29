#include "ui/NotEyeUI.hpp"
using namespace noteye;

namespace ui{

		int NotEyeUI::HEADER_ROW_OFFSET=2;
		int NotEyeUI::HEADER_COLUMN_OFFSET=2;
		int NotEyeUI::MESSAGE_LIMIT=5;
		int NotEyeUI::MESSAGE_MAP_COLUMN_OFFSET=7;

		NotEyeUI::NotEyeUI(std::string noteye_dir,std::string noteye_user_dir):UI(){
				this->noteye_dir=noteye_dir;
				this->noteye_user_dir=noteye_user_dir;
		}

		void NotEyeUI::set_uiState(const frontend::UIState& uiState){
				this->uiState = &uiState;
		}

		void NotEyeUI::draw_uiState(){

				const frontend::GameMap* gm  = uiState->gameMap;
				int maxRows = gm->width;
				int maxCols = gm->height;

				if(gm->needsRedraw){


						for(int i = 0; i< maxRows; i++){
								for(int j = 0; j< maxCols; j++){
										noteye_move(i+HEADER_ROW_OFFSET,j+HEADER_COLUMN_OFFSET);
										const char c = gm->get_entry(i,j).symbol;
										noteye_addch(c);
								}
						}
				}

				std::vector<const all::GameMessage*> msg_vec= uiState->message_list.game_messages;

				int messages_added=0;

				for(std::vector<const all::GameMessage*>::iterator it =msg_vec.begin() ; it != msg_vec.end() && messages_added <=MESSAGE_LIMIT ; it++){
						noteye_move(messages_added+HEADER_ROW_OFFSET+messages_added,maxCols+HEADER_COLUMN_OFFSET+MESSAGE_MAP_COLUMN_OFFSET);
						noteye_addstr((**it).message_text.c_str());
						messages_added++;
				}
		}
		all::GameAction NotEyeUI::process_input(){
				bool should_continue = true;
				int ch = noteye_getch();
				switch (ch){

						case 'w':
								return all::GameAction::QUIT;
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

				return all::GameAction::WAIT;

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


		void NotEyeUI::finish(){
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
