#include "widget.h"
#include "ui_widget.h"

void Widget::move(QPushButton *button, QString figure)
{
    if(button->font().bold() == true && currentFigureButton->font().bold() == true){                               //CASUAL MOVES
        button->setStyleSheet("background-image: url(:/img/"+figure+"-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }
    else if(button->font().bold() == false && currentFigureButton->font().bold() == true){
        button->setStyleSheet("background-image: url(:/img/"+figure+"-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }
    else if(button->font().bold() == true && currentFigureButton->font().bold() == false){
        button->setStyleSheet("background-image: url(:/img/"+figure+"-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }
    else if(button->font().bold() == false && currentFigureButton->font().bold() == false){
        button->setStyleSheet("background-image: url(:/img/"+figure+"-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }

    if(whiteMove){
        for(int i=0; i<whiteFiguresButtons.size();i++)                      //replacing position of piece in vector
        {
            if(currentFigureButton == whiteFiguresButtons.at(i))
            {
                whiteFiguresButtons.replace(i,button);
                break;
            }
        }

        for(int j=0; j<blackFiguresButtons.size();j++)                      //deleting piece from opponent vector if piece was taken
        {
            if(button== blackFiguresButtons.at(j))
            {
                blackFiguresButtons.replace(j,ui->empty);                   //using replacing instead of deleting to avoid index changes
                break;
            }
        }
    }
    else if(!whiteMove)
    {
        for(int i=0; i<blackFiguresButtons.size();i++)
        {
            if(currentFigureButton == blackFiguresButtons.at(i))
            {
                blackFiguresButtons.replace(i,button);
                break;
            }
        }

        for(int j=0; j<whiteFiguresButtons.size();j++)                      //deleting piece from opponent vector if piece was taken
        {
            if(button== whiteFiguresButtons.at(j))
            {
                whiteFiguresButtons.replace(j,ui->empty);                              //using replacing instead of deleting to avoid index changes
                break;
            }
        }
    }

}
void Widget::castleMove(QString side)
{
    if(whiteMove){
        if(side == "short"){
            ui->f1->setStyleSheet("background-image: url(:/img/whiteRook-greenField.png);");
            ui->g1->setStyleSheet("background-image: url(:/img/whiteKing-whiteField.png);");
            ui->h1->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
            ui->e1->setStyleSheet("background-color: white;\nborder: 1px solid black;");

            whiteFiguresButtons[15] = ui->g1;
            whiteFiguresButtons[13] = ui->f1;
        }
        else if(side == "long"){
            ui->a1->setStyleSheet("background-color: white;\nborder: 1px solid black;");
            ui->b1->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
            ui->c1->setStyleSheet("background-image: url(:/img/whiteKing-whiteField.png);");
            ui->d1->setStyleSheet("background-image: url(:/img/whiteRook-greenField.png);");
            ui->e1->setStyleSheet("background-color: white;\nborder: 1px solid black;");

            whiteFiguresButtons[15] = ui->c1;
            whiteFiguresButtons[12] = ui->d1;
        }

        whiteCastleLong = false;
        whiteCastleShort = false;
    }
    else if(!whiteMove){
        if(side == "short"){
            ui->f8->setStyleSheet("background-image: url(:/img/blackRook-whiteField.png);");
            ui->g8->setStyleSheet("background-image: url(:/img/blackKing-greenField.png);");
            ui->h8->setStyleSheet("background-color: white;\nborder: 1px solid black;");
            ui->e8->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");

            blackFiguresButtons[15] = ui->g8;
            blackFiguresButtons[13] = ui->f8;
        }
        else if(side == "long"){
            ui->a8->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
            ui->b8->setStyleSheet("background-color: white;\nborder: 1px solid black;");
            ui->c8->setStyleSheet("background-image: url(:/img/blackKing-greenField.png);");
            ui->d8->setStyleSheet("background-image: url(:/img/blackRook-whiteField.png);");
            ui->e8->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");

            blackFiguresButtons[15] = ui->c8;
            blackFiguresButtons[12] = ui->d8;
        }

        blackCastleLong = false;
        blackCastleShort = false;
    }
}
void Widget::enPassantMove(QPushButton *button, QString figure, QString cordNumber)
{
    if(button->font().bold() == true && currentFigureButton->font().bold() == true){
        button->setStyleSheet("background-image: url(:/img/"+figure+"-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
        convertStringToButton(button->objectName()[0]+cordNumber);
        requiredButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }
    else if(button->font().bold() == false && currentFigureButton->font().bold() == true){
        button->setStyleSheet("background-image: url(:/img/"+figure+"-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
        convertStringToButton(button->objectName()[0]+cordNumber);
        requiredButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }
    else if(button->font().bold() == true && currentFigureButton->font().bold() == false){
        button->setStyleSheet("background-image: url(:/img/"+figure+"-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
        convertStringToButton(button->objectName()[0]+cordNumber);
        requiredButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }
    else if(button->font().bold() == false && currentFigureButton->font().bold() == false){
        button->setStyleSheet("background-image: url(:/img/"+figure+"-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
        convertStringToButton(button->objectName()[0]+cordNumber);
        requiredButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }


    if(whiteMove){
        for(int i=0; i<whiteFiguresButtons.size();i++)                      //replacing position of piece in vector
        {
            if(currentFigureButton == whiteFiguresButtons.at(i))
            {
                whiteFiguresButtons.replace(i,button);
                break;
            }
        }

        for(int j=0; j<blackFiguresButtons.size();j++)                      //deleting piece from opponent vector if piece was taken
        {
            if(requiredButton == blackFiguresButtons.at(j))
            {
                blackFiguresButtons.replace(j,ui->empty);                   //using replacing instead of deleting to avoid index changes
                break;
            }
        }
    }
    else if(!whiteMove)
    {
        for(int i=0; i<blackFiguresButtons.size();i++)
        {
            if(currentFigureButton == blackFiguresButtons.at(i))
            {
                blackFiguresButtons.replace(i,button);
                break;
            }
        }

        for(int j=0; j<whiteFiguresButtons.size();j++)                      //deleting piece from opponent vector if piece was taken
        {
            if(requiredButton == whiteFiguresButtons.at(j))
            {
                whiteFiguresButtons.replace(j,ui->empty);                              //using replacing instead of deleting to avoid index changes
                break;
            }
        }
    }

    enPassantLeft = "";
    enPassantRight = "";
}
void Widget::allPossibleMovesFromOpponentSide()
{
    if(whiteMove)
    {
        for(int i=0; i<whiteFiguresButtons.size();i++){
            if(whiteFiguresButtons.at(i)->objectName()!="empty"){
                getFigureName(whiteFiguresButtons.at(i),true);

                if(currentFigure=="King"){
                   kingMovement(whiteFiguresButtons.at(i), true);
                } else if(currentFigure == "poon"){
                    poonMovementWhite(whiteFiguresButtons.at(i), true);
                } else if(currentFigure == "Knight"){
                    knightMovement(whiteFiguresButtons.at(i), true);
                } else if(currentFigure == "Bishop"){
                    bishopMovement(whiteFiguresButtons.at(i), true);
                } else if(currentFigure == "Rook"){
                    rookMovement(whiteFiguresButtons.at(i), true);
                } else if(currentFigure == "Queen"){
                    queenMovement(whiteFiguresButtons.at(i), true);
                }
            }
        }
        for(int i=0;i<opponentPossibleMoves.size();i++){

            for(int j=0;j<opponentPossibleMoves.size();j++){
                possibleMoves.clear();
                if(i!=j && opponentPossibleMoves.at(i)==opponentPossibleMoves.at(j)){
                    opponentPossibleMoves.remove(j);
                    i=0; j=0;
                }
            }
        }

        qDebug()<<opponentPossibleMoves.size();
        qDebug()<<"__________________________________";
    }
    else if(!whiteMove)
    {
        for(int i=0; i<blackFiguresButtons.size();i++){
            if(blackFiguresButtons.at(i)->objectName()!="empty"){
                getFigureName(blackFiguresButtons.at(i),true);

                if(currentFigure=="King"){
                   kingMovement(blackFiguresButtons.at(i), true);
                } else if(currentFigure == "poon"){
                    poonMovementBlack(blackFiguresButtons.at(i), true);
                } else if(currentFigure == "Knight"){
                    knightMovement(blackFiguresButtons.at(i), true);
                } else if(currentFigure == "Bishop"){
                    bishopMovement(blackFiguresButtons.at(i), true);
                } else if(currentFigure == "Rook"){
                    rookMovement(blackFiguresButtons.at(i), true);
                } else if(currentFigure == "Queen"){
                    queenMovement(blackFiguresButtons.at(i), true);
                }
            }
        }

        for(int i=0;i<opponentPossibleMoves.size();i++){



            for(int j=0;j<opponentPossibleMoves.size();j++){
                possibleMoves.clear();
                if(i!=j && opponentPossibleMoves.at(i)==opponentPossibleMoves.at(j)){
                    opponentPossibleMoves.remove(j);
                    i=0; j=0;
                }
            }
        }


        qDebug()<<opponentPossibleMoves.size();
        qDebug()<<"__________________________________";
    }

}

void Widget::poonPromotion(QPushButton *button, QString figureColor)
{

    if(button->font().bold() == true && currentFigureButton->font().bold()==true){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Queen-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }else if(button->font().bold() == true){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Queen-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }
    else if(button->font().bold() == false && currentFigureButton->font().bold()==false){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Queen-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }else if(button->font().bold() == false){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Queen-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }


    if(whiteMove){
        for(int i=0; i<whiteFiguresButtons.size();i++)                      //replacing position of piece in vector
        {
            if(currentFigureButton == whiteFiguresButtons.at(i))
            {
                whiteFiguresButtons.replace(i,ui->empty);
                whiteFiguresButtons.push_back(button);
                break;
            }
        }

        for(int j=0; j<blackFiguresButtons.size();j++)                      //deleting piece from opponent vector if piece was taken
        {
            if(requiredButton == blackFiguresButtons.at(j))
            {
                blackFiguresButtons.replace(j,ui->empty);                   //using replacing instead of deleting to avoid index changes
                break;
            }
        }
    }
    else if(!whiteMove)
    {
        for(int i=0; i<blackFiguresButtons.size();i++)
        {
            if(currentFigureButton == blackFiguresButtons.at(i))
            {
                blackFiguresButtons.replace(i,ui->empty);
                blackFiguresButtons.push_back(button);
                break;
            }
        }

        for(int j=0; j<whiteFiguresButtons.size();j++)                      //deleting piece from opponent vector if piece was taken
        {
            if(requiredButton == whiteFiguresButtons.at(j))
            {
                whiteFiguresButtons.replace(j,ui->empty);                              //using replacing instead of deleting to avoid index changes
                break;
            }
        }
    }
}
void Widget::blockMove(QString keyword)
{
    for(int i=0;i<possibleMoves.size();i++){
        if(possibleMoves.at(i)==keyword){
            possibleMoves.remove(i);
        }
    }
}
