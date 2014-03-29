#include "ui/CursesUI.hpp"

namespace ui{

		int CursesUI::HEADER_ROW_OFFSET=2;
		int CursesUI::HEADER_COLUMN_OFFSET=2;
		int CursesUI::MESSAGE_LIMIT=5;
		int CursesUI::MESSAGE_MAP_COLUMN_OFFSET=7;

		CursesUI::CursesUI(){
		}

		void CursesUI::set_uiState(const frontend::UIState& uiState){
				this->uiState = &uiState;
		}

		void CursesUI::draw_uiState(){

				const frontend::GameMap* gm  = uiState->gameMap;
				int maxRows = gm->width;
				int maxCols = gm->height;

				if(gm->needsRedraw){


						for(int i = 0; i< maxRows; i++){
								for(int j = 0; j< maxCols; j++){
										move(i+HEADER_ROW_OFFSET,j+HEADER_COLUMN_OFFSET);
										const char c = gm->get_entry(i,j).symbol;
										addch(c);
								}
						}
				}

				std::vector<const all::GameMessage*> msg_vec= uiState->message_list.game_messages;

				int messages_added=0;

				for(std::vector<const all::GameMessage*>::iterator it =msg_vec.begin() ; it != msg_vec.end() && messages_added <=MESSAGE_LIMIT ; it++){
						move(messages_added+HEADER_ROW_OFFSET+messages_added,maxCols+HEADER_COLUMN_OFFSET+MESSAGE_MAP_COLUMN_OFFSET);
						addstr((**it).message_text.c_str());
						messages_added++;
				}
				refresh();
		}
		bool CursesUI::process_input(){
				bool should_continue = true;
				int ch = getch();
				switch (ch){

						case 'w':
								printw("You have won!\n");
								should_continue = false;
								break;

						default:
								break;
				}

				return should_continue;

		}


		void CursesUI::init(){

				p_window = initscr();
				clear();
				cbreak();
				noecho();
				refresh();

				mvaddstr(0, 25 ,"Welcome to gethal!");
				mvaddstr(23, 15 ,"Press 'w' to win.");

				refresh();

		}

		void  CursesUI::finish(){
				endwin();
		}
}
