#ifndef RESOURCESMANAGER_H_INCLUDED
#define RESOURCESMANAGER_H_INCLUDED

#include "Sprites.h"
#include "Textures.h"
#include "Sounds.h"
#include "Fonts.h"

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <string>
#include <array>

namespace UldericoAlpha
{
	/**
	 * Diese Klasse verwaltet alle Ressourcen im Spiel.
	 * 
	 * Die eigentlichen Ressourcen (Texturen, SoundBuffer und Fonts) werden dabei
	 * intern verwaltet. Über die öffentliche Schnittstelle werden nur Referenzen
	 * (Sprite, Sound, Text) auf die internen Ressourcen zur Verfügung gestellt.
	 */
	class ResourcesManager
	{
	public:
		/**
		 * Lädt alle Ressourcen.
		 */
		ResourcesManager();

		/**
		 * Gibt das angeforderte Sprite zurück.
		 */
		sf::Sprite Get(Sprites sprite) const;

		/**
		 * Gibt den angeforderten Sound zurück.
		 */
		sf::Sound Get(Sounds sound) const;

		/**
		 * Gibt den angeforderten Text mit angegebener Schriftart zurück.
		 */
		sf::Text GetText(std::string const& text, Fonts font = Font_CosmicAlien) const;

	private:
		sf::Texture const& Get(Textures texture) const;
		
		sf::Font const& Get(Fonts font) const;

		void LoadTextures();

		void LoadFonts();

		void LoadSprites();

		void LoadSounds();

	private:
		std::array<sf::Texture, Textures_Count> m_textures;
		std::array<sf::Sprite, Sprites_Count> m_sprites;
		std::array<sf::SoundBuffer, Sounds_Count> m_soundBuffers;
		std::array<sf::Font, Fonts_Count> m_fonts;
	};
}
#endif