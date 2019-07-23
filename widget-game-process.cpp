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

}

void Widget::on_startGameButton_clicked(){
    ui->startGameButton->setEnabled(false);
    enableWhiteButtons();
}


void Widget::on_any_button_clicked(QPushButton *button)
{
    if(!action)                     //1st pressing
    {
        if(numberOfMove == 7) qDebug()<<whiteFiguresButtons<<blackFiguresButtons;
        if(isItCheck){                      //GOTTA MOVE THAT LATER
            disableAllButons();
            enableProtectingFigures();
        }

        action=true;
        currentFigureButton=button;          //needed to clean the field after move
        currentFigureStyleSheet=button->styleSheet();

        getFigureName(button);              //setting currentFigure

        if(currentFigure=="King"){
           // kingMovement(button);
        } else if(currentFigure == "poon"){
            if(whiteMove) poonMovementWhite(button);
            else if(!whiteMove) poonMovementBlack(button);
        } else if(currentFigure == "Knight"){
            knightMovement(button);
        } else if(currentFigure == "Bishop"){
            bishopMovement(button);
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
                  // switchPlayers("black",button);
               }
           }
           else if(currentFigure == "poon")
           {
               if(currentFigureButton == button){
                   goBack(button);
               }
               else if(enPassant && (button->objectName() == enPassantLeft || button->objectName()==enPassantRight)){
                   enPassant = false;
                   enPassantMove(button,"whitePoon","5");
                   switchPlayers(button);
               }
               else if (button->objectName()[1]=="8") {
                   poonPromotion(button,"white");//to repair
                   switchPlayers(button);
               }
               else{
                   move(button,"whitePoon");
                   switchPlayers(button);
               }
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
           else if (currentFigure == "Bishop")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   move(button,"whiteBishop");
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
               if(currentFigureButton == button){
                    goBack(button);
               }else if(enPassant && (button->objectName() == enPassantLeft || button->objectName()==enPassantRight)){
                   enPassant = false;
                   enPassantMove(button,"blackPoon","4");
                   switchPlayers(button);
              }
               else if (button->objectName()[1]=="1") {
                  //todo
               }
               else {
                   move(button,"blackPoon");
                   switchPlayers(button);
               }
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
