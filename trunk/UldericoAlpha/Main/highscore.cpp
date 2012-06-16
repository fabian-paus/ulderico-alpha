#include "highscore.h"
#include "string.h"

namespace UldericoAlpha
{
	// Funktionen des Highscore Eintrages
	HighscoreEntry::HighscoreEntry()
	{
		SetName("");
		Score = 0;
	}
	HighscoreEntry::~HighscoreEntry()
	{
		delete[] Name;
	}	
	void HighscoreEntry::SetName(const char* Input)
	{
		HighscoreEntry::NameLength = strlen(Input);
		HighscoreEntry::Name = new char[NameLength + 1];
		strcpy(HighscoreEntry::Name, Input);
	}

	// Funktionen der Highscore Liste
	HighscoreList::HighscoreList()
	{
		for(int i = 0; i < 10; i++)
		{
			UldericoAlpha::HighscoreEntry *Entry = new UldericoAlpha::HighscoreEntry;
			UldericoAlpha::HighscoreList::Placement[i] = Entry;
		}
	}
	HighscoreList::~HighscoreList()
	{
		for(int i = 0; i < 10; i++)
		{
			delete UldericoAlpha::HighscoreList::Placement[i];
			UldericoAlpha::HighscoreList::Placement[i] = 0;
		}
	}
}