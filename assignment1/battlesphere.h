#ifndef BATTLESPHERE_H
#define BATTLESPHERE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QSound>
#include <QTimer>
#include "spaceitemfactory.h"
#include <config.h>

namespace si {

    class BattleSphere : public QDialog
    {
        Q_OBJECT
        Config * config;
        SpaceItemFactory factory;
        Defender * ship;
        vector<Bullet *> bullets;
        QPixmap bullet;
        QSound sound;
        QTimer* timer;
        int dx = 0;
        int dy = 350;
        int ds = 30;
        int bx = -1000;
        int by = -1000;
        int bs = 10;
        int counter = 0;
        vector<string> commands;


    public:
        BattleSphere(QWidget *parent = nullptr);
        ~BattleSphere();
        void setDefender(Defender * ship);
        void spaceshipCommand();
    protected:
        void paintEvent(QPaintEvent *event);
    public slots:
        void nextFrame();
    };

} // end namespace si

#endif // BATTLESPHERE_H
