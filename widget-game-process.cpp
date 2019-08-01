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
    ui->startGameButton->setText("White move!");
    enableWhiteButtons();
}


void Widget::on_any_button_clicked(QPushButton *button)
{
    if(!action)                     //1st pressing
    {
        possibleMoves.clear();


        //qDebug()<<blackFiguresButtons;
        if(isItCheck){                      //GOTTA MOVE THAT LATER
            disableAllButons();
            enableProtectingFigures();
        }

        action=true;
        currentFigureButton=button;          //needed to clean the field after move
        currentFigureStyleSheet=button->styleSheet();

        getFigureName(button);              //setting currentFigure

        if(currentFigure=="King"){
           kingMovement(button);
        } else if(currentFigure == "poon"){
            if(whiteMove) poonMovementWhite(button);
            else if(!whiteMove) poonMovementBlack(button);
        } else if(currentFigure == "Knight"){
            knightMovement(button);
        } else if(currentFigure == "Bishop"){
            bishopMovement(button);
        } else if(currentFigure == "Rook"){
            rookMovement(button);
        } else if(currentFigure == "Queen"){
            queenMovement(button);
        }
    }
    else if(action)                             //2nd pressing
    {
       validMove = true;
       action=false;
       cleanCoordinates();

       if(whiteMove)
       {
           if(currentFigure == "King")
           {
               if(currentFigureButton == button){
                   goBack(button);
               }else if(button == ui->g1 && whiteCastleShort){
                   castleMove("short");
                   switchPlayers(button);
               }else if(button == ui->c1 && whiteCastleLong){
                   castleMove("long");
                   switchPlayers(button);
               }
               else{
                   whiteCastleLong = false;
                   whiteCastleShort = false;

                   move(button,"whiteKing");
                   switchPlayers(button);
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
                   poonPromotion(button,"white");
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
           else if (currentFigure == "Rook")
           {
               if(currentFigureButton == button){
                   goBack(button);
               }
               else {
                   if(currentFigureButton == whiteFiguresButtons[12]) whiteCastleLong = false;
                   else if(currentFigureButton == whiteFiguresButtons[13]) whiteCastleShort = false;

                   move(button,"whiteRook");
                   switchPlayers(button);
               }
           }
           else if (currentFigure == "Queen")
           {
               if(currentFigureButton == button){
                   goBack(button);
               }
               else {
                   move(button,"whiteQueen");
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
               }else if(button == ui->g8 && blackCastleShort){
                   castleMove("short");
                   switchPlayers(button);
               }else if(button == ui->c8 && blackCastleLong){
                   castleMove("long");
                   switchPlayers(button);
               }
               else{
                   blackCastleLong = false;
                   blackCastleShort = false;

                   move(button,"blackKing");
                   switchPlayers(button);
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
                   poonPromotion(button,"black");
                   switchPlayers(button);
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
           else if (currentFigure == "Bishop")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   move(button,"blackBishop");
                   switchPlayers(button);
               }
           }
           else if (currentFigure == "Rook")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   if(currentFigureButton == blackFiguresButtons[12]) blackCastleLong = false;
                   else if(currentFigureButton == blackFiguresButtons[13]) blackCastleShort = false;

                   move(button,"blackRook");
                   switchPlayers(button);
               }
           }
           else if (currentFigure == "Queen")
           {
               if(currentFigureButton == button){
                    goBack(button);
               }
               else {
                   move(button,"blackQueen");
                   switchPlayers(button);
               }
           }
       }
    }
}
