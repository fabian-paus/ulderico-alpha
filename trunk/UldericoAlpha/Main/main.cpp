#include "ResourcesManager.h"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	
	ResourcesManager rm;

	// Start the game loop
	while (window.IsOpen())
	{


		// Process events
		sf::Event event;
		while (window.PollEvent(event))
		{
			// Close window : exit
			if (event.Type == sf::Event::Closed)
				window.Close();
		}

		// Clear screen
		window.Clear();

		//draw background
		window.Draw(rm.GetSprite("background"));

		// Update the window
		window.Display();
	}

	return EXIT_SUCCESS;
}