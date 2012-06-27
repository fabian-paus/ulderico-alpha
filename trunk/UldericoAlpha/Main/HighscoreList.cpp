#include "HighscoreList.h"
#include <fstream>
#include "HighscoreBehaviour.h"
#include <string>



namespace UldericoAlpha
{
	// Funktionen der Highscore Liste

	bool HighscoreList::CanInsert(int Points) const
	{
		return Placement[MAX_ENTRIES-1].GetScore() < Points;
	}

	const HighscoreEntry& HighscoreList::GetEntry(int Index) const
	{
		return Placement[Index];
	}

	void HighscoreList::SaveToFile() const
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
		std::ifstream file("Highscore.txt");

		for(int i = 0; i < MAX_ENTRIES && file; i++)
		{
			std::string name;
			int points = 0;

			file >> name;
			file >> points;

			Placement[i] = HighscoreEntry(name, points);
		}
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