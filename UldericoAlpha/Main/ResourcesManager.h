#ifndef RESOURCESMANAGER_H_INCLUDED
#define RESOURCESMANAGER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <string>



class ResourcesManager
{
	typedef std::map <std::string, sf::Sprite> SpriteResourceMap;
	typedef std::map <std::string, sf::Sound> SoundResourceMap;

private:
	SpriteResourceMap spriteResources;
	SoundResourceMap soundResources;
	void RegisterSprite(std::string const & name, sf::Sprite resource );
	void RegisterSound(std::string const & name, sf::Sound resource );
public:
	ResourcesManager();
	const sf::Sprite& GetSprite(std::string const & name);
	const sf::Sound& GetSound(std::string const & name);
};

#endif