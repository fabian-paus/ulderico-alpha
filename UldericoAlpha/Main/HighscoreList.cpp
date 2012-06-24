#include "HighscoreList.h"
#include <fstream>
#include "HighscoreBehaviour.h"
#include <string>



namespace UldericoAlpha
{
	// Funktionen der Highscore Liste

	bool HighscoreList::CanInsert(int Points)
	{
		return Placement[MAX_ENTRIES-1].GetScore() < Points;
	}

	const HighscoreEntry& HighscoreList::GetEntry(int Index)
	{
		return Placement[Index];
	}

	void HighscoreList::SaveToFile()
	{
		std::fstream File;
		File.open("Highscore.txt", std::ios::out);

		for(int i = 0; i < MAX_ENTRIES; i++)
		{
			File << Placement[i].GetName() << std::endl;
			File << Placement[i].GetScore() << std::endl;
		}
		File.close();
	}

	void HighscoreList::LoadFromFile()
	{
		std::fstream File;
		File.open("Highscore.txt", std::ios::in);

		std::string tmp;
		int points;

		for(int i = 0; i < MAX_ENTRIES && !File.eof(); i++)
		{
			File >> tmp;
			Placement[i].SetName(tmp);
			File >> points;
			Placement[i].SetScore(points);
		}
		File.close();
		//HighscoreBehaviour::STR_PLACEMENT_NAME_FIRST = Placement[0].GetName();

	}
	void HighscoreList::Insert (const HighscoreEntry& NewEntry)
	{
		HighscoreEntry tmp = Placement[MAX_ENTRIES-1];
		Placement[MAX_ENTRIES-1] = NewEntry;
		
		// Voraussetzung: Liste ist sortiert
		for(int i = MAX_ENTRIES-1; i; i--)
		{
			if(Placement[i].GetScore() > Placement[i-1].GetScore() )
			{
				tmp = Placement[i-1];
				Placement[i-1] = Placement[i];
				Placement[i] = tmp;
			}
		}
	}

}