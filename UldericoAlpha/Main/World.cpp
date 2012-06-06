#include "World.h"

#include <algorithm>

namespace UldericoAlpha
{
    /** 
     * Die Absolutgeschwindigkeit des Spielers, wenn dieser bewegt wird,
     * kann hier angepasst werden.
     */
    static const float PLAYER_ABS_SPEED = 10.0f;

    World::World(Vector2D const& size)
        : m_size(size)
    {
        InitializePlayer();
        InitializeShields();
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

    void World::UpdatePlayer()
    {
        m_player.Update();
        if (!CanPlayerMove())
            StopPlayerMovement();
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
        // Wenn eine Kugel etwas trifft, dann entfernen
        auto erase_iter = std::remove_if(m_bullets.begin(), m_bullets.end(), [&] (Bullet const& bullet) -> bool
        {
            // Oben aus dem Bildschirm geflogen
            if (bullet.GetPosition().GetY() < -Bullet::HEIGHT)
                return true;

            // Unten aus dem Bildschirm geflogen
            if (bullet.GetPosition().GetY() > GetHeight())
                return true;

            for (auto shield = m_shields.begin(); shield != m_shields.end(); ++shield)
            {
                if (shield->CollidesWith(bullet))
                    return true;
		    }

            return false;
        });

        m_bullets.erase(erase_iter, m_bullets.end());
    }
}
