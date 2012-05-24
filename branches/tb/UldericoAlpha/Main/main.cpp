#include "Game.h"

using namespace UldericoAlpha::Core;

int main()
{	
	//instantiate game class
	Game uldericoAlpha;
   
	//load the resources
	uldericoAlpha.Load();

	//start game loop
	uldericoAlpha.StartGameLoop();

	return EXIT_SUCCESS;
}