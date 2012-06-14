#ifndef ULDERICO_ALPHA_INVADER_H_INCLUDED
#define ULDERICO_ALPHA_INVADER_H_INCLUDED

#include "Object.h"

#include "InvaderType.h"
#include "BulletType.h"

namespace UldericoAlpha
{
	/**
	* Klasse, welche die Invader abbildet.
	* Der Typ des Invaders wird über den Konstruktor gesetzt
	*/
	class Invader : public Object
	{
	public:
		/**
		* Hier wird der gewählte Invader erstellt
		*/
		Invader(InvaderType type);

		InvaderType GetType() const { return m_type; };

		BulletType GetBulletType() const { return GetBulletFrom(m_type); }

		bool IsAlive() const { return m_alive; }

		void Kill() { m_alive = false; }

	private:
		InvaderType m_type;
		bool m_alive;
	};
}

#endif //ULDERICO_ALPHA_INVADER_H_INCLUDED