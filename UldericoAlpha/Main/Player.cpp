#include "Player.h"

namespace UldericoAlpha
{
    /**
     * Die Größe des Spielers muss hier angepasst werden, falls sich
     * die Darstellung ändert.
     */
    static const Vector2D PLAYER_SIZE(117.0f * 0.4f, 70.0f * 0.4f);

    Player::Player()
        : Object(Vector2D::ZERO, PLAYER_SIZE)
    { }
}
