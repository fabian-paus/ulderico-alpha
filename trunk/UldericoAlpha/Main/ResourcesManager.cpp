#include "ResourcesManager.h"

static const char* const CHARACTERS_IMAGE = "res/img/characters.png";
static const char* const BACKGROUND_IMAGE = "res/img/invaders.png";

static const char* const SPACE_INVADERS_SOUND = "res/sound/spaceinvaders1.ogg";

static const char* const EXPLOSION_SOUND = "res/sound/explosion.wav";

ResourcesManager::ResourcesManager()
{
	// Load all images into sprites and make them accessable by name
	if(!m_background.LoadFromFile(BACKGROUND_IMAGE) || !m_character.LoadFromFile(CHARACTERS_IMAGE))
		return;

	LoadImages();

	LoadSounds();
}

void ResourcesManager::RegisterSprite(std::string const & name, sf::Sprite resource)
{
	m_spriteResources.insert(std::make_pair(name, resource));
}

void ResourcesManager::RegisterSound(std::string const & name, sf::Sound resource)
{
	m_soundResources.insert(std::make_pair(name, resource));
}

const sf::Sprite& ResourcesManager::GetSprite(std::string const & name)
{
	return m_spriteResources[name];
}

const sf::Sound& ResourcesManager::GetSound(std::string const & name)
{
	return m_soundResources[name];
}

void ResourcesManager::LoadImages()
{
	RegisterSprite("background", sf::Sprite(m_background));

	sf::Sprite invaders = sf::Sprite(m_character);

	//Load first invader(green)	
	sf::IntRect inv1Rec(0, 0, 82, 86);
	invaders.SetTextureRect(inv1Rec);
	RegisterSprite("invader1", invaders);

	//Load second invader(blue)
	sf::IntRect inv2Rec(112, 0, 116, 86);
	invaders.SetTextureRect(inv2Rec);
	RegisterSprite("invader2", invaders);

	//Load third invader(purple)	
	sf::IntRect inv3Rec(250, 0, 122, 86);
	invaders.SetTextureRect(inv3Rec);
	RegisterSprite("invader3", invaders);

	//Load me(red)
	sf::IntRect meRec(31, 303, 117, 70);
	invaders.SetTextureRect(meRec);
	RegisterSprite("me", invaders);

	//Load attack(green)
	sf::IntRect att1Rec(22, 122, 30, 60);
	invaders.SetTextureRect(att1Rec);
	RegisterSprite("attack1", invaders);

	//Load attack(blue)
	sf::IntRect att2Rec(152, 122, 28, 50);
	invaders.SetTextureRect(att2Rec);
	RegisterSprite("attack2", invaders);

	//Load attack(purble)
	sf::IntRect att3Rec(290, 122, 28, 50);
	invaders.SetTextureRect(att3Rec);
	RegisterSprite("attack3", invaders);

	//Load attack(red)
	sf::IntRect attMeRec(84, 222, 13, 45);
	invaders.SetTextureRect(attMeRec);
	RegisterSprite("attackMe", invaders);
}

void ResourcesManager::LoadSounds()
{
	m_spaceInvaders.LoadFromFile(SPACE_INVADERS_SOUND);

	RegisterSound("main-theme", sf::Sound(m_spaceInvaders));
}