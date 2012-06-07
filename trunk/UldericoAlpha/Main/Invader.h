#ifndef ULDERICO_ALPHA_INVADER_H_INCLUDED
#define ULDERICO_ALPHA_INVADER_H_INCLUDED

#include "Object.h"

#include "InvaderType.h"

namespace UldericoAlpha
{
	/**
	* Klasse, welche die Invader abbildet.
	* Der Typ des Invaders wird �ber den Konstruktor gesetzt
	*/
	class Invader : public Object
	{
	public:
		/**
		* Hier wird der gew�hlte Invader erstellt
		*/
		Invader(InvaderType type);

		InvaderType GetType() const { return m_type; };

	private:
		InvaderType m_type;
	};
}

#endif //ULDERICO_ALPHA_INVADER_H_INCLUDED