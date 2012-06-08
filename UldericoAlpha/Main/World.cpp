#include "World.h"

#include <algorithm>

namespace UldericoAlpha
{
    /** 
     * Die Absolutgeschwindigkeit des Spielers, wenn dieser bewegt wird,
     * kann hier angepasst werden.
     */
    static const float PLAYER_ABS_SPEED = 10.0f;
	static const float INVADER_ABS_SPEED = 10.0f;

	static const int INITIAL_PLAYER_LIVES = 3;

    World::World(Vector2D const& size)
        : m_size(size),
		  m_player(INITIAL_PLAYER_LIVES)
    {
        InitializePlayer();
        InitializeShields();
		InitializeInvaders();
    }
    
    void World::MovePlayerLeft()
    {
        m_player.SetSpeed(Vector2D(-PLAYER_ABS_SPEED, 0.0f));
        if (!CanPlayerMove())
            StopPlayerMovement();
    }
    
    void World::MovePlayerRight()
    {
        m_player.SetSpeed(Vector2D(+PLAYER_ABS_SPEED, 0.0f));
        if (!CanPlayerMove())
            StopPlayerMovement();
    }

    void World::StopPlayerMovement()
    {
        m_player.SetSpeed(Vector2D::ZERO);
    }

    void World::ShootFromPlayer()
    {
        Vector2D position(
            m_player.GetPosition().GetX() + m_player.GetSize().GetX() / 2.0f - Bullet::WIDTH / 2.0f,
            m_player.GetPosition().GetY() - Bullet::HEIGHT);

        Vector2D speed(0.0f, -10.0f);

        m_bullets.push_back(Bullet(position, speed));
    }

    void World::Update()
    {
        UpdatePlayer();

		UpdateInvaders();

        for (auto shield = m_shields.begin(); shield != m_shields.end(); ++shield)
            shield->Update();

        for (auto bullet = m_bullets.begin(); bullet != m_bullets.end(); ++bullet)
            bullet->Update();

        CheckCollisions();
    }

    void World::InitializePlayer()
    {
        Vector2D startPosition(
            GetWidth() / 2.0f - m_player.GetSize().GetX() / 2.0f, 
            GetHeight() - m_player.GetSize().GetY() - 30.0f);

        m_player.SetPosition(startPosition);
    }

    void World::InitializeShields()
    {
        // Speicher reservieren, um mehrfache Allokationen zu vermeiden
        m_shields.reserve(4);

        m_shields.push_back(Shield( 60, 420));
		m_shields.push_back(Shield(240, 420));
		m_shields.push_back(Shield(420, 420));
		m_shields.push_back(Shield(600, 420));
    }

	void World::InitializeInvaders()
	{
		m_invaders.reserve(30);
				
		Vector2D speed(INVADER_ABS_SPEED, 0.0f);

		for(int j = 2; j >= 0 ; j--)
		{
			for(int i = 0; i < 10; i++)
			{
				Invader invader((InvaderType)j);
				invader.SetPosition(Vector2D((invader.GetSize().GetX() + 6.0f) * i, (invader.GetSize().GetY() + 6.0f) * j));
				invader.SetSpeed(speed);
				m_invaders.push_back(invader);
			}
		}

	}

    void World::UpdatePlayer()
    {
        m_player.Update();
        if (!CanPlayerMove())
            StopPlayerMovement();
    }

	void World::UpdateInvaders()
	{
		if (m_invaders.empty())
			return;

		//Links dagegen oder rechts oder unten
		//maxX, minY, maxY
		//  x->
		//y
		//|
		//v
		Vector2D maxX = m_invaders.begin()->GetPosition();
		Vector2D minX = m_invaders.begin()->GetPosition();
		Vector2D maxY = m_invaders.begin()->GetPosition();
		Vector2D minY = m_invaders.begin()->GetPosition();

		Vector2D speed;

		for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			Vector2D invaderPos = invader->GetPosition();
			if(invaderPos.GetX() > maxX.GetX())
				maxX = invader->PredictPosition(2.0f);			
			if(invaderPos.GetY() > maxY.GetY())
				maxY = invader->PredictPosition(2.0f);
			if(invaderPos.GetX() < minX.GetX())
				minX = invader->PredictPosition(2.0f);
			if(invaderPos.GetY() < minY.GetY())
				minY = invader->PredictPosition(2.0f);
		}

		if(minX.GetX() <= 0)
		{
			Vector2D right(INVADER_ABS_SPEED, 0);
			speed = right;
		}
		if(maxX.GetX() + m_invaders.begin()->GetSize().GetX() >= m_size.GetX())
		{
			Vector2D left(-INVADER_ABS_SPEED, 0);
			speed = left;
		}

		if(maxX.GetX() >= m_size.GetX())
		{
		}
		

		for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			if(speed != Vector2D::ZERO)
				invader->SetSpeed(speed);
			invader->Update();
		}
	}
    
    bool World::CanPlayerMove() const
    {
        Vector2D nextPosition = m_player.PredictPosition(1.0f);

        // Linker Rand
        if (nextPosition.GetX() < 0.0f)
            return false;

        // Rechter Rand (Größe des Spielers mit einbeziehen)
        if (nextPosition.GetX() > GetWidth() - m_player.GetSize().GetX())
            return false;

        return true;
    }

    void World::CheckCollisions()
    {
		bool playerWasHit = false;

        // Wenn eine Kugel ein Schild trifft, dann entfernen
        auto eraseBullets = std::remove_if(m_bullets.begin(), m_bullets.end(), 
			[&] (Bullet const& bullet) -> bool
		{
            // Oben aus dem Bildschirm geflogen
            if (bullet.GetPosition().GetY() < -Bullet::HEIGHT)
                return true;

            // Unten aus dem Bildschirm geflogen
            if (bullet.GetPosition().GetY() > GetHeight())
                return true;

			// Hat die Kugel ein Schild getroffen?
            for (auto shield = m_shields.begin(); shield != m_shields.end(); ++shield)
            {
                if (shield->CollidesWith(bullet))
                    return true;
		    }

			// Hat die Kugel einen Invader getroffen?
			for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
			{
				if (invader->CollidesWith(bullet))
				{
					invader->Kill();
					return true;
				}
			}

			// Hat die Kugel den Spieler getroffen?
			if (m_player.CollidesWith(bullet))
				playerWasHit = true;

            return false;
        });

        m_bullets.erase(eraseBullets, m_bullets.end());

		// Alle getöteten Invader entfernen
		auto eraseInvaders = std::remove_if(m_invaders.begin(), m_invaders.end(),
			[] (Invader const& invader) { return !invader.IsAlive(); });

		m_invaders.erase(eraseInvaders, m_invaders.end());

		// Wenn der Spieler mindestens einmal getroffen wurde, verliert er ein Leben
		if (playerWasHit)
			m_player.LoseLife();
    }
}
