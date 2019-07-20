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

void Widget::knightMovement(QPushButton *button)
{
    disableAllButons();

    QString left;                           //tracking position
    QString right;
    QString left_further;
    QString right_further;
    QString up;
    QString down;
    QString up_further;
    QString down_further;
    if(button->objectName()[0]=='a'){
        left="x";
        left_further="x";
        right="b";
        right_further="c";
    } else if(button->objectName()[0]=='b'){
        left="a";
        left_further="x";
        right="c";
        right_further="d";
    } else if(button->objectName()[0]=='c'){
        left="b";
        left_further="a";
        right="d";
        right_further="e";
    } else if(button->objectName()[0]=='d'){
        left="c";
        left_further="b";
        right="e";
        right_further="f";
    } else if(button->objectName()[0]=='e'){
        left="d";
        left_further="c";
        right="f";
        right_further="g";
    } else if(button->objectName()[0]=='f'){
        left="e";
        left_further="d";
        right="g";
        right_further="h";
    } else if(button->objectName()[0]=='g'){
        left="f";
        left_further="e";
        right="h";
        right_further="x";
    } else if(button->objectName()[0]=='h'){
        left="g";
        left_further="f";
        right="x";
        right_further="x";
    }
    if(button->objectName()[1]=='1'){
        up="2";
        up_further="3";
        down="x";
        down_further="x";
    } else if(button->objectName()[1]=='2'){
        up="3";
        up_further="4";
        down="1";
        down_further="x";
    } else if(button->objectName()[1]=='3'){
        up="4";
        up_further="5";
        down="2";
        down_further="1";
    } else if(button->objectName()[1]=='4'){
        up="5";
        up_further="6";
        down="3";
        down_further="2";
    } else if(button->objectName()[1]=='5'){
        up="6";
        up_further="7";
        down="4";
        down_further="3";
    } else if(button->objectName()[1]=='6'){
        up="7";
        up_further="8";
        down="5";
        down_further="4";
    } else if(button->objectName()[1]=='7'){
        up="8";
        up_further="x";
        down="6";
        down_further="5";
    } else if(button->objectName()[1]=='8'){
        up="x";
        up_further="x";
        down="7";
        down_further="6";
    }

    QString coords;
    coords=left+down_further;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }
    coords=left_further+down;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }
    coords=left_further+up;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }
    coords=left+up_further;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }
    coords=right+down_further;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }
    coords=right_further+down;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }
    coords=right_further+up;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }
    coords=right+up_further;
    if(coords[0]!='x' && coords[1]!='x'){
        //if pinned function
        possibleMoves.push_back(coords);
    }

    if(whiteMove)
    {
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/whiteKnight-blueField.png);");


    }
    else if(!whiteMove)
    {

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
