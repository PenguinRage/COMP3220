#ifndef BATTLESPHERE_H
#define BATTLESPHERE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QSound>
#include <QTimer>
#include "spaceitemfactory.h"
#include "config.h"
#include <QKeyEvent>
#include <cstdlib>
#include <iostream>

namespace si {

    class BattleSphere : public QDialog
    {
        Q_OBJECT
        Config * config;
        SpaceItemFactory factory;
        Defender * ship;
        Star * star;
        vector<Bullet *> bullets;
        vector<string> commands;
        vector<Star *> stars;
        QSound sound;
        QTimer* timer;
        int dx = 0;
        int dy = 350;
        int ds = 30;
        int counter = 0;



    public:
        BattleSphere(QWidget *parent = nullptr);
        ~BattleSphere();
        void setDefender(Defender * ship);
        void spaceshipCommand();
        void fallingStars();
        void firingBullets(int ship_width);

    protected:
        void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);
        void togglePause();
    private:
        bool gamerunner = true;
    public slots:
        void nextFrame();
    };

} // end namespace si

#endif // BATTLESPHERE_H
