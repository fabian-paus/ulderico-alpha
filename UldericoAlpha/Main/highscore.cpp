#include "highscore.h"
#include "string.h"
#include <fstream>
#include <iostream>


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
		NameLength = strlen(Input);
		Name = new char[NameLength + 1];
		int i = 0;
		for( ; i < NameLength; i++)
		{
			Name[i] = Input[i];
		}
		Name[i] = 0;
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

		char* tmp = new char[20];
		int points;

		for(int i = 0; i < 10 && !File.eof(); i++)
		{
			File >> tmp;
			Placement[i]->SetName(tmp);
			File >> points;
			Placement[i]->SetScore(points);
		}
		File.close();
	}
	void HighscoreList::Insert(HighscoreEntry* NewEntry)
	{
		HighscoreEntry* tmp = Placement[9];
		Placement[9] = NewEntry;
		//delete[] tmp;		// Gibt Speicher des 10 Eintrages wieder frei

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
	bool HighscoreList::Add_HighscoreEntry(int Score)
	{
		if(CanInsert(Score))
		{
			HighscoreEntry* NewEntry = new HighscoreEntry;
			char* name = new char[20];

			std::cout << "Enter your name: ";
			std::cin >> name;
			NewEntry->SetName(name);
			NewEntry->SetScore(Score);
			Insert(NewEntry);

			return 1;
		}
		else
			return 0;
	}
}