#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    disableAllButons();

    setStartingParameters();
    placePiecesOnBoard();
    setFiguresPosition();
    qDebug()<<ui->startGameButton->isEnabled();
    ui->startGameButton->setEnabled(true);
}

void Widget::on_startGameButton_clicked(){
    ui->startGameButton->setEnabled(false);
    enableWhiteButtons();
}


void Widget::on_any_button_clicked(QPushButton *button)
{
    if(whiteMove) qDebug()<<whiteFiguresButtons;
    if(!action)                     //1st pressing
    {
        if(isItCheck){                      //GOTTA MOVE THAT LATER
            disableAllButons();
            enableProtectingFigures();
        }

        action=true;
        currentFigureButton=button;          //needed to clean the field after move

        getFigureName(button);              //setting currentFigure

        if(currentFigure=="King"){
           // kingMovement(button);
        } else if(currentFigure == "poon"){
           // poonMovement(button);
        } else if(currentFigure == "Knight"){
            knightMovement(button);
        } else if(currentFigure == "Bishop"){
           // bishopMovement(button);
        } else if(currentFigure == "Rook"){
           // rookMovement(button);
        } else if(currentFigure == "Queen"){
           // queenMovement(button);
        }
    }
    else if(action)                             //2nd pressing
    {
       action=false;
       cleanCoordinates();

       if(whiteMove)
       {
           if(currentFigure == "King")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   //move(button,"whiteKing");
                  // isKingChecked();
                  // switchPlayers("black",button);
               }
           }
           else if(currentFigure == "poon")
           {

           }
           else if (currentFigure == "Knight")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   move(button,"whiteKnight");
                   switchPlayers(button);
               }
           }
       }
       else if(!whiteMove)
       {
           if(currentFigure == "King")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   //move(button,"whiteKing");
                  // isKingChecked();
                  // switchPlayers("black",button);
               }
           }
           else if(currentFigure == "poon")
           {

           }
           else if (currentFigure == "Knight")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   move(button,"blackKnight");
                   switchPlayers(button);
               }
           }
       }
    }
}
