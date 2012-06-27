#ifndef ULDERICO_ALPHA_HIGHSCORE_ENTRY_H_INCLUDED
#define ULDERICO_ALPHA_HIGHSCORE_ENTRY_H_INCLUDED
#include <string>

namespace UldericoAlpha
{
	/*
	*  Klasse, die jeweils einen Eintrag repräsentiert.
	*/

	class HighscoreEntry
	{
	private:
		std::string Name;
		int Score;

	public:
		HighscoreEntry(const std::string& NameInput = "", int ScoreInput = 0);

		void SetName(const std::string& Input);
		void SetScore(int Points) { Score = Points; }
		const std::string& GetName() const { return Name; }
		int GetScore() const { return Score; }
	};	
}
#endif // ULDERICO_ALPHA_HIGHSCORE_ENTRY_H_INCLUDED