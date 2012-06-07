#ifndef ULDERICO_ALPHA_SQUADRON_H_INCLUDED
#define ULDERICO_ALPHA_SQUADRON_H_INCLUDED

#include "Object.h"

#include "Invader.h"

#include "InvaderType.h"

#include <vector>

namespace UldericoAlpha
{
	class Squadron : public Object
	{
	public:
		Squadron();
				
        std::vector<Invader>::const_iterator InvadersBegin() const
        { return m_invaders.begin(); }

        std::vector<Invader>::const_iterator InvadersEnd() const
        { return m_invaders.end(); }

		virtual void Update();

	private:
		std::vector<Invader> m_invaders;
	};
}

#endif //ULDERICO_ALPHA_SQUADRON_H_INCLUDED