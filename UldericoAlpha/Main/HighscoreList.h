#ifndef ULDERICO_ALPHA_HIGHSCORE_LIST_H_INCLUDED
#define ULDERICO_ALPHA_HIGHSCORE_LIST_H_INCLUDED

#include "HighscoreEntry.h"

/*
*  Highscore Liste, mit maximal 10 Eintr�gen.
*/

namespace UldericoAlpha
{
	class HighscoreList
	{
	public:
		static const int MAX_ENTRIES = 10;

		void Insert(const HighscoreEntry& NewEntry);
		bool CanInsert(int Points) const;

		const HighscoreEntry& GetEntry(int Index) const;

		void SaveToFile() const;
		void LoadFromFile();
	
	private:

		HighscoreEntry Placement[MAX_ENTRIES];

	};
}

#endif // ULDERICO_ALPHA_HIGHSCORE_LIST_H_INCLUDED