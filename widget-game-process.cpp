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
    renderFiguresPosition();
}

void Widget::on_startGameButton_clicked(){
    ui->startGameButton->setEnabled(false);
    enableWhiteButtons();
}


void Widget::on_any_button_clicked(QPushButton *button)
{
    if(!action)                     //1st pressing
    {
        if(isItCheck){                      //if we have check on the board, pieces that cannot help are blocked
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
    }
}
