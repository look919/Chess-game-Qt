#include "widget.h"
#include "ui_widget.h"



void Widget::colision(QPushButton *button, QString color, bool colisionWithOpponentPieces, bool enemyMoves)
{
    if(currentFigure=="Knight"|| currentFigure=="King"){
        for(int i=0; i<possibleMoves.size();i++){

           convertStringToButton(possibleMoves.at(i));
           checkIfThereIsAPiece(requiredButton,color);

           if(ifExist==true){
               possibleMoves.remove(i);
               i-=1;
               ifExist=false;
           }
        }
        button->setEnabled(true);
    }
    else if((currentFigure=="Bishop"|| currentFigure=="Rook" || currentFigure=="Queen"))
    {
        bool blocking=false;

        for(int i=0; i<possibleMoves.size();i++){
            if(blocking==false){
                convertStringToButton(possibleMoves.at(i));
                if(enemyMoves == false) checkIfThereIsAPiece(requiredButton,color);

                if(ifExist==true){
                    possibleMoves.remove(i);
                    blocking=true;
                    i-=1;
                    ifExist=false;
                }else{
                    if(colisionWithOpponentPieces==true){
                        if(color == "white"){

                            checkIfThereIsAPiece(requiredButton,"black");                      //WHITE

                            if(ifExist==true){
                                blocking=true;
                                ifExist=false;
                            }
                            if(enemyMoves == true){
                                checkIfThereIsAPiece(requiredButton,"white");

                                if(ifExist==true){
                                    blocking=true;
                                    ifExist=false;
                                }
                            }
                        } else if(color == "black"){

                            checkIfThereIsAPiece(requiredButton,"white");                      //WHITE

                            if(ifExist==true){
                                blocking=true;
                                ifExist=false;
                            }
                            if(enemyMoves == true){
                                checkIfThereIsAPiece(requiredButton,"black");

                                if(ifExist==true){
                                    blocking=true;
                                    ifExist=false;
                                }
                            }
                        }
                    }
               }

            }
            else{

                if(coords=="up" || coords == "down"){
                        while(possibleMoves.at(i)[1]!='1' && possibleMoves.at(i)[1]!='8'){
                            possibleMoves.remove(i);
                        }
                        if(possibleMoves.at(i)[1]!='1' || possibleMoves.at(i)[1]!='8') possibleMoves.remove(i);
                        blocking=false;
                }
                else if(coords=="left" || coords == "right"){
                    while(possibleMoves.at(i)[0]!='a' && possibleMoves.at(i)[0]!='h'){
                        if(i>=possibleMoves.size()-1) break;                                            //VERY IMPORTANT STUFF IN BISHOP MOVEMENT
                            possibleMoves.remove(i);
                        }
                        if(possibleMoves.at(i)[0]!='a' || possibleMoves.at(i)[0]!='h') possibleMoves.remove(i);
                        blocking=false;
                    }

            }
        }
        for(int i=0; i<possibleMoves.size();i++){
            possibleMovesStorage.push_back(possibleMoves.at(i));           //coping valid moves to memory
        }
        possibleMoves.clear();
    }

}

