#ifndef ULDERICO_ALPHA_SQUADRON_H_INCLUDED
#define ULDERICO_ALPHA_SQUADRON_H_INCLUDED

#include "Object.h"
#include "Invader.h"
#include "InvaderType.h"
#include "BoundingBox.h"
#include "MotionPattern.h"

#include <vector>
#include <algorithm>

namespace UldericoAlpha
{
	class Squadron : public Object
	{
	public:
		Squadron();
				
		void SetBoundingBox(Vector2D size, Vector2D position);

		void Initialize();

        std::vector<Invader>::const_iterator InvadersBegin() const
        { return m_invaders.begin(); }

        std::vector<Invader>::const_iterator InvadersEnd() const
        { return m_invaders.end(); }

		bool HasInvaders() const { return m_invaders.size() > 0; };

		void EraseInvaders();

		bool Collision(Object const bullet);

		virtual void Update();

	private:
		std::vector<Invader> m_invaders;
		BoundingBox m_boundingBox;
		MotionPattern m_motionPattern;
		static const int MARGIN = 6;		
		static const int INVADER_SPEED = 5;
	};
}

#endif //ULDERICO_ALPHA_SQUADRON_H_INCLUDED