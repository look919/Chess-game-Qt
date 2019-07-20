#include "widget.h"
#include "ui_widget.h"

void Widget::getFigureName(QPushButton *button)
{
    if(whiteMove){                                          //WHITE
        for(int i=0; i<whiteFiguresButtons.size();i++){
            if(button == whiteFiguresButtons.at(i)){
                if(i<=7) currentFigure = "poon";            //getting info which piece is choosen
                else if(i<=9) currentFigure = "Knight";
                else if(i<=11) currentFigure = "Bishop";
                else if(i<=13) currentFigure = "Rook";
                else if(i<=14) currentFigure = "Queen";
                else if(i<=15) currentFigure = "King";
                break;
            }
        }
    }
    else{                                                   //BLACK
        for(int i=0; i<blackFiguresButtons.size();i++){
            if(button == blackFiguresButtons.at(i)){
                if(i<=7) currentFigure = "poon";             //getting info which piece is choosen
                else if(i<=9) currentFigure = "Knight";
                else if(i<=11) currentFigure = "Bishop";
                else if(i<=13) currentFigure = "Rook";
                else if(i<=14) currentFigure = "Queen";
                else if(i<=15) currentFigure = "King";
                break;
            }
        }
    }
}

void Widget::poonMovement(QPushButton *button)
{
    disableAllButons();                                      //disable all buttons in order to enable only permitted moves

    if(whiteMove)
    {
        button->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-blueField.png);"));
        button->setEnabled(true);

        if(button->objectName()[1]=="2"){

        }
    }

}

void Widget::renderFiguresPosition()
{
    if(whiteMove)
    {
        whiteFiguresButtons.clear();
        //whiteFiguresButtons
        whiteFiguresButtons.push_back(whitePoon1);
        whiteFiguresButtons.push_back(whitePoon2);
        whiteFiguresButtons.push_back(whitePoon3);
        whiteFiguresButtons.push_back(whitePoon4);
        whiteFiguresButtons.push_back(whitePoon5);
        whiteFiguresButtons.push_back(whitePoon6);
        whiteFiguresButtons.push_back(whitePoon7);
        whiteFiguresButtons.push_back(whitePoon8);
        whiteFiguresButtons.push_back(whiteKnight1);
        whiteFiguresButtons.push_back(whiteKnight2);
        whiteFiguresButtons.push_back(whiteBishop1);
        whiteFiguresButtons.push_back(whiteBishop2);
        whiteFiguresButtons.push_back(whiteRook1);
        whiteFiguresButtons.push_back(whiteRook2);
        whiteFiguresButtons.push_back(whiteQueen);
        whiteFiguresButtons.push_back(whiteKing);
    }
    else if(!whiteMove)
    {
        blackFiguresButtons.clear();
        //blackFiguresButtons
        blackFiguresButtons.push_back(blackPoon1);
        blackFiguresButtons.push_back(blackPoon2);
        blackFiguresButtons.push_back(blackPoon3);
        blackFiguresButtons.push_back(blackPoon4);
        blackFiguresButtons.push_back(blackPoon5);
        blackFiguresButtons.push_back(blackPoon6);
        blackFiguresButtons.push_back(blackPoon7);
        blackFiguresButtons.push_back(blackPoon8);
        blackFiguresButtons.push_back(blackKnight1);
        blackFiguresButtons.push_back(blackKnight2);
        blackFiguresButtons.push_back(blackBishop1);
        blackFiguresButtons.push_back(blackBishop2);
        blackFiguresButtons.push_back(blackRook1);
        blackFiguresButtons.push_back(blackRook2);
        blackFiguresButtons.push_back(blackQueen);
        blackFiguresButtons.push_back(blackKing);
    }
}
