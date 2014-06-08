#include "ui/CursesUI.hpp"

namespace ui{

		CursesUI::CursesUI():UI(){

				state_set=false;
				ui_initialized=false;
				layout_calc_needed=true;

				max_x=0;
				max_y=0;

				margin_top_bot_left=1;
				margin_top_bot_right=1;
				margin_top=1;
				margin_bot=1;

				info_spacer_north=1;
				info_spacer_south=1;

				margin_left=1;
				margin_right=1;

				gamemap_spacer_east=0;
				gamemap_spacer_east=0;

				gamemap_spacer_east=1;

				info_spacer_north=1;
				info_spacer_south=1;
				info_max_width=0;
				info_max_height=0;


				hint_height=2;
				status_height=3;

				top_bottom_width=0;

				gm_h=0;
				gm_w=0;
				p_window=nullptr;
				spacer_char="\u2592";

				ccm = CursesColorMap();
				cmu = frontend::ColorMapperUtil();
		}

		bool CursesUI::recalculate_layout(){
				if(state_set && ui_initialized){

						getmaxyx(p_window, max_y, max_x);

						const frontend::GameMap* gm  = uiState->gameMap;
						gm_h = gm->width;
						gm_w = gm->height;



						gamemap_spacer_north = info_spacer_north; //(max_y - (gm_h+status_height+message_height+hint_height))/2 ;
						gamemap_spacer_south = info_spacer_south; //gamemap_spacer_north; 


						if(std::max(gamemap_spacer_north + gamemap_spacer_south + gm_h, info_spacer_north + info_spacer_south)+status_height+hint_height+margin_top+margin_bot > max_y
										|| margin_left + gm_h + gamemap_spacer_east + margin_right > max_x 
										|| margin_top_bot_left + margin_top_bot_right  > max_x
						  ){
								clear();
								mvaddstr(0,0,"Screen Too Small");
								refresh();
								return false;
						}	

						top_bottom_width = max_x - (margin_top_bot_left + margin_top_bot_right);

						//fill screen w/ spacer char
						draw_spacer(Spacer(all::Coordinate(0,0),max_x,max_y));
						message_height= max_y-(gm_h+gamemap_spacer_south + gamemap_spacer_north+status_height+hint_height+margin_top+margin_bot);

						info_max_width= max_x -( margin_left + gm_w + gamemap_spacer_east + margin_right );
						info_max_height= max_y -( status_height + message_height + hint_height + info_spacer_north + info_spacer_south + margin_top + margin_bot );

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

		void CursesUI::draw_colored_string(const frontend::ColoredString& cs){
				init_pair(1, ccm.get_curses_color(cs.color_fg), ccm.get_curses_color(cs.color_bg));
				attron(COLOR_PAIR(1));
				addstr(cs.str.c_str());
				attroff(COLOR_PAIR(1));

		}
		void CursesUI::draw_spacer(const Spacer& s){
				const all::Coordinate start_coord = s.start_coord;

				for(int i = 0; i < s.width ; i++){
						for(int j = 0 ; j < s.height ; j++){
								mvaddstr(start_coord.x + i , start_coord.y + j , spacer_char.c_str());
						}
				}
		}

		void CursesUI::draw_uiState(){

				if(layout_calc_needed ){
						if(!recalculate_layout()){
								return;
						}
				}


				draw_game_map(all::Coordinate(margin_top+status_height+gamemap_spacer_north,margin_left));


				drawStatusEntryContainer(uiState->status_entries, all::Coordinate(margin_top, margin_top_bot_left), status_height, top_bottom_width);
				drawMessageContainer(uiState->current_message, all::Coordinate(margin_top+status_height+info_spacer_north, margin_left+gm_w+gamemap_spacer_east), info_max_height, info_max_width);
				drawMessageContainer(uiState->message_list, all::Coordinate(margin_top+status_height+gamemap_spacer_north+gm_h+gamemap_spacer_south, margin_top_bot_left), message_height, top_bottom_width);
				drawMessageContainer(uiState->current_hint, all::Coordinate(margin_top+status_height+gamemap_spacer_north+gm_h+gamemap_spacer_south+message_height, margin_top_bot_left), hint_height, top_bottom_width);

				refresh();
		}


		void CursesUI::drawStatusEntryContainer(const frontend::GameStatusEntryContainer& sc, all::Coordinate c, int height, int width){

				if(sc.needsRedraw){

						clear_bounds(c,height,width);

						auto status_vec= sc.status_entries;

						auto stat_vec = decltype(status_vec)(); 
						auto attr_vec = decltype(status_vec)(); 
						auto cond_vec = decltype(status_vec)(); 

						for(auto &it : status_vec){
								std::vector<const frontend::GameStatusEntry*>* vec_to_add = nullptr;
								switch(it->status_type){
										case frontend::STATUS:
												vec_to_add = &stat_vec;
												break;
										case frontend::ATTRIBUTE:
												vec_to_add = &attr_vec;
												break;
										case frontend::CONDITION:
												vec_to_add = &cond_vec;;
												break;
										default:
												break;
								}
								if(vec_to_add != nullptr){
										vec_to_add->push_back(it);
								}
						}

						create_status_line(stat_vec,all::Coordinate(0+c.x,c.y),width);
						create_status_line(attr_vec,all::Coordinate(1+c.x,c.y),width);
						create_status_line(cond_vec,all::Coordinate(2+c.x,c.y),width);
				}
		}

		void CursesUI::create_status_line(std::vector<const frontend::GameStatusEntry*> entry_vec, all::Coordinate start_coord, int len_limit){
				move(start_coord.x, start_coord.y);
				int total_length=0;
				bool reached_limit = false;
				bool first_entry = true;

				for(auto &se : entry_vec){

						std::string add_str= get_status_entry_string(*se);

						if(first_entry){
								first_entry= false;
						}else{
								add_str = "  "+add_str;
						}

						total_length+=add_str.length();

						if(total_length >len_limit){
								reached_limit = true;
								break;
						}else{
								addstr(add_str.c_str());
								move(start_coord.x,start_coord.y+total_length);
						}
				}

				if(reached_limit && len_limit > 3){
						move(start_coord.x, start_coord.y + len_limit -1 - 3);
						addstr("...");
				}
		}

		std::string CursesUI::get_status_entry_string(const frontend::GameStatusEntry& se){
				std::string str = se.abbrev;

				if(se.is_numeric()){
						str+=':';
						str+=std::to_string(se.current_value());
						if(se.has_maximum()){
								str+="/";
								str+=std::to_string(se.maximum_value());
						}
				}
				return str;

		}

		void CursesUI::drawMessageContainer(const frontend::GameMessageContainer& mc, all::Coordinate c, int height, int width){


				if(mc.needsRedraw){

						clear_bounds(c,height,width);

						auto msg_vec= mc.game_messages;
						int lines_added=0;
						for(auto it =msg_vec.begin() ; it != msg_vec.end() && lines_added <height; it++){
								move(lines_added+c.x,c.y);
								frontend::ColoredTextObject cto = cmu.get_color_object_for_message_type((**it).message_type);
								frontend::ColoredString cs(
														(**it).message_text, 
														cto.color_fg,
														cto.color_bg,
														cto.attribute);
								this->draw_colored_string(cs);
												
								lines_added++;
						}	
				}
		}

		void CursesUI::clear_bounds(all::Coordinate c, int height, int width){
				for(int i = c.x ; i < c.x+height ; i++ ){
						for(int j = c.y ; j < c.y+width ; j++ ){
								//todo: add color handling
								mvaddstr(i,j," ");
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

				setlocale(LC_ALL,"");
				p_window = initscr();
				if(has_colors() == FALSE){
						endwin();
						printf("Your terminal does not support color");
						exit(1);
				}else{
						start_color();
				}

				clear();
				cbreak();
				noecho();
				nonl();
				nonl();
				intrflush(stdscr, FALSE);
				keypad(stdscr, TRUE);


				curs_set(0);
				refresh();

				ui_initialized=true;

				if(layout_calc_needed){
						recalculate_layout();
				}

				refresh();

		}

		void  CursesUI::finish(){
				clear();
				endwin();
		}
}
