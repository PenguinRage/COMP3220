#ifndef MENU_H
#define MENU_H

#include <QLabel>
#include <QPushButton>
namespace game {
class Menu {
public:
    Menu(QWidget* parent, QString name, int& playeScore, QList<QPair<QString, int>> scores, bool m, bool k);
    ~Menu();
    void displayMenu(bool paused);
    void openScore();
    void toggleKeyboard();
    void toggleMouse();
    bool useKeyboard();
    bool useMouse();


private:
    void makeButtons(QWidget* parent, QString name);
    void closeButtons();  // if any buttons are left open, close them
    int& gameScore;
    QList<QPair<QString, int>> scoreboard;
    QList<QLabel*> table = {};

    QPushButton* score;
    QPushButton* mouse_button;
    QPushButton* keyboard_button;
    QPushButton* slow_button;
    QPushButton* fast_button;


    bool keyboard = false;
    bool mouse = false;

    QLabel* playerName;
    QLabel* playerScoreLabel;

    void revealPlayerScore(bool open);
    void colourButtons(QPushButton * input_button, bool cond);
};
}
#endif  // SCOREBUTTON_H