void Widget::abstractColision(QPushButton *button)
{
    bool enemyKing = false;
    int pinnedCounter =0;

    if(whiteMove)
    {
        for(int i=0;i<abstractPossibleMoves.size();i++){
            convertStringToButton(abstractPossibleMoves.at(i));
            if(requiredButton == blackFiguresButtons[15]){
                enemyKing = true;
                break;
            }
        }

        if(enemyKing){
            for(int i=0;i<abstractPossibleMoves.size();i++){
                convertStringToButton(abstractPossibleMoves.at(i));

                if(requiredButton != blackFiguresButtons[15]){                          // if abstract move is diffrent than enemy king position
                    for(int j=0; j<blackFiguresButtons.size();j++){
                        if(requiredButton == blackFiguresButtons.at(j)){
                            if(pinnedCounter == 0){
                                pinnedCounter++;
                                pinnedFigures.push_back(blackFiguresButtons.at(j));
                                attackingFigures.push_back(button);
                            }
                            else if(pinnedCounter != 0){
                                attackingFigures.pop_back();                            //deleting element that was added trought this loop
                                pinnedFigures.pop_back();
                            }
                        }
                    }
                }
                else{                                                                   //if we achieve king - break the loop
                    break;
                }
            }
        }

    }
    else if(!whiteMove)
    {
        for(int i=0;i<abstractPossibleMoves.size();i++){
            convertStringToButton(abstractPossibleMoves.at(i));
            if(requiredButton == whiteFiguresButtons[15]){
                enemyKing = true;
                break;
            }
        }

        if(enemyKing){
            for(int i=0;i<abstractPossibleMoves.size();i++){
                convertStringToButton(abstractPossibleMoves.at(i));

                if(requiredButton != whiteFiguresButtons[15]){                          // if abstract move is diffrent than enemy king position
                    for(int j=0; j<whiteFiguresButtons.size();j++){
                        if(requiredButton == whiteFiguresButtons.at(j)){
                            if(pinnedCounter == 0){
                                pinnedCounter++;
                                pinnedFigures.push_back(whiteFiguresButtons.at(j));
                                attackingFigures.push_back(button);
                            }
                            else if(pinnedCounter != 0){
                                attackingFigures.pop_back();                            //deleting element that was added trought this loop
                                pinnedFigures.pop_back();
                            }
                        }
                    }
                }
                else{                                                                   //if we achieve king - break the loop
                    break;
                }
            }
        }
    }

}
void Widget::checkIfThereIsAPiece(QPushButton *button, QString color)
{
    ifExist = false;
    if(color == "none")
    {
        for(int i=0;i<blackFiguresButtons.size();i++){
            if(button == blackFiguresButtons.at(i)){
                ifExist=true;
                break;
            }
        }
        for(int i=0;i<whiteFiguresButtons.size();i++){
            if(button == whiteFiguresButtons.at(i)){
                ifExist=true;
                break;
            }
        }
    }
    else if(color=="white")
    {
        for(int i=0;i<whiteFiguresButtons.size();i++){
            if(button == whiteFiguresButtons.at(i)){
                ifExist=true;
                break;
            }
        }
    }
    else if(color=="black"){
        for(int i=0;i<blackFiguresButtons.size();i++){
            if(button == blackFiguresButtons.at(i)){
                ifExist=true;
                break;
            }
        }
    }
}
void Widget::convertStringToButton(QString coords)
{
    requiredButton = nullptr;
    if     (ui->a1->objectName()==coords)     requiredButton=ui->a1;
    else if(ui->b1->objectName()==coords)     requiredButton=ui->b1;
    else if(ui->c1->objectName()==coords)     requiredButton=ui->c1;
    else if(ui->d1->objectName()==coords)     requiredButton=ui->d1;
    else if(ui->e1->objectName()==coords)     requiredButton=ui->e1;
    else if(ui->f1->objectName()==coords)     requiredButton=ui->f1;
    else if(ui->g1->objectName()==coords)     requiredButton=ui->g1;
    else if(ui->h1->objectName()==coords)     requiredButton=ui->h1;
    else if(ui->a2->objectName()==coords)     requiredButton=ui->a2;
    else if(ui->b2->objectName()==coords)     requiredButton=ui->b2;
    else if(ui->c2->objectName()==coords)     requiredButton=ui->c2;
    else if(ui->d2->objectName()==coords)     requiredButton=ui->d2;
    else if(ui->e2->objectName()==coords)     requiredButton=ui->e2;
    else if(ui->f2->objectName()==coords)     requiredButton=ui->f2;
    else if(ui->g2->objectName()==coords)     requiredButton= ui->g2;
    else if(ui->h2->objectName()==coords)     requiredButton= ui->h2;
    else if(ui->a3->objectName()==coords)     requiredButton= ui->a3;
    else if(ui->b3->objectName()==coords)     requiredButton= ui->b3;
    else if(ui->c3->objectName()==coords)     requiredButton= ui->c3;
    else if(ui->d3->objectName()==coords)     requiredButton= ui->d3;
    else if(ui->e3->objectName()==coords)     requiredButton= ui->e3;
    else if(ui->f3->objectName()==coords)     requiredButton= ui->f3;
    else if(ui->g3->objectName()==coords)     requiredButton= ui->g3;
    else if(ui->h3->objectName()==coords)     requiredButton= ui->h3;
    else if(ui->a4->objectName()==coords)     requiredButton= ui->a4;
    else if(ui->b4->objectName()==coords)     requiredButton= ui->b4;
    else if(ui->c4->objectName()==coords)     requiredButton= ui->c4;
    else if(ui->d4->objectName()==coords)     requiredButton= ui->d4;
    else if(ui->e4->objectName()==coords)     requiredButton= ui->e4;
    else if(ui->f4->objectName()==coords)     requiredButton= ui->f4;
    else if(ui->g4->objectName()==coords)     requiredButton= ui->g4;
    else if(ui->h4->objectName()==coords)     requiredButton= ui->h4;
    else if(ui->a5->objectName()==coords)     requiredButton= ui->a5;
    else if(ui->b5->objectName()==coords)     requiredButton= ui->b5;
    else if(ui->c5->objectName()==coords)     requiredButton= ui->c5;
    else if(ui->d5->objectName()==coords)     requiredButton= ui->d5;
    else if(ui->e5->objectName()==coords)     requiredButton= ui->e5;
    else if(ui->f5->objectName()==coords)     requiredButton= ui->f5;
    else if(ui->g5->objectName()==coords)     requiredButton= ui->g5;
    else if(ui->h5->objectName()==coords)     requiredButton= ui->h5;
    else if(ui->a6->objectName()==coords)     requiredButton= ui->a6;
    else if(ui->b6->objectName()==coords)     requiredButton= ui->b6;
    else if(ui->c6->objectName()==coords)     requiredButton= ui->c6;
    else if(ui->d6->objectName()==coords)     requiredButton= ui->d6;
    else if(ui->e6->objectName()==coords)     requiredButton= ui->e6;
    else if(ui->f6->objectName()==coords)     requiredButton= ui->f6;
    else if(ui->g6->objectName()==coords)     requiredButton= ui->g6;
    else if(ui->h6->objectName()==coords)     requiredButton= ui->h6;
    else if(ui->a7->objectName()==coords)     requiredButton= ui->a7;
    else if(ui->b7->objectName()==coords)     requiredButton= ui->b7;
    else if(ui->c7->objectName()==coords)     requiredButton= ui->c7;
    else if(ui->d7->objectName()==coords)     requiredButton= ui->d7;
    else if(ui->e7->objectName()==coords)     requiredButton= ui->e7;
    else if(ui->f7->objectName()==coords)     requiredButton= ui->f7;
    else if(ui->g7->objectName()==coords)     requiredButton= ui->g7;
    else if(ui->h7->objectName()==coords)     requiredButton= ui->h7;
    else if(ui->a8->objectName()==coords)     requiredButton= ui->a8;
    else if(ui->b8->objectName()==coords)     requiredButton= ui->b8;
    else if(ui->c8->objectName()==coords)     requiredButton= ui->c8;
    else if(ui->d8->objectName()==coords)     requiredButton= ui->d8;
    else if(ui->e8->objectName()==coords)     requiredButton= ui->e8;
    else if(ui->f8->objectName()==coords)     requiredButton= ui->f8;
    else if(ui->g8->objectName()==coords)     requiredButton= ui->g8;
    else if(ui->h8->objectName()==coords)     requiredButton= ui->h8;
}
void Widget::cleanCoordinates()     //brings back the right background color from blue after move;
{
    for(int i=0;i<possibleMoves.size();i++){

    if(ui->a1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a1);
    }
    else if(ui->b1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b1);
    }
    else if(ui->c1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c1);
    }
    else if(ui->d1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d1);
    }
    else if(ui->e1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e1);
    }
    else if(ui->f1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f1);
    }
    else if(ui->g1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g1);
    }
    else if(ui->h1->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h1);
    }
    else if(ui->a2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a2);
    }
    else if(ui->b2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b2);
    }
    else if(ui->c2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c2);
    }
    else if(ui->d2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d2);
    }
    else if(ui->e2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e2);
    }
    else if(ui->f2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f2);
    }
    else if(ui->g2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g2);
    }
    else if(ui->h2->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h2);
    }
    else if(ui->a3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a3);
    }
    else if(ui->b3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b3);
    }
    else if(ui->c3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c3);
    }
    else if(ui->d3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d3);
    }
    else if(ui->e3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e3);
    }
    else if(ui->f3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f3);
    }
    else if(ui->g3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g3);
    }
    else if(ui->h3->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h3);
    }
    else if(ui->a4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a4);
    }
    else if(ui->b4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b4);
    }
    else if(ui->c4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c4);
    }
    else if(ui->d4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d4);
    }
    else if(ui->e4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e4);
    }
    else if(ui->f4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f4);
    }
    else if(ui->g4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g4);
    }
    else if(ui->h4->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h4);
    }
    else if(ui->a5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a5);
    }
    else if(ui->b5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b5);
    }
    else if(ui->c5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c5);
    }
    else if(ui->d5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d5);
    }
    else if(ui->e5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e5);
    }
    else if(ui->f5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f5);
    }
    else if(ui->g5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g5);
    }
    else if(ui->h5->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h5);
    }
    else if(ui->a6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a6);
    }
    else if(ui->b6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b6);
    }
    else if(ui->c6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c6);
    }
    else if(ui->d6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d6);
    }
    else if(ui->e6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e6);
    }
    else if(ui->f6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f6);
    }
    else if(ui->g6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g6);
    }
    else if(ui->h6->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h6);
    }
    else if(ui->a7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a7);
    }
    else if(ui->b7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b7);
    }
    else if(ui->c7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c7);
    }
    else if(ui->d7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d7);
    }
    else if(ui->e7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e7);
    }
    else if(ui->f7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f7);
    }
    else if(ui->g7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g7);
    }
    else if(ui->h7->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h7);
    }
    else if(ui->a8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->a8);
    }
    else if(ui->b8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->b8);
    }
    else if(ui->c8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->c8);
    }
    else if(ui->d8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->d8);
    }
    else if(ui->e8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->e8);
    }
    else if(ui->f8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->f8);
    }
    else if(ui->g8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->g8);
    }
    else if(ui->h8->objectName()==possibleMoves.at(i)){
        cleanCoordinates_shorter(ui->h8);
    }

}

}
void Widget::cleanCoordinates_shorter(QPushButton *button)
{
    if(button->styleSheet()=="background-color: #7092be;\nborder: 1px solid black;" && button->font().bold()==true){        //GREEN FIELD
        button->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }
    else if(button->styleSheet()=="background-color: #7092be;\nborder: 1px solid black;"){                                  //WHITE FIELD
        button->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }

    else if(button->styleSheet()=="background-image: url(:/img/whitePoon-blueField.png);" && button->font().bold()==true){  //POONS
        button->setStyleSheet("background-image: url(:/img/whitePoon-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whitePoon-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/whitePoon-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackPoon-blueField.png);" && button->font().bold()==true){
        button->setStyleSheet("background-image: url(:/img/blackPoon-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackPoon-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/blackPoon-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteBishop-blueField.png);" && button->font().bold()==true){  //BISHOPS
        button->setStyleSheet("background-image: url(:/img/whiteBishop-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteBishop-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/whiteBishop-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackBishop-blueField.png);" && button->font().bold()==true){
        button->setStyleSheet("background-image: url(:/img/blackBishop-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackBishop-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/blackBishop-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteKnight-blueField.png);" && button->font().bold()==true){  //KNIGHTS
        button->setStyleSheet("background-image: url(:/img/whiteKnight-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteKnight-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/whiteKnight-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackKnight-blueField.png);" && button->font().bold()==true){
        button->setStyleSheet("background-image: url(:/img/blackKnight-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackKnight-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/blackKnight-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteRook-blueField.png);" && button->font().bold()==true){  //ROOKS
        button->setStyleSheet("background-image: url(:/img/whiteRook-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteRook-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/whiteRook-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackRook-blueField.png);" && button->font().bold()==true){
        button->setStyleSheet("background-image: url(:/img/blackRook-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackRook-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/blackRook-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteQueen-blueField.png);" && button->font().bold()==true){  //QUEEN
        button->setStyleSheet("background-image: url(:/img/whiteQueen-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteQueen-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/whiteQueen-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackQueen-blueField.png);" && button->font().bold()==true){
        button->setStyleSheet("background-image: url(:/img/blackQueen-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackQueen-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/blackQueen-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteKing-blueField.png);" && button->font().bold()==true){  //KING
        button->setStyleSheet("background-image: url(:/img/whiteKing-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/whiteKing-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/whiteKing-whiteField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackKing-blueField.png);" && button->font().bold()==true){
        button->setStyleSheet("background-image: url(:/img/blackKing-greenField.png);");
    }
    else if(button->styleSheet()=="background-image: url(:/img/blackKing-blueField.png);"){
        button->setStyleSheet("background-image: url(:/img/blackKing-whiteField.png);");
    }
}

void Widget::goBack(QPushButton *button)
{
    disableAllButons();
    if(whiteMove) enableWhiteButtons();
    else if(!whiteMove) enableBlackButtons();

    possibleMoves.clear();
    possibleMovesStorage.clear();
    cleanCoordinates();
    button->setStyleSheet(currentFigureStyleSheet);
    currentFigureStyleSheet = "";
}




void Widget::disableAllButons()
{
    ui->a1->setEnabled(false);
    ui->b1->setEnabled(false);
    ui->c1->setEnabled(false);
    ui->d1->setEnabled(false);
    ui->e1->setEnabled(false);
    ui->f1->setEnabled(false);
    ui->g1->setEnabled(false);
    ui->h1->setEnabled(false);
    ui->a2->setEnabled(false);
    ui->b2->setEnabled(false);
    ui->c2->setEnabled(false);
    ui->d2->setEnabled(false);
    ui->e2->setEnabled(false);
    ui->f2->setEnabled(false);
    ui->g2->setEnabled(false);
    ui->h2->setEnabled(false);
    ui->a3->setEnabled(false);
    ui->b3->setEnabled(false);
    ui->c3->setEnabled(false);
    ui->d3->setEnabled(false);
    ui->e3->setEnabled(false);
    ui->f3->setEnabled(false);
    ui->g3->setEnabled(false);
    ui->h3->setEnabled(false);
    ui->a4->setEnabled(false);
    ui->b4->setEnabled(false);
    ui->c4->setEnabled(false);
    ui->d4->setEnabled(false);
    ui->e4->setEnabled(false);
    ui->f4->setEnabled(false);
    ui->g4->setEnabled(false);
    ui->h4->setEnabled(false);
    ui->a5->setEnabled(false);
    ui->b5->setEnabled(false);
    ui->c5->setEnabled(false);
    ui->d5->setEnabled(false);
    ui->e5->setEnabled(false);
    ui->f5->setEnabled(false);
    ui->g5->setEnabled(false);
    ui->h5->setEnabled(false);
    ui->a6->setEnabled(false);
    ui->b6->setEnabled(false);
    ui->c6->setEnabled(false);
    ui->d6->setEnabled(false);
    ui->e6->setEnabled(false);
    ui->f6->setEnabled(false);
    ui->g6->setEnabled(false);
    ui->h6->setEnabled(false);
    ui->a7->setEnabled(false);
    ui->b7->setEnabled(false);
    ui->c7->setEnabled(false);
    ui->d7->setEnabled(false);
    ui->e7->setEnabled(false);
    ui->f7->setEnabled(false);
    ui->g7->setEnabled(false);
    ui->h7->setEnabled(false);
    ui->a8->setEnabled(false);
    ui->b8->setEnabled(false);
    ui->c8->setEnabled(false);
    ui->d8->setEnabled(false);
    ui->e8->setEnabled(false);
    ui->f8->setEnabled(false);
    ui->g8->setEnabled(false);
    ui->h8->setEnabled(false);
}
void Widget::enableWhiteButtons()
{
   enableWhiteButtons_shorter(ui->a1);
   enableWhiteButtons_shorter(ui->b1);
   enableWhiteButtons_shorter(ui->c1);
   enableWhiteButtons_shorter(ui->d1);
   enableWhiteButtons_shorter(ui->e1);
   enableWhiteButtons_shorter(ui->f1);
   enableWhiteButtons_shorter(ui->g1);
   enableWhiteButtons_shorter(ui->h1);
   enableWhiteButtons_shorter(ui->a2);
   enableWhiteButtons_shorter(ui->b2);
   enableWhiteButtons_shorter(ui->c2);
   enableWhiteButtons_shorter(ui->d2);
   enableWhiteButtons_shorter(ui->e2);
   enableWhiteButtons_shorter(ui->f2);
   enableWhiteButtons_shorter(ui->g2);
   enableWhiteButtons_shorter(ui->h2);
   enableWhiteButtons_shorter(ui->a3);
   enableWhiteButtons_shorter(ui->b3);
   enableWhiteButtons_shorter(ui->c3);
   enableWhiteButtons_shorter(ui->d3);
   enableWhiteButtons_shorter(ui->e3);
   enableWhiteButtons_shorter(ui->f3);
   enableWhiteButtons_shorter(ui->g3);
   enableWhiteButtons_shorter(ui->h3);
   enableWhiteButtons_shorter(ui->a4);
   enableWhiteButtons_shorter(ui->b4);
   enableWhiteButtons_shorter(ui->c4);
   enableWhiteButtons_shorter(ui->d4);
   enableWhiteButtons_shorter(ui->e4);
   enableWhiteButtons_shorter(ui->f4);
   enableWhiteButtons_shorter(ui->g4);
   enableWhiteButtons_shorter(ui->h4);
   enableWhiteButtons_shorter(ui->a5);
   enableWhiteButtons_shorter(ui->b5);
   enableWhiteButtons_shorter(ui->c5);
   enableWhiteButtons_shorter(ui->d5);
   enableWhiteButtons_shorter(ui->e5);
   enableWhiteButtons_shorter(ui->f5);
   enableWhiteButtons_shorter(ui->g5);
   enableWhiteButtons_shorter(ui->h5);
   enableWhiteButtons_shorter(ui->a6);
   enableWhiteButtons_shorter(ui->b6);
   enableWhiteButtons_shorter(ui->c6);
   enableWhiteButtons_shorter(ui->d6);
   enableWhiteButtons_shorter(ui->e6);
   enableWhiteButtons_shorter(ui->f6);
   enableWhiteButtons_shorter(ui->g6);
   enableWhiteButtons_shorter(ui->h6);
   enableWhiteButtons_shorter(ui->a7);
   enableWhiteButtons_shorter(ui->b7);
   enableWhiteButtons_shorter(ui->c7);
   enableWhiteButtons_shorter(ui->d7);
   enableWhiteButtons_shorter(ui->e7);
   enableWhiteButtons_shorter(ui->f7);
   enableWhiteButtons_shorter(ui->g7);
   enableWhiteButtons_shorter(ui->h7);
   enableWhiteButtons_shorter(ui->a8);
   enableWhiteButtons_shorter(ui->b8);
   enableWhiteButtons_shorter(ui->c8);
   enableWhiteButtons_shorter(ui->d8);
   enableWhiteButtons_shorter(ui->e8);
   enableWhiteButtons_shorter(ui->f8);
   enableWhiteButtons_shorter(ui->g8);
   enableWhiteButtons_shorter(ui->h8);
}
void Widget::enableBlackButtons()
{
    enableBlackButtons_shorter(ui->a1);
    enableBlackButtons_shorter(ui->b1);
    enableBlackButtons_shorter(ui->c1);
    enableBlackButtons_shorter(ui->d1);
    enableBlackButtons_shorter(ui->e1);
    enableBlackButtons_shorter(ui->f1);
    enableBlackButtons_shorter(ui->g1);
    enableBlackButtons_shorter(ui->h1);
    enableBlackButtons_shorter(ui->a2);
    enableBlackButtons_shorter(ui->b2);
    enableBlackButtons_shorter(ui->c2);
    enableBlackButtons_shorter(ui->d2);
    enableBlackButtons_shorter(ui->e2);
    enableBlackButtons_shorter(ui->f2);
    enableBlackButtons_shorter(ui->g2);
    enableBlackButtons_shorter(ui->a3);
    enableBlackButtons_shorter(ui->b3);
    enableBlackButtons_shorter(ui->c3);
    enableBlackButtons_shorter(ui->d3);
    enableBlackButtons_shorter(ui->e3);
    enableBlackButtons_shorter(ui->f3);
    enableBlackButtons_shorter(ui->g3);
    enableBlackButtons_shorter(ui->h3);
    enableBlackButtons_shorter(ui->a4);
    enableBlackButtons_shorter(ui->b4);
    enableBlackButtons_shorter(ui->c4);
    enableBlackButtons_shorter(ui->d4);
    enableBlackButtons_shorter(ui->e4);
    enableBlackButtons_shorter(ui->f4);
    enableBlackButtons_shorter(ui->g4);
    enableBlackButtons_shorter(ui->h4);
    enableBlackButtons_shorter(ui->a5);
    enableBlackButtons_shorter(ui->b5);
    enableBlackButtons_shorter(ui->c5);
    enableBlackButtons_shorter(ui->d5);
    enableBlackButtons_shorter(ui->e5);
    enableBlackButtons_shorter(ui->f5);
    enableBlackButtons_shorter(ui->g5);
    enableBlackButtons_shorter(ui->h5);
    enableBlackButtons_shorter(ui->a6);
    enableBlackButtons_shorter(ui->b6);
    enableBlackButtons_shorter(ui->c6);
    enableBlackButtons_shorter(ui->d6);
    enableBlackButtons_shorter(ui->e6);
    enableBlackButtons_shorter(ui->f6);
    enableBlackButtons_shorter(ui->g6);
    enableBlackButtons_shorter(ui->h6);
    enableBlackButtons_shorter(ui->a7);
    enableBlackButtons_shorter(ui->b7);
    enableBlackButtons_shorter(ui->c7);
    enableBlackButtons_shorter(ui->d7);
    enableBlackButtons_shorter(ui->e7);
    enableBlackButtons_shorter(ui->f7);
    enableBlackButtons_shorter(ui->g7);
    enableBlackButtons_shorter(ui->h7);
    enableBlackButtons_shorter(ui->a8);
    enableBlackButtons_shorter(ui->b8);
    enableBlackButtons_shorter(ui->c8);
    enableBlackButtons_shorter(ui->d8);
    enableBlackButtons_shorter(ui->e8);
    enableBlackButtons_shorter(ui->f8);
    enableBlackButtons_shorter(ui->g8);
    enableBlackButtons_shorter(ui->h8);
}

void Widget::enableWhiteButtons_shorter(QPushButton *button)
{
    for(int i=0; i<whiteFiguresButtons.size();i++){
        if(button == whiteFiguresButtons.at(i)){
            button->setEnabled(true);
            break;
        }
    }
}
void Widget::enableBlackButtons_shorter(QPushButton *button)
{
    for(int i=0; i<blackFiguresButtons.size();i++){
        if(button == blackFiguresButtons.at(i)){
            button->setEnabled(true);
            break;
        }
    }
}

void Widget::enableProtectingFigures()
{

}


void Widget::matchCoordinates()                             //function that enable permitted moves buttons
{
    for(int i=0;i<possibleMoves.size();i++){
        if(ui->a1->objectName()==possibleMoves.at(i)){
            ui->a1->setEnabled(true);
            showPermittedMoves(ui->a1);
        }
        else if(ui->b1->objectName()==possibleMoves.at(i)){
            ui->b1->setEnabled(true);
            showPermittedMoves(ui->b1);
        }
        else if(ui->c1->objectName()==possibleMoves.at(i)){
            ui->c1->setEnabled(true);
            showPermittedMoves(ui->c1);
        }
        else if(ui->d1->objectName()==possibleMoves.at(i)){
            ui->d1->setEnabled(true);
            showPermittedMoves(ui->d1);
        }
        else if(ui->e1->objectName()==possibleMoves.at(i)){
            ui->e1->setEnabled(true);
            showPermittedMoves(ui->e1);
        }
        else if(ui->f1->objectName()==possibleMoves.at(i)){
            ui->f1->setEnabled(true);
            showPermittedMoves(ui->f1);
        }
        else if(ui->g1->objectName()==possibleMoves.at(i)){
            ui->g1->setEnabled(true);
            showPermittedMoves(ui->g1);
        }
        else if(ui->h1->objectName()==possibleMoves.at(i)){
            ui->h1->setEnabled(true);
            showPermittedMoves(ui->h1);
        }
        else if(ui->a2->objectName()==possibleMoves.at(i)){
            ui->a2->setEnabled(true);
            showPermittedMoves(ui->a2);
        }
        else if(ui->b2->objectName()==possibleMoves.at(i)){
            ui->b2->setEnabled(true);
            showPermittedMoves(ui->b2);
        }
        else if(ui->c2->objectName()==possibleMoves.at(i)){
            ui->c2->setEnabled(true);
            showPermittedMoves(ui->c2);
        }
        else if(ui->d2->objectName()==possibleMoves.at(i)){
            ui->d2->setEnabled(true);
            showPermittedMoves(ui->d2);
        }
        else if(ui->e2->objectName()==possibleMoves.at(i)){
            ui->e2->setEnabled(true);
            showPermittedMoves(ui->e2);
        }
        else if(ui->f2->objectName()==possibleMoves.at(i)){
            ui->f2->setEnabled(true);
            showPermittedMoves(ui->f2);
        }
        else if(ui->g2->objectName()==possibleMoves.at(i)){
            ui->g2->setEnabled(true);
            showPermittedMoves(ui->g2);
        }
        else if(ui->h2->objectName()==possibleMoves.at(i)){
            ui->h2->setEnabled(true);
            showPermittedMoves(ui->h2);
        }
        else if(ui->a3->objectName()==possibleMoves.at(i)){
            ui->a3->setEnabled(true);
            showPermittedMoves(ui->a3);
        }
        else if(ui->b3->objectName()==possibleMoves.at(i)){
            ui->b3->setEnabled(true);
            showPermittedMoves(ui->b3);
        }
        else if(ui->c3->objectName()==possibleMoves.at(i)){
            ui->c3->setEnabled(true);
            showPermittedMoves(ui->c3);
        }
        else if(ui->d3->objectName()==possibleMoves.at(i)){
            ui->d3->setEnabled(true);
            showPermittedMoves(ui->d3);
        }
        else if(ui->e3->objectName()==possibleMoves.at(i)){
            ui->e3->setEnabled(true);
            showPermittedMoves(ui->e3);
        }
        else if(ui->f3->objectName()==possibleMoves.at(i)){
            ui->f3->setEnabled(true);
            showPermittedMoves(ui->f3);
        }
        else if(ui->g3->objectName()==possibleMoves.at(i)){
            ui->g3->setEnabled(true);
            showPermittedMoves(ui->g3);
        }
        else if(ui->h3->objectName()==possibleMoves.at(i)){
            ui->h3->setEnabled(true);
            showPermittedMoves(ui->h3);
        }
        else if(ui->a4->objectName()==possibleMoves.at(i)){
            ui->a4->setEnabled(true);
            showPermittedMoves(ui->a4);
        }
        else if(ui->b4->objectName()==possibleMoves.at(i)){
            ui->b4->setEnabled(true);
            showPermittedMoves(ui->b4);
        }
        else if(ui->c4->objectName()==possibleMoves.at(i)){
            ui->c4->setEnabled(true);
            showPermittedMoves(ui->c4);
        }
        else if(ui->d4->objectName()==possibleMoves.at(i)){
            ui->d4->setEnabled(true);
            showPermittedMoves(ui->d4);
        }
        else if(ui->e4->objectName()==possibleMoves.at(i)){
            ui->e4->setEnabled(true);
            showPermittedMoves(ui->e4);
        }
        else if(ui->f4->objectName()==possibleMoves.at(i)){
            ui->f4->setEnabled(true);
            showPermittedMoves(ui->f4);
        }
        else if(ui->g4->objectName()==possibleMoves.at(i)){
            ui->g4->setEnabled(true);
            showPermittedMoves(ui->g4);
        }
        else if(ui->h4->objectName()==possibleMoves.at(i)){
            ui->h4->setEnabled(true);
            showPermittedMoves(ui->h4);
        }
        else if(ui->a5->objectName()==possibleMoves.at(i)){
            ui->a5->setEnabled(true);
            showPermittedMoves(ui->a5);
        }
        else if(ui->b5->objectName()==possibleMoves.at(i)){
            ui->b5->setEnabled(true);
            showPermittedMoves(ui->b5);
        }
        else if(ui->c5->objectName()==possibleMoves.at(i)){
            ui->c5->setEnabled(true);
            showPermittedMoves(ui->c5);
        }
        else if(ui->d5->objectName()==possibleMoves.at(i)){
            ui->d5->setEnabled(true);
            showPermittedMoves(ui->d5);
        }
        else if(ui->e5->objectName()==possibleMoves.at(i)){
            ui->e5->setEnabled(true);
            showPermittedMoves(ui->e5);
        }
        else if(ui->f5->objectName()==possibleMoves.at(i)){
            ui->f5->setEnabled(true);
            showPermittedMoves(ui->f5);
        }
        else if(ui->g5->objectName()==possibleMoves.at(i)){
            ui->g5->setEnabled(true);
            showPermittedMoves(ui->g5);
        }
        else if(ui->h5->objectName()==possibleMoves.at(i)){
            ui->h5->setEnabled(true);
            showPermittedMoves(ui->h5);
        }
        else if(ui->a6->objectName()==possibleMoves.at(i)){
            ui->a6->setEnabled(true);
            showPermittedMoves(ui->a6);
        }
        else if(ui->b6->objectName()==possibleMoves.at(i)){
            ui->b6->setEnabled(true);
            showPermittedMoves(ui->b6);
        }
        else if(ui->c6->objectName()==possibleMoves.at(i)){
            ui->c6->setEnabled(true);
            showPermittedMoves(ui->c6);
        }
        else if(ui->d6->objectName()==possibleMoves.at(i)){
            ui->d6->setEnabled(true);
            showPermittedMoves(ui->d6);
        }
        else if(ui->e6->objectName()==possibleMoves.at(i)){
            ui->e6->setEnabled(true);
            showPermittedMoves(ui->e6);
        }
        else if(ui->f6->objectName()==possibleMoves.at(i)){
            ui->f6->setEnabled(true);
            showPermittedMoves(ui->f6);
        }
        else if(ui->g6->objectName()==possibleMoves.at(i)){
            ui->g6->setEnabled(true);
            showPermittedMoves(ui->g6);
        }
        else if(ui->h6->objectName()==possibleMoves.at(i)){
            ui->h6->setEnabled(true);
            showPermittedMoves(ui->h6);
        }
        else if(ui->a7->objectName()==possibleMoves.at(i)){
            ui->a7->setEnabled(true);
            showPermittedMoves(ui->a7);
        }
        else if(ui->b7->objectName()==possibleMoves.at(i)){
            ui->b7->setEnabled(true);
            showPermittedMoves(ui->b7);
        }
        else if(ui->c7->objectName()==possibleMoves.at(i)){
            ui->c7->setEnabled(true);
            showPermittedMoves(ui->c7);
        }
        else if(ui->d7->objectName()==possibleMoves.at(i)){
            ui->d7->setEnabled(true);
            showPermittedMoves(ui->d7);
        }
        else if(ui->e7->objectName()==possibleMoves.at(i)){
            ui->e7->setEnabled(true);
            showPermittedMoves(ui->e7);
        }
        else if(ui->f7->objectName()==possibleMoves.at(i)){
            ui->f7->setEnabled(true);
            showPermittedMoves(ui->f7);
        }
        else if(ui->g7->objectName()==possibleMoves.at(i)){
            ui->g7->setEnabled(true);
            showPermittedMoves(ui->g7);
        }
        else if(ui->h7->objectName()==possibleMoves.at(i)){
            ui->h7->setEnabled(true);
            showPermittedMoves(ui->h7);
        }
        else if(ui->a8->objectName()==possibleMoves.at(i)){
            ui->a8->setEnabled(true);
            showPermittedMoves(ui->a8);
        }
        else if(ui->b8->objectName()==possibleMoves.at(i)){
            ui->b8->setEnabled(true);
            showPermittedMoves(ui->b8);
        }
        else if(ui->c8->objectName()==possibleMoves.at(i)){
            ui->c8->setEnabled(true);
            showPermittedMoves(ui->c8);
        }
        else if(ui->d8->objectName()==possibleMoves.at(i)){
            ui->d8->setEnabled(true);
            showPermittedMoves(ui->d8);
        }
        else if(ui->e8->objectName()==possibleMoves.at(i)){
            ui->e8->setEnabled(true);
            showPermittedMoves(ui->e8);
        }
        else if(ui->f8->objectName()==possibleMoves.at(i)){
            ui->f8->setEnabled(true);
            showPermittedMoves(ui->f8);
        }
        else if(ui->g8->objectName()==possibleMoves.at(i)){
            ui->g8->setEnabled(true);
            showPermittedMoves(ui->g8);
        }
        else if(ui->h8->objectName()==possibleMoves.at(i)){
            ui->h8->setEnabled(true);
            showPermittedMoves(ui->h8);
        }
    }
}
void Widget::showPermittedMoves(QPushButton *button)
{
    if(button->styleSheet()=="background-color: #035623;\nborder: 1px solid black;" && button->isEnabled()==true) button->setStyleSheet("background-color: #7092be;\nborder: 1px solid black;");
    else if(button->styleSheet()=="background-color: white;\nborder: 1px solid black;"&& button->isEnabled()==true) button->setStyleSheet("background-color: #7092be;\nborder: 1px solid black;");

    else if(button->styleSheet()=="background-image: url(:/img/whitePoon-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whitePoon-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whitePoon-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whitePoon-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackPoon-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackPoon-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackPoon-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackPoon-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteBishop-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteBishop-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteBishop-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteBishop-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackBishop-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackBishop-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackBishop-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackBishop-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteKnight-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteKnight-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteKnight-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteKnight-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackKnight-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackKnight-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackKnight-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackKnight-blueField.png);");

    else if(button->styleSheet()=="background-image: url(:/img/whiteRook-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteRook-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteRook-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteRook-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackRook-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackRook-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackRook-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackRook-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteQueen-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteQueen-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteQueen-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteQueen-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackQueen-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackQueen-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackQueen-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackQueen-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteKing-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteKing-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/whiteKing-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/whiteKing-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackKing-whiteField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackKing-blueField.png);");
    else if(button->styleSheet()=="background-image: url(:/img/blackKing-greenField.png);"&& button->isEnabled()==true) button->setStyleSheet("background-image: url(:/img/blackKing-blueField.png);");
}
