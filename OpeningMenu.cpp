//-----include section-----
#include "OpeningMenu.h"

#include <vector>
#include <memory>


//-----functions section------
//-----------------------------------------------------------------------------
OpeningMenu::OpeningMenu()
{
	for (int buttons = 0; buttons < START_WINDOW_BUTTONS_NUM; buttons++)
	{
		Button newButton = Button('E');

		m_menuButtons->push_back(newButton);
	}
}

