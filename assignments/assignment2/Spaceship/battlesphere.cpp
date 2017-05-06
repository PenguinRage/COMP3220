#include "battlesphere.h"

#include <random>

namespace si {

    /**
     * \brief: Constructs BattleSphere game using the provided defender
     * \param: parent, not used here
     * \param: d, defender describing where the player position is initially
     * \param: bulletSpeed, how many pixels to move bullet in one frame
     * \param: commandCentre, stores buffer of user inputs (just file inputs initially)
     * \result: the person
     */
    BattleSphere::BattleSphere(QWidget *parent,
                           Defender d, int bulletSpeed, CommandCentre cc, std::vector<Swarm> s)
        : QDialog(parent),
          m_defender(d),
          m_bulletSpeed(bulletSpeed),
          m_commandCentre(cc),
          m_swarms(s)
    {
        m_score = new Score();
        srand(time(NULL));


        for (int i=0; i<m_numStars; ++i) {
            int randX = rand() % m_screenWidth;
            int randY = rand() % m_screenHeight;

            float randStartOpacity = ((double) rand() / (RAND_MAX)) + 1;
            Star curStar(randX, randY);
            curStar.setOpacity(randStartOpacity);
            m_stars.push_back(curStar);
        }

        m_defenderImg.load(":/images/player.png");
        m_bulletImg.load(":/images/fireball.png");
        m_starImg.load(":/images/star.png");
        m_invader1.load(":/images/invader_1.png");
        m_invader2.load(":/images/invader_2.png");
        m_invader3.load(":/images/invader_3.png");

        m_bulletImg = m_bulletImg.scaledToHeight(15);
        m_invader1 = m_invader1.scaledToWidth(80);
        m_invader2 = m_invader2.scaledToWidth(80);
        m_invader3 = m_invader3.scaledToWidth(80);
        m_explosion = m_starImg.scaledToHeight(m_invader1.height());
        m_starImg = m_starImg.scaledToWidth(5);

        if (d.getScale() == "tiny") {
            m_defenderImg = m_defenderImg.scaledToWidth(40);
        } else if (d.getScale() == "normal") {
            m_defenderImg = m_defenderImg.scaledToWidth(70);
        } else if (d.getScale() == "large") {
            m_defenderImg = m_defenderImg.scaledToWidth(100);
        } else if (d.getScale() == "giant") {
            m_defenderImg = m_defenderImg.scaledToWidth(140);
        }

        setStyleSheet("background-color: #000000;");
        this->resize(m_screenWidth, m_screenHeight);
        update();

        // Create the button, make "this" the parent
        m_button = new QPushButton("Save Screenshot!", this);
        // set size and location of the button
        m_button->setGeometry(QRect(QPoint(0, 0),
        QSize(150, 50)));
        m_button->setStyleSheet("background-color: #FFFFFF;");

        m_timer = new QTimer(this);
        connect(m_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
        connect(m_button, SIGNAL(released()), this, SLOT(screenshot()));
        m_timer->start(50);
    }

    /**
     * \brief: Destroys dynamically allocated variables
     */
    BattleSphere::~BattleSphere() {
        delete m_timer;
        delete m_button;
        delete m_score;
    }

    /**
     * \brief: called on each frame, re draws all objects
     * \param: event, description of when to perform the redraw
     */
    void BattleSphere::paintEvent(QPaintEvent *event) {
        QPainter painter(this);

        if (m_gameover)
        {
            painter.setFont({"Helvetica", 40});
            painter.setPen({255, 170, 50, 208});
            painter.drawText(QPoint((400), 400), "Game Over");
        }

        for (auto &curBullet : m_bullets) {
            painter.drawPixmap(curBullet.getX(), curBullet.getY(), m_bulletImg);
            curBullet.updateX(m_bulletSpeed);
            curBullet.updateY(m_bulletSpeed);
        }

        for (auto &curLaser : m_lasers) {
            painter.drawPixmap(curLaser.getX(), curLaser.getY(), m_bulletImg);
            curLaser.updateX(m_laserSpeed);
            curLaser.updateY(m_laserSpeed);
        }

        for (auto &curSwarm : m_swarms) {
            for (int i = 0; i < curSwarm.getSize(); i++)
            {
                Alien* curAlien = curSwarm.getAlien(i);
                if (curAlien->isBlown())
                {
                    painter.drawPixmap(curAlien->getX(), curAlien->getY(), m_explosion);
                    curAlien->setDestroyed(false);
                }
                if (!curAlien->isAlive()) continue;
                int type = curAlien->getSwarmID() % 3;
                if (type == 1)
                {
                    painter.drawPixmap(curAlien->getX(), curAlien->getY(), m_invader1);
                }
                else if (type == 2)
                {
                    painter.drawPixmap(curAlien->getX(), curAlien->getY(), m_invader2);
                }
                else
                {
                    painter.drawPixmap(curAlien->getX(), curAlien->getY(), m_invader3);
                }
            }
        }
        std::stringstream ss;
        ss << "Score: " << m_score->getScore();

        painter.setFont({"Helvetica", 30});
        painter.setPen({255, 170, 50, 208});
        painter.drawText(QPoint((m_screenWidth-200), 50), ss.str().c_str());
        if (m_gameover)
        {
            painter.drawPixmap(m_defender.getX(), m_defender.getY(), m_explosion);
        }
        else
        {
            painter.drawPixmap(m_defender.getX(), m_defender.getY(), m_defenderImg);
        }


        for (auto &curStar : m_stars) {
            if (curStar.getOpacity() > 0.6 && curStar.getOpacityDelta() > 0) {
                curStar.toggleOpacityDelta();
            } else if (curStar.getOpacity() < 0.1 && curStar.getOpacityDelta() < 0) {
                curStar.toggleOpacityDelta();
            }
            curStar.setOpacity(curStar.getOpacity() + curStar.getOpacityDelta());
            painter.setOpacity(curStar.getOpacity());
            painter.drawPixmap(curStar.getX(), curStar.getY(), m_starImg);
        }

    }

    /**
     * \brief: runs every X seconds, where X is the value sent to the timer
     *         function in the input
     */
    void BattleSphere::nextFrame() {
        // Check to see if gameover
        for (auto& curLaser : m_lasers)
        {
            if (m_defender.isHit(curLaser.getX(),curLaser.getY(), m_defenderImg.width(), m_defenderImg.height()))
            {
                m_gameover = true;
                update();
                m_timer->stop();
                return;
            }
        }


        // check for alien kills
        for (auto &curSwarm : m_swarms) {
            curSwarm.move();
            for (int i = 0; i < curSwarm.getSize(); i++)
            {
                Alien* curAlien = curSwarm.getAlien(i);

                if (!curAlien->isAlive()) continue;

                int pos = 0;
                bool hit = false;

                if (m_bullets.empty()) continue;
                for (auto &curBullet : m_bullets)
                {
                    if (curAlien->isHit(curBullet.getX(), curBullet.getY(), m_invader1.width(), m_invader1.height()))
                    {
                        m_score->increment();
                        curAlien->setDestroyed(true);
                        hit = true;
                        break;
                    }
                    pos++;
                }
                if (hit) m_bullets.erase(m_bullets.cbegin() + pos);
            }
        }
        if ((m_frame % m_tolerance) == 0) {
        for (auto &curSwarm : m_swarms) {
            for (int i = 0; i < curSwarm.getSize(); i++)
            {
                Alien* curAlien = curSwarm.getAlien(i);

                if (curAlien->shoot() && curAlien->isAlive())
                {
                    int bx = curAlien->getX() + (m_invader1.width()) - (m_invader1.width()/1.7);
                    int by = curAlien->getY() + m_invader1.height();
                    Laser b(bx, by);
                    m_lasers.push_back(b);
                }
            }
        }
        }

        // animate the defender
        int maxX = this->width() - m_defenderImg.width();

        if (m_commandCentre.hasNext()) {
            std::string nextCommand = m_commandCentre.popNext();
            if (nextCommand == "Left") {
                m_defender.setX(m_defender.getX() - m_defender.getSpeed());
                if (m_defender.getX() < 0) {
                    m_defender.setX(0);
                }
            } else if (nextCommand == "Right") {
                m_defender.setX(m_defender.getX() + m_defender.getSpeed());
                if (m_defender.getX() > maxX) {
                    m_defender.setX(maxX);
                }
            } else if (nextCommand == "Fire") {
                int bx = m_defender.getX() + (m_defenderImg.width()/2) - (m_bulletImg.width()/2);
                int by = m_defender.getY() - m_bulletImg.height();
                Bullet b(bx, by);
                m_bullets.push_back(b);
            }
        }

        update();
        m_frame++;
    }

    void BattleSphere::screenshot()
    {
        QWidget *w = QApplication::activeWindow();
        if(w) {
            QPixmap p = QPixmap::grabWidget(w);
            p.save(QString("BattleSphereScreenshot.png"));
        }
    }

} // end namespace si
