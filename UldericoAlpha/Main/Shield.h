#ifndef ULDERICO_ALPHA_SHIELD_H_INCLUDED
#define ULDERICO_ALPHA_SHIELD_H_INCLUDED

#include <vector>

#include "Object.h"

namespace UldericoAlpha
{
	/**
	* Klasse des Schutzschilds mit integriertem Schadensmodell
	*/
	class Shield : public Object
	{
	public:
        static const float BLOCK_WIDTH;
		static const float BLOCK_HEIGHT;
        
        static const int BLOCK_COUNT_WIDTH = 10;
        static const int BLOCK_COUNT_HEIGHT = 5;

		/**
		* Erstellt ein Schild an gegebener Position
		*/
		Shield(float positionX, float positionY);

		/**
		* Zeigt an, ob an der Stelle ein Schildfragment existiert.
        *
        * Die Position muss folgenden Bedingungen genügen:
        *  0 <= positionX < BLOCK_COUNT_WIDTH
        *  0 <= positionY < BLOCK_COUNT_HEIGHT
		*/
		bool FragmentExists(int positionX, int positionY) const;

    protected:
        /**
         * Überprüft, ob eine Kollision mit noch intakten Schildteilen
         * aufgetretetn ist.
         */
        virtual bool DetectCollision(Object const& other);

    private:
        static bool IsFilled(int xPosition, int yPosition);

		bool m_fragments[BLOCK_COUNT_HEIGHT][BLOCK_COUNT_WIDTH];
	};
}

#endif //ULDERICO_ALPHA_SHIELD_H_INCLUDED
