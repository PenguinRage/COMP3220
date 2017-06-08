#include "heatseeker.h"

namespace game {
// Missiles to seek targets
HeatSeeker::HeatSeeker(
        QPixmap image, int x, int y, int bullet_velocity, bool friendly)
        : Bullet(image, x, y, bullet_velocity, friendly) {
    // The base image will be rotated by the builder.
    // Because builders construct the complex parts :)
}

// Moves the missile dependent on the position of the ship
void HeatSeeker::move() {
    if (target_x + 50 < this->get_x()) {
        this->set_x(this->get_x() - get_bullet_velocity());
    }
    else {
        this->set_x(this->get_x() + get_bullet_velocity());
    }
    this->set_y(this->get_y() - get_bullet_velocity());
}
// Target acquired
void HeatSeeker::setTarget(int x)
{
    target_x = x;
}

}
