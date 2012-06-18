#include "highscore.h"
#include "string.h"
#include <fstream>


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
	bool HighscoreList::CanInsert(int Points)
	{
		/* 
		*	Sofern Platzierung 10 eine geringere Score enthält,
		*	ist eine Einsortierung möglich
		*/

		if(Placement[9]->GetScore() < Points)
			return true;
		else
			return false;
	}
	HighscoreEntry* HighscoreList::GetEntry(int Index)
	{
		return Placement[Index-1];
	}
	void HighscoreList::SaveToFile()
	{
		std::fstream File;
		File.open("Highscore.txt", std::ios::out);

		for(int i = 0; i < 10; i++)
		{
			File << Placement[i]->GetName() << std::endl;
			File << Placement[i]->GetScore() << std::endl;
		}
		File.close();
	}
	void HighscoreList::LoadFromFile()
	{
		std::fstream File;
		File.open("Highscore.txt", std::ios::in);

		char* string;
		int points;

		for(int i = 0; i < 10 && !File.eof(); i++)
		{
			File >> string;
			Placement[i]->SetName(string);
			File >> points;
			Placement[i]->SetScore(points);
		}
		File.close();
	}
	void HighscoreList::Insert(HighscoreEntry* NewEntry)
	{
		delete[] Placement[10];		// Gibt Speicher des 10 Eintrages wieder frei
		Placement[10] = NewEntry;
		HighscoreEntry* tmp;

		// Voraussetzung: Liste ist sortiert
		for(int i = 9; i; i--)
		{
			if(Placement[i]->GetScore() > Placement[i-1]->GetScore() )
			{
				tmp = Placement[i-1];
				Placement[i-1] = Placement[i];
				Placement[i] = tmp;
			}
		}
	}
}