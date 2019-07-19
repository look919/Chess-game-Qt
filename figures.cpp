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
