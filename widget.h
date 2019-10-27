#ifndef WIDGET_H
#define WIDGET_H

//poon promotion
//checkmate
//what if check
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
    //PIECES
    QVector <QString> blueFigures;              //blue figures used for showing possbile moves and colision system
    QVector <QPushButton*> whiteFiguresButtons;
    QVector <QPushButton*> blackFiguresButtons;

    void setStartingParameters();
    void placePiecesOnBoard();
    void setFiguresPosition();


    bool isItCheck;
    bool isItCheckMate;
    bool whiteMove;       //checking whether its white or black time to play
    int numberOfMove;
    bool action;          //checking whether player click on the button for the first time(choosing figure) or for the second time(choosing place to move)


    //figures.cpp
    void getFigureName(QPushButton *button, bool enemyMoves = false);
    QString currentFigure; 
    void poonMovementWhite(QPushButton *button, bool enemyMoves=false,bool check=false);    //seperating those two functions to make code cleaner
    void poonMovementBlack(QPushButton *button, bool enemyMoves=false, bool check=false);
    void poonColision(QPushButton *button);
    void poonTaking(QPushButton *button, QString color="none",bool abstract = false);


    void knightMovement(QPushButton *button, bool enemyMoves=false,bool check=false);
    void bishopMovement(QPushButton *button, bool enemyMoves=false,bool check=false);
    void rookMovement(QPushButton *button, bool enemyMoves=false,bool check=false);
    void queenMovement(QPushButton *button, bool enemyMoves=false,bool check=false);
    void kingMovement(QPushButton *button, bool enemyMoves=false,bool check=false);
    void kingCastle();
    bool whiteCastleShort;
    bool whiteCastleLong;
    bool blackCastleShort;
    bool blackCastleLong;

    QString coords;
    QVector <QString> possibleMoves;
    QVector <QString> possibleMovesStorage;       // using in rook,queen and bishop functions to allow colision
    QVector <QString> abstractPossibleMoves;
    QVector <QString> protectingMoves;

    void pinnedMovement(QPushButton *button,QString color, bool enemyMoves, bool check= false);
    bool pinned;
    bool pinnedPoonStraight;
    int index;



    //moves
    void move(QPushButton *button, QString figure);
    void castleMove(QString side);
    void poonPromotion(QPushButton *button, QString figureColor);
    void enPassantMove(QPushButton *button, QString figure, QString cordNumber);
    bool enPassant;
    QString enPassantLeft;
    QString enPassantRight;

    void allPossibleMovesFromOpponentSide();
    QVector <QString> opponentPossibleMoves;
    QVector <QString> opponentPossibleMovesStorage;

    void blockMove(QString keyword);
    void goBack(QPushButton *button);
    QPushButton *currentFigureButton;       //cleaners
    QString currentFigureStyleSheet;



    //buttons-manipulations
    void pinnedFigues();
    QVector <QPushButton*> pinnedFigures;
    QVector <QPushButton*> attackingFigures;
    void isKingChecked(QPushButton *button);
    void isKingMated();
    int defendersCounter;
    void markKings();
    QVector <QString> checkingMoves;
    void colision(QPushButton *button, QString color="none", bool colisionWithOpponentPieces = false, bool isenemyMove = false);
    void abstractColision(QPushButton *button);
    void matchCoordinates();
    void showPermittedMoves(QPushButton *button);
    void convertStringToButton(QString coords);
    QPushButton *requiredButton;
    void checkIfThereIsAPiece(QPushButton *button, QString color="none");
    bool ifExist;
    void cleanCoordinates();
    void cleanCoordinates_shorter(QPushButton *button);
    void disableAllButons();
    void enableWhiteButtons();
    void enableBlackButtons();
    void enableWhiteButtons_shorter(QPushButton *button);
    void enableBlackButtons_shorter(QPushButton *button);
    void enableProtectingFigures();




    void switchPlayers(QPushButton *button);


    void whiteHistory(QPushButton *button);
    void blackHistory(QPushButton *button);
    QString matchHistory_white;
    QString matchHistory_black;
    QString matchHistory_numberOfMove;
    QString text;                                   //needed for match history and en passant move




    void on_any_button_clicked(QPushButton *button);

private slots:
    void on_startGameButton_clicked();      //others.cpp

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
