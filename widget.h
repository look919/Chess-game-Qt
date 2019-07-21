#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QDebug>

namespace Ui {
class Widget;
}class Widget : public QWidget
{ Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
    void setStartingParameters();
    void placePiecesOnBoard();

    bool isItCheck;
    bool isItCheckMate;

    //PIECES
    QVector <QString> blueFigures;      //blue figures used for showing possbile moves and colision system
    QVector <QPushButton*> whiteFiguresButtons;
    QVector <QPushButton*> blackFiguresButtons;
    void setFiguresPosition();

    bool whiteMove;       //checking whether its white or black time to play
    int numberOfMove;
    bool action;          //checking whether player click on the button for the first time(choosing figure) or for the second time(choosing place to move)


    //figures.cpp
    void getFigureName(QPushButton *button);
    QString currentFigure;

    QVector <QString> possibleMoves;
    QVector <QString> possibleMovesStorage;       // using in rook,queen and bishop functions to allow colision


    QString coords;
    void poonMovementWhite(QPushButton *button);    //seperating those two functions to make code cleaner
    void poonMovementBlack(QPushButton *button);
    void poonColision(QPushButton *button);
    void poonTaking(QPushButton *button, QString color);
    bool enPassant;


    void knightMovement(QPushButton *button);


    //buttons-manipulations
    void matchCoordinates();
    void showPermittedMoves(QPushButton *button);
    void colision(QPushButton *button, QString color, bool colisionWithOpponentPieces = false);
    void checkIfThereIsAPiece(QPushButton *button, QString color="none");
    bool ifExist;
    void cleanCoordinates();
    void cleanCoordinates_shorter(QPushButton *button);
    void goBack(QPushButton *button);
    QPushButton *currentFigureButton;       //cleaners
    QString currentFigureStyleSheet;
    void move(QPushButton *button, QString figure);
    void blockMove(QString keyword);
    void switchPlayers(QPushButton *button);
    QString matchHistory_white;
    QString matchHistory_black;
    QString matchHistory_numberOfMove;
    QString text;                                   //needed for match history and en passant move


    QPushButton *requiredButton;
    void convertStringToButton(QString coords);
    void disableAllButons();
    void enableWhiteButtons();
    void enableBlackButtons();
    void enableWhiteButtons_shorter(QPushButton *button);
    void enableBlackButtons_shorter(QPushButton *button);
    void enableProtectingFigures();


    void on_any_button_clicked(QPushButton *button);    //line 107

private slots:
    void on_startGameButton_clicked();

    //buttons-on-board.cpp
    //void on_any_button_clicked(QPushButton *button);
    void on_a1_clicked();
    void on_b1_clicked();
    void on_c1_clicked();
    void on_d1_clicked();
    void on_e1_clicked();
    void on_f1_clicked();
    void on_g1_clicked();
    void on_h1_clicked();
    void on_a2_clicked();
    void on_b2_clicked();
    void on_c2_clicked();
    void on_d2_clicked();
    void on_e2_clicked();
    void on_f2_clicked();
    void on_g2_clicked();
    void on_h2_clicked();
    void on_a3_clicked();
    void on_b3_clicked();
    void on_c3_clicked();
    void on_d3_clicked();
    void on_e3_clicked();
    void on_f3_clicked();
    void on_g3_clicked();
    void on_h3_clicked();
    void on_a4_clicked();
    void on_b4_clicked();
    void on_c4_clicked();
    void on_d4_clicked();
    void on_e4_clicked();
    void on_f4_clicked();
    void on_g4_clicked();
    void on_h4_clicked();
    void on_a5_clicked();
    void on_b5_clicked();
    void on_c5_clicked();
    void on_d5_clicked();
    void on_e5_clicked();
    void on_f5_clicked();
    void on_g5_clicked();
    void on_h5_clicked();
    void on_a6_clicked();
    void on_b6_clicked();
    void on_c6_clicked();
    void on_d6_clicked();
    void on_e6_clicked();
    void on_f6_clicked();
    void on_g6_clicked();
    void on_h6_clicked();
    void on_a7_clicked();
    void on_b7_clicked();
    void on_c7_clicked();
    void on_d7_clicked();
    void on_e7_clicked();
    void on_f7_clicked();
    void on_g7_clicked();
    void on_h7_clicked();
    void on_a8_clicked();
    void on_b8_clicked();
    void on_c8_clicked();
    void on_d8_clicked();
    void on_e8_clicked();
    void on_f8_clicked();
    void on_g8_clicked();
    void on_h8_clicked();
};

#endif // WIDGET_H
