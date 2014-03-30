
#include "frontend/GameStatusEntryContainer.hpp"

namespace frontend{

		GameStatusEntryContainer::GameStatusEntryContainer():UIComponent(){
			needsRedraw=true;
		}
		
		GameStatusEntryContainer::~GameStatusEntryContainer(){
				//delete remaining messages
				for(auto &ptr : status_entries){
						delete (ptr);
				}
		}

}
