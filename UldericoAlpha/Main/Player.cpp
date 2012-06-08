#include "Player.h"

namespace UldericoAlpha
{
    /**
     * Die Gr��e des Spielers muss hier angepasst werden, falls sich
     * die Darstellung �ndert.
     */
    static const Vector2D PLAYER_SIZE(117.0f * 0.4f, 70.0f * 0.4f);

    Player::Player(int lives)
        : Object(Vector2D::ZERO, PLAYER_SIZE),
		  m_lives(lives)
    { }
}
