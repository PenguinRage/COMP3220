#include "menu.h"

namespace game {
Menu::Menu(QWidget* parent, QString name, int& playerScore, QList<QPair<QString, int>> scores, bool m, bool k)
        : gameScore(playerScore), mouse(m), keyboard(k) {
    // Scores could be read in the future.
    makeButtons(parent, name);
}

Menu::~Menu() {
    delete score;
    delete playerName;
    delete playerScoreLabel;
    delete fast_button;
    delete mouse_button;
    delete keyboard_button;
}

void Menu::makeButtons(QWidget* parent, QString name) {

    score = new QPushButton("Score", parent);
    score->setGeometry(QRect(0, 0, 100, 30));
    score->setVisible(false);
    score->setStyleSheet("background-color: blue");
    score->setFocusPolicy(Qt::NoFocus);
    QObject::connect(score, SIGNAL(released()), parent, SLOT(showScore()));

    fast_button = new QPushButton("Faster", parent);
    fast_button->setGeometry(QRect(450, 100, 100, 30));
    fast_button->setVisible(false);
    fast_button->setStyleSheet("background-color: white");
    fast_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(fast_button, SIGNAL(released()), parent, SLOT(setFastSpeed()));

    slow_button = new QPushButton("Slower", parent);
    slow_button->setGeometry(QRect(300, 100, 100, 30));
    slow_button->setVisible(false);
    slow_button->setStyleSheet("background-color: white");
    slow_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(slow_button, SIGNAL(released()), parent, SLOT(setSlowSpeed()));

    mouse_button = new QPushButton("Mouse", parent);
    mouse_button->setGeometry(QRect(300, 10, 100, 30));
    mouse_button->setVisible(false);
    colourButtons(mouse_button, mouse);
    mouse_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(mouse_button, SIGNAL(released()), parent, SLOT(toggleMouse()));

    keyboard_button = new QPushButton("Keyboard", parent);
    keyboard_button->setGeometry(QRect(450, 10, 100, 30));
    keyboard_button->setVisible(false);
    colourButtons(keyboard_button, keyboard);
    keyboard_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(keyboard_button, SIGNAL(released()), parent, SLOT(toggleKeyboard()));

    playerName = new QLabel(parent);
    playerName->setGeometry(0, 30, 100, 30);
    playerName->setText(name);
    playerName->setVisible(false);
    playerName->setStyleSheet("background-color: white");

    playerScoreLabel = new QLabel(parent);
    playerScoreLabel->setGeometry(100, 30, 100, 30);
    playerScoreLabel->setText(QString::number(gameScore));
    playerScoreLabel->setVisible(false);
    playerScoreLabel->setStyleSheet("background-color: gray");
}

void Menu::colourButtons(QPushButton * input_button, bool cond) {
    if (cond) {
        input_button->setStyleSheet("background-color: green");
    }
    else {
        input_button->setStyleSheet("background-color: red");
    }
}

// called when game is paused or unpaused
void Menu::displayMenu(bool paused) {
    if (!paused) {
        closeButtons();
    } else {
        score->setVisible(true);
        mouse_button->setVisible(true);
        keyboard_button->setVisible(true);
        fast_button->setVisible(true);
        slow_button->setVisible(true);
    }
}

// helper, closes all the opened menus
void Menu::closeButtons() {
    score->setVisible(false);
    mouse_button->setVisible(false);
    keyboard_button->setVisible(false);
    fast_button->setVisible(false);
    slow_button->setVisible(false);
    revealPlayerScore(false);

}

// helper function for OpenScore
void Menu::revealPlayerScore(bool open) {
    // recalculate playerScoreLabel
    playerScoreLabel->setText(QString::number(gameScore));
    playerName->setVisible(open);
    playerScoreLabel->setVisible(open);
}

void Menu::openScore() {
    if (playerName->isVisible()) {
        revealPlayerScore(false);
    } else {
        revealPlayerScore(true);
    }
}

bool Menu::useKeyboard() {
    return keyboard;
}

bool Menu::useMouse() {
    return mouse;
}

void Menu::toggleKeyboard()
{
    if (keyboard) {

        keyboard = false;
    }
    else {
        keyboard = true;
    }

    colourButtons(keyboard_button, keyboard);
}

void Menu::toggleMouse()
{
    if (mouse) {
        mouse = false;
    }
    else {
        mouse = true;
    }
    colourButtons(mouse_button, mouse);
}


}
