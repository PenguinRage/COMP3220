#ifndef BATTLESPHERE_H
#define BATTLESPHERE_H

#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QApplication>
#include <QPushButton>

#include <vector>

#include "commandcentre.h"
#include "defender.h"
#include "iofile.h"
#include "bullet.h"
#include "star.h"

namespace si {

    class BattleSphere : public QDialog
    {
    public:
        BattleSphere(QWidget *parent, Defender d, int bulletSpeed, CommandCentre cc);
        ~BattleSphere();

    private:
        Q_OBJECT
        QPixmap m_defenderImg;
        QPixmap m_bulletImg;
        QPixmap m_starImg;
        QTimer* m_timer;
        QPushButton *m_button;

        std::vector<Bullet> m_bullets;

        std::vector<Star> m_stars;

        int m_numStars = 30;

        int m_bulletSpeed;

        int m_screenWidth = 600;
        int m_screenHeight = 400;

        CommandCentre m_commandCentre;

        Defender m_defender;

    protected:
        void paintEvent(QPaintEvent *event);

    public slots:
        void nextFrame();
        void screenshot();
    };

} // end namespace si

#endif // BATTLESPHERE_H
