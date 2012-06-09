#ifndef ULDERICO_ALPHA_SOUNDS_H_INCLUDED
#define ULDERICO_ALPHA_SOUNDS_H_INCLUDED

#include <string>

namespace UldericoAlpha
{
	/**
	 * Aufzählung der im Spiel verwendeten Sounds.
	 */
	enum Sounds
	{
		Sounds_Begin,

		Sound_MainTheme = Sounds_Begin,
		Sound_Shoot,
		Sound_Killed,
		Sound_Explosion,
		Sound_UfoLowPitch,
		Sound_UfoHighPitch,

		Sounds_Count
	};

	/**
	 * Gibt den Speicherort des Sounds an.
	 */
	std::string GetSoundFile(Sounds sound);
}

#endif // ULDERICO_ALPHA_SOUNDS_H_INCLUDED