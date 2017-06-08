#ifndef HEATSEEKER_H
#define HEATSEEKER_H
#include "bullet.h"
#include <QPixmap>

namespace game {
class HeatSeeker : public Bullet {
protected:
    int target_x;
public:
    HeatSeeker(QPixmap image, int x, int y, int bullet_velocity, bool friendly);
    virtual ~HeatSeeker() {}
    void move();
    void setTarget(int x);
};
}

#endif // HEATSEEKER_H
