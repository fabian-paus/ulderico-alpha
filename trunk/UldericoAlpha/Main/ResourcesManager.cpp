#include "ResourcesManager.h"


ResourcesManager::ResourcesManager(void)
{
	//Load all images into sprites and make them accessable by name
	sf::Texture bg;
	sf::Texture character;
	if(!bg.LoadFromFile(background) || !character.LoadFromFile(characters))
		return;
	sf::Sprite *back = new sf::Sprite(bg);
	this->Register("background", back);
}


ResourcesManager::~ResourcesManager(void)
{
}

void ResourcesManager::Free( std::string const & name )
{
	this->UnRegister(name);
}