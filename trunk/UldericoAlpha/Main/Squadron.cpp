#include "Squadron.h"

namespace UldericoAlpha
{	
    static const Vector2D SQUADRON_SIZE(123.0f * 0.4f, 87.0f * 0.4f);

	Squadron::Squadron()
		: Object(Vector2D::ZERO, SQUADRON_SIZE),
		  m_motionPattern(true)
	{ }

	void Squadron::SetBoundingBox(Vector2D size, Vector2D position)
	{
		m_boundingBox = BoundingBox(size, position);
	}

	void Squadron::Initialize()
	{
		//Invaders initialisieren
		m_invaders.reserve(30);
				
		Vector2D speed(INVADER_SPEED, 0.0f);

		for(int j = 2; j >= 0 ; j--)
		{
			for(int i = 0; i < 10; i++)
			{
				Invader invader((InvaderType)j);
				invader.SetPosition(Vector2D((invader.GetSize().GetX() + MARGIN) * i, (invader.GetSize().GetY() + MARGIN) * j));
				invader.SetSpeed(speed);
				m_invaders.push_back(invader);
			}
		}

		//Bewegungsablauf festlegen
		m_motionPattern.AddStep(InvaderAction_MoveRight, -1);
		m_motionPattern.AddStep(InvaderAction_MoveDown, 5);
		m_motionPattern.AddStep(InvaderAction_MoveLeft, -1);
		m_motionPattern.AddStep(InvaderAction_MoveDown, 5);
	}

	void Squadron::EraseInvaders()
	{
		// Alle getöteten Invader entfernen
		auto eraseInvaders = std::remove_if(m_invaders.begin(), m_invaders.end(),
			[] (Invader const& invader) { return !invader.IsAlive(); });

		m_invaders.erase(eraseInvaders, m_invaders.end());
	}

	bool Squadron::Collision(Object const bullet)
	{		
		// Hat die Kugel einen Invader aus dem Schwadron getroffen?
		for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			if (invader->CollidesWith(bullet))
			{
				invader->Kill();
				return true;
			}
		}
		return false;
	}

	void Squadron::Update()
	{
		if (m_invaders.empty())
			return;

		Vector2D speed;

		for(auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			BoundingBoxAction boundingBoxAction = m_boundingBox.InBoundingBox(*invader);
			if(boundingBoxAction != BoundingBoxAction_Move)
			{
				m_motionPattern.SetNextAction();
				if(m_motionPattern.GetAction() == InvaderAction_MoveDown && boundingBoxAction == BoundingBoxAction_CollisionBottom)
					m_motionPattern.SetNextAction();
				break;
			}
		}
/*
		std::for_each(m_invaders.begin(), m_invaders.end(), [&] (Invader const& invader)
		{
			BoundingBoxAction boundingBoxAction = m_boundingBox.InBoundingBox(invader);
			if(boundingBoxAction != BoundingBoxAction_Move)
			{
				m_motionPattern.SetNextAction();
			}
		});
*/
		switch(m_motionPattern.GetAction())
		{
		case InvaderAction_MoveDown:
			speed = Vector2D(0.0f, INVADER_SPEED);
			break;
		case InvaderAction_MoveLeft:
			speed = Vector2D(-INVADER_SPEED, 0.0f);
			break;
		case InvaderAction_MoveRight:
			speed = Vector2D(INVADER_SPEED, 0.0f);
			break;
		default:
			speed = Vector2D::ZERO;
		}

		for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			if(speed != Vector2D::ZERO)
				invader->SetSpeed(speed);
			invader->Update();
		}
	}
}