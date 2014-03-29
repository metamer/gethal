#include "ui/CursesUI.hpp"

namespace ui{

		CursesUI::CursesUI(){

				state_set=false;
				ui_initialized=false;
				margin_top_bot_left=1;
				margin_top_bot_right=1;

				info_spacer_north=1;
				info_spacer_south=1;

				margin_left=1;
				margin_right=1;
				gamemap_spacer_east=1;

				message_height=3;
				hint_height=2;
				status_height=3;

				max_x=0;
				max_y=0;
		}

		bool CursesUI::recalculate_layout(){
				if(state_set && ui_initialized){

						getmaxyx(p_window, max_y, max_x);

						const frontend::GameMap* gm  = uiState->gameMap;
						gm_h = gm->width;
						gm_w = gm->height;


						if(std::max(gm_h, info_spacer_north + info_spacer_south)+status_height+message_height+hint_height > max_y
										|| margin_left + gm_h + gamemap_spacer_east + margin_right > max_x 
										|| margin_top_bot_left + margin_top_bot_right  > max_x
						  ){
								clear();
								mvaddstr(0,0,"Screen Too Small");
								refresh();
								return false;
						}

						gamemap_spacer_north = (max_y - (gm_h+status_height+message_height+hint_height))/2 ;
						gamemap_spacer_south = gamemap_spacer_north; 

						top_bottom_width = max_x - (margin_top_bot_left + margin_top_bot_right);

						info_max_width= max_x -( margin_left + gm_h + gamemap_spacer_east + margin_right );
						info_max_height= max_y -( status_height + message_height + hint_height + info_spacer_north + info_spacer_south );

						layout_calc_needed=false;
						return true;
				}
				return false;
		}

		void CursesUI::set_uiState(const frontend::UIState& uiState){
				this->uiState = &uiState;

				state_set=true;

				if(layout_calc_needed){
						recalculate_layout();
				}

		}

		void CursesUI::draw_uiState(){


				draw_game_map(all::Coordinate(status_height+gamemap_spacer_north,margin_left));


				drawMessageContainer(uiState->current_message, all::Coordinate(status_height+info_spacer_north, margin_left+gm_w+gamemap_spacer_east), info_max_height, info_max_width);
				drawMessageContainer(uiState->message_list, all::Coordinate(status_height+gamemap_spacer_north+gm_h+gamemap_spacer_south, margin_top_bot_left), message_height, top_bottom_width);
				drawMessageContainer(uiState->current_hint, all::Coordinate(status_height+gamemap_spacer_north+gm_h+gamemap_spacer_south+message_height, margin_top_bot_left), hint_height, top_bottom_width);

				refresh();
		}


		//lines_added+status_height+gamemap_spacer_north+gm_h+gamemap_spacer_south+message_height
		//margin_top_bot_left)
		void CursesUI::drawMessageContainer(const frontend::GameMessageContainer& mc, all::Coordinate c, int height, int width){

				if(mc.needsRedraw){

						auto msg_vec= mc.game_messages;
						int lines_added=0;
						for(auto it =msg_vec.begin() ; it != msg_vec.end() && lines_added <height; it++){
								move(lines_added+c.x,c.y);
								addstr((**it).message_text.c_str());
								lines_added++;
						}	
				}
		}


		void CursesUI::draw_game_map(all::Coordinate c){
				const frontend::GameMap* gm  = uiState->gameMap;
				if(gm->needsRedraw){


						int maxRows = gm->width;
						int maxCols = gm->height;

						for(int i = 0; i< maxRows; i++){
								for(int j = 0; j< maxCols; j++){
										move(i+c.x,j+c.y);
										const char c = gm->get_entry(i,j).symbol;
										addch(c);
								}
						}
				}	
		}

		bool CursesUI::process_input(){
				bool should_continue = true;
				int ch = getch();
				switch (ch){

						case 'q':
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

				ui_initialized=true;

				if(layout_calc_needed){
						recalculate_layout();
				}

				refresh();

		}

		void  CursesUI::finish(){
				endwin();
		}
}
