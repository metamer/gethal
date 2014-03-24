#include "ui/SimpleUI.hpp"

namespace ui{


		void SimpleUI::set_uiState(const frontend::UIState& uiState){
				this->uiState = &uiState;
		}

		void SimpleUI::draw_uiState(){

				std::cout<<"====Begin Redraw===="<<std::endl;
				const frontend::GameMap* gm  = uiState->gameMap;

				if(gm->needsRedraw){

						int maxRows = gm->width;
						int maxCols = gm->height;

						for(int i = 0; i< maxRows; i++){
								for(int j = 0; j< maxCols; j++){
										const char c = gm->get_entry(i,j).symbol;
										std::cout<<c;
								}
								std::cout<<std::endl;
						}

						std::cout<<"Messages:"<<std::endl;

						std::vector<const all::GameMessage*> msg_vec= uiState->message_list.game_messages, cur_msg=uiState->current_message.game_messages, cur_hint=uiState->current_hint.game_messages;
						for(std::vector<const all::GameMessage*>::iterator it =msg_vec.begin() ; it != msg_vec.end() ; it++){
								std::cout<<((**it).message_text)<<std::endl;
						}
						std::cout<<"Current Messages:"<<std::endl;
						for(std::vector<const all::GameMessage*>::iterator it =cur_msg.begin() ; it != cur_msg.end() ; it++){
								std::cout<<((**it).message_text)<<std::endl;
						}
						std::cout<<"Current Hint:"<<std::endl;
						for(std::vector<const all::GameMessage*>::iterator it =cur_hint.begin() ; it != cur_hint.end() ; it++){
								std::cout<<((**it).message_text)<<std::endl;
						}
				}
				std::cout<<"====End Redraw===="<<std::endl;
				std::cout<<"Enter Your Command:"<<std::endl;

		}

		void SimpleUI::init(){
				std::cout<<"Using Simple UI. Press q to quit."<<std::endl;
		}

		void SimpleUI::finish(){
		}

		bool SimpleUI::process_input(){
				char ch = 0;
				std::cin>>ch;
				switch (ch){
						case 'q':
								std::cout<<"Quitting"<<std::endl;
								return false;
								break;
						default:
								break;
				}
				return true;
		}

}
