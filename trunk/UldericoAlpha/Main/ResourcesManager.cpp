#include "ResourcesManager.h"

static const char *characters = "\\res\\img\\characters.png";
static const char *background = "\\res\\img\\invaders.png";

ResourcesManager::ResourcesManager()
{
	//Load all images into sprites and make them accessable by name
	sf::Texture bg;
	sf::Texture character;
	if(!bg.LoadFromFile(background) || !character.LoadFromFile(characters))
		return;
	sf::Sprite back(bg);
	RegisterSprite("background", back);
}

void ResourcesManager::RegisterSprite(std::string const & name, sf::Sprite resource)
{
	spriteResources.insert(std::make_pair(name, resource));
}

//void ResourcesManager::RegisterSound(std::string const & name, sf::Sound resource)
//{
//	soundResources.insert(std::make_pair(name, resource));
//}

const sf::Sprite& ResourcesManager::GetSprite(std::string const & name)
{
	return spriteResources[name];
}

//const sf::Sound& ResourcesManager::GetSound(std::string const & name)
//{
//	return soundResources[name];
//}