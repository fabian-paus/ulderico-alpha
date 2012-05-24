#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ResourcesManager.h"
#include "Level.h"
#include "Player.h"
#include "Bullet.h"
#include "BoundaryBox.h"

namespace UldericoAlpha
{
	namespace Core
	{
		class Game
		{
		public:
			Game();
			~Game(void);
			void Load();
			void StartGameLoop();
			enum GameState 
			{
				loading,
				started,
				playing,
				paused,
				gameOver
			};
		private:
			Level *levels;
			int activLevel;
			GameState state;
			Bullet *bullets;
			Player player;
			Helper::ResourcesManager rm;
			BoundaryBox bb;
			void draw();
			void start();
			void pause();
			void update();
			sf::RenderWindow window;
		};
	}
}
#endif