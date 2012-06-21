#include "HighscoreEntry.h"

namespace UldericoAlpha
{
	HighscoreEntry::HighscoreEntry(const std::string& NameInput, int ScoreInput)
		: Name(NameInput), Score(ScoreInput)	
	{
	}

	void HighscoreEntry::SetName(const std::string& Input)
	{
		Name = Input;
	}
}