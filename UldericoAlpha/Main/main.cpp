#include "Game.h"
#include <boost\signals2.hpp>

#include <iostream>

int main()
{	
   sf::RenderWindow window(sf::VideoMode(775, 572), "SFML window");

   //main event signals
   boost::signals2::signal<void (sf::Event event)> onKeyDown;
   boost::signals2::signal<void (sf::Event event)> onMouseButtonPressed;

   //instantiate game class
	Game uldericoAlpha;
   onKeyDown.connect(boost::bind(&Game::OnKeyDown, &uldericoAlpha));
   onMouseButtonPressed.connect(boost::bind(&Game::OnMouseButtonPressed, &uldericoAlpha));
      
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

			if(event.Type == sf::Event::KeyPressed)
			{
            onKeyDown(event);
				//if (event.Key.Code == sf::Keyboard::Space)
				//	shoot.Play();
				//if(event.Key.Control && event.Key.Code == 15)
				//	uldericoAlpha.Pause();

			}
         if(event.Type == sf::Event::MouseButtonPressed)
         {
            onMouseButtonPressed(event);
            //if(event.MouseButton.X >= 250 && event.MouseButton.X <= 450 && event.MouseButton.Y >= 300 && event.MouseButton.Y <= 350)
            //{
            //   uldericoAlpha.Start();
            //}
         }
		}

		// Clear screen
		window.Clear();

      //Update the game
		uldericoAlpha.Update();

		// Update the window
		window.Display();
	}

	return EXIT_SUCCESS;
}