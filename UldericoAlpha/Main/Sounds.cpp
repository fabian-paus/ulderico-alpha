#include "Sounds.h"

#include <cassert>

namespace UldericoAlpha
{
	std::string GetSoundFile(Sounds sound)
	{
		switch (sound)
		{
		case Sound_MainTheme:    return "res/sound/spaceinvaders1.ogg";
		case Sound_Shoot:        return "res/sound/shoot.wav";
		case Sound_Killed:       return "res/sound/invaderkilled.wav";
		case Sound_Explosion:    return "res/sound/explosion.wav";
		case Sound_UfoLowPitch:  return "res/sound/ufo_lowpitch.wav";
		case Sound_UfoHighPitch: return "res/sound/ufo_highpitch.wav";

		default:
			assert(false);
			return "";
		}
	}
}
