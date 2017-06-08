#include "menu.h"

namespace game {
Menu::Menu(QWidget* parent, QString name, int& playerScore, QList<QPair<QString, int>> scores, bool m, bool k)
        : gameScore(playerScore), mouse(m), keyboard(k), scoreboard(scores) {
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
    for (int i = 0; i < 10; i++) {
        delete table.at(i);
    }
    delete exit_button;
    delete reset_button;
}

// Makes the buttons for the Menu UI
void Menu::makeButtons(QWidget* parent, QString name) {
    if (parent == NULL) return;



    // Score Button
    score = new QPushButton("Scores", parent);
    score->setGeometry(QRect(0, 0, 100, 30));
    score->setVisible(false);
    score->setStyleSheet("background-color: blue");
    score->setFocusPolicy(Qt::NoFocus);
    QObject::connect(score, SIGNAL(released()), parent, SLOT(showScore()));

    // Faster Speed Button
    fast_button = new QPushButton("Faster", parent);
    fast_button->setGeometry(QRect(450, 200, 100, 30));
    fast_button->setVisible(false);
    fast_button->setStyleSheet("background-color: white");
    fast_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(fast_button, SIGNAL(released()), parent, SLOT(setFastSpeed()));

    // Slower Speed Button
    slow_button = new QPushButton("Slower", parent);
    slow_button->setGeometry(QRect(300, 200, 100, 30));
    slow_button->setVisible(false);
    slow_button->setStyleSheet("background-color: white");
    slow_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(slow_button, SIGNAL(released()), parent, SLOT(setSlowSpeed()));

    // Mouse Control Button
    mouse_button = new QPushButton("Mouse", parent);
    mouse_button->setGeometry(QRect(300, 100, 100, 30));
    mouse_button->setVisible(false);
    colourButtons(mouse_button, mouse);
    mouse_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(mouse_button, SIGNAL(released()), parent, SLOT(toggleMouse()));

    // Keyboard Control Button
    keyboard_button = new QPushButton("Keyboard", parent);
    keyboard_button->setGeometry(QRect(450, 100, 100, 30));
    keyboard_button->setVisible(false);
    colourButtons(keyboard_button, keyboard);
    keyboard_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(keyboard_button, SIGNAL(released()), parent, SLOT(toggleKeyboard()));

    // Labels for player and score
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

    // Building the Scoreboard elements
    QString del = ": ";
    for (int i = 0; i < scoreboard.size(); i++) {
        if (i == 10) break;
        QLabel * tmp = new QLabel(parent);
        QString str = '\t' + scoreboard.at(i).first + del  +'\t' + '\t' + QString::number(scoreboard.at(i).second);
        tmp->setGeometry(0,200+ i * 35, 200, 30);
        tmp->setText(str);
        tmp->setVisible(false);
        tmp->setStyleSheet("background-color: white");
        table.append(tmp);
    }
    // Exit Button
    exit_button = new QPushButton("Exit", parent);
    exit_button->setGeometry(QRect(800, 650, 100, 30));
    exit_button->setVisible(false);
    exit_button->setStyleSheet("background-color: red");
    exit_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(exit_button, SIGNAL(released()), parent, SLOT(exit()));

    reset_button = new QPushButton("Reset", parent);
    reset_button->setGeometry(QRect(800, 550, 100, 30));
    reset_button->setVisible(false);
    reset_button->setStyleSheet("background-color: green");
    reset_button->setFocusPolicy(Qt::NoFocus);
    QObject::connect(reset_button, SIGNAL(released()), parent, SLOT(reset()));
}

// Toggles the color of the buttons when on and off
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
        reset_button->setVisible(true);
        exit_button->setVisible(true);
    }
}

// helper, closes all the opened menus
void Menu::closeButtons() {
    score->setVisible(false);
    mouse_button->setVisible(false);
    keyboard_button->setVisible(false);
    fast_button->setVisible(false);
    slow_button->setVisible(false);
    reset_button->setVisible(false);
    exit_button->setVisible(false);
    revealPlayerScore(false);
    for (int i = 0; i < table.size(); i++) {
        table.at(i)->setVisible(false);
    }

}

// helper function for OpenScore
void Menu::revealPlayerScore(bool open) {
    // recalculate playerScoreLabel
    playerScoreLabel->setText(QString::number(gameScore));
    playerName->setVisible(open);
    playerScoreLabel->setVisible(open);
}

// Opens the player score and the scoreboard
void Menu::openScore() {
    if (playerName->isVisible()) {
        revealPlayerScore(false);
        for (int i = 0; i < table.size(); i++) {
            table.at(i)->setVisible(false);
        }
    } else {
        revealPlayerScore(true);
        for (int i = 0; i < table.size(); i++) {
            table.at(i)->setVisible(true);
        }
    }
}

// returns wheither keyboard is in use
bool Menu::useKeyboard() {
    return keyboard;
}

// returns wheither mouse is in use
bool Menu::useMouse() {
    return mouse;
}

// toggles keyboardUI and functionality on and off
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

// toggles mouseUI and functionality on and off
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
