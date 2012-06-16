#ifndef ULDERICO_ALPHA_HIGHSCORE_H_INCLUDED
#define ULDERICO_ALPHA_HIGHSCORE_H_INCLUDED

namespace UldericoAlpha
{
	/*
	*  Klasse, die jeweils einen Eintrag repräsentiert.
	*/

	class HighscoreEntry
	{
	private:
		char* Name;
		short NameLength;  // Anzahl Buchstaben des Namens + terminierende "0"
		int Score;

	public:
		HighscoreEntry();
		~HighscoreEntry();
		void SetName(const char* Input);
		void SetScore(int Points) { Score = Points; }
		char* GetName() { return Name; }
		int GetScore() { return Score; }
	};

	/*
	*  Highscore Liste, mit maximal 10 Einträgen.
	*/

	class HighscoreList
	{
	private:
		HighscoreEntry* Placement[10];
		void Insert(short Place);
		short DeterminePlace(int Points);		// Ermittelt die Platzierung in der Tabelle
	
	public:
		HighscoreList();
		~HighscoreList();

		bool CanInsert(int Points);		

		HighscoreEntry* GetEntry(int Index);

		bool SaveToFile();
		bool LoadFromFile();
	};
}
#endif // ULDERICO_ALPHA_HIGHSCORE_H_INCLUDED