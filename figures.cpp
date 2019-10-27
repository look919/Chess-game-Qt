#include "widget.h"
#include "ui_widget.h"

void Widget::getFigureName(QPushButton *button, bool enemyMoves)
{
    if(whiteMove && enemyMoves == false){                                          //WHITE
        for(int i=0; i<whiteFiguresButtons.size();i++){
            if(button == whiteFiguresButtons.at(i)){
                if(i<=7) currentFigure = "poon";
                else if(i<=9) currentFigure = "Knight";
                else if(i<=11) currentFigure = "Bishop";
                else if(i<=13) currentFigure = "Rook";
                else if(i<=14 || i>15) currentFigure = "Queen";
                else if(i<=15) currentFigure = "King";
                break;
            }
        }
    }
    else if(!whiteMove && enemyMoves == false){                                                   //BLACK
        for(int i=0; i<blackFiguresButtons.size();i++){
            if(button == blackFiguresButtons.at(i)){
                if(i<=7) currentFigure = "poon";
                else if(i<=9) currentFigure = "Knight";
                else if(i<=11) currentFigure = "Bishop";
                else if(i<=13) currentFigure = "Rook";
                else if(i<=14 || i>15) currentFigure = "Queen";
                else if(i<=15) currentFigure = "King";
                break;
            }
        }
    }
    else if(whiteMove && enemyMoves == true){                                          //WHITE figures
        for(int i=0; i<whiteFiguresButtons.size();i++){
            if(button == whiteFiguresButtons.at(i)){
                if(i<=7) currentFigure = "poon";
                else if(i<=9) currentFigure = "Knight";
                else if(i<=11) currentFigure = "Bishop";
                else if(i<=13) currentFigure = "Rook";
                else if(i<=14 || i>15) currentFigure = "Queen";
                else if(i<=15) currentFigure = "King";
                break;
            }
        }
    }
    else if(!whiteMove && enemyMoves == true){                                                   //BLACK figures
        for(int i=0; i<blackFiguresButtons.size();i++){
            if(button == blackFiguresButtons.at(i)){
                if(i<=7) currentFigure = "poon";
                else if(i<=9) currentFigure = "Knight";
                else if(i<=11) currentFigure = "Bishop";
                else if(i<=13) currentFigure = "Rook";
                else if(i<=14 || i>15) currentFigure = "Queen";
                else if(i<=15) currentFigure = "King";
                break;
            }
        }
    }

}

void Widget::poonMovementWhite(QPushButton *button, bool enemyMoves, bool check)
{
    possibleMoves.clear();
    if(!check) disableAllButons();                                      //disable all buttons in order to enable only permitted moves

    pinned = false;
    pinnedPoonStraight = false;

    for(int i=0;i<pinnedFigures.size();i++){
        if(button == pinnedFigures.at(i)) {
            pinned = true;
            if(attackingFigures.at(i)->objectName()[0] == pinnedFigures.at(i)->objectName()[0]) pinnedPoonStraight = true;
            else pinnedPoonStraight = false;
            break;
        }
    }

    if(!pinned || pinnedPoonStraight)
    {
        if(button->objectName()[1]=="2"){                   //FIRST MOVE
            possibleMoves.push_back(button->objectName()[0]+"3");
            possibleMoves.push_back(button->objectName()[0]+"4");


        } else if(button->objectName()[1]=="5"){            //EN PASSANT
            possibleMoves.push_back(button->objectName()[0]+"6");

            QChar poonCanTakeOnLeft = button->objectName()[0];
            QString left;
            QString right;
            char secondCord='7';
            char thirdCord='5';
            QString enter = " \n";

            if(poonCanTakeOnLeft == 'a'){
                left="x";
                right="b";
            }
            else if(poonCanTakeOnLeft == 'b'){
                left="a";
                right="c";
            }
            else if(poonCanTakeOnLeft == 'c'){
                left="b";
                right="d";
            }
            else if(poonCanTakeOnLeft == 'd'){
                left="c";
                right="e";
            }
            else if(poonCanTakeOnLeft == 'e'){
                left="d";
                right="f";
            }
            else if(poonCanTakeOnLeft == 'f'){
                left="e";
                right="g";
            }
            else if(poonCanTakeOnLeft == 'g'){
                left="f";
                right="h";
            }
            else if(poonCanTakeOnLeft == 'h'){
                left="g";
                right="x";
            }

            QString fullname_left = left+secondCord+"-"+left+thirdCord+enter;
            QString fullname_right = right+secondCord+"-"+right+thirdCord+enter;

            enPassantLeft = left+"6";
            enPassantRight = right+"6";

            if(text == fullname_right){
                possibleMoves.push_back(enPassantRight);
                enPassant = true;
            } else if(text == fullname_left){
                possibleMoves.push_back(enPassantLeft);
                enPassant = true;
            }
        } else if(button->objectName()[1]=="3" || button->objectName()[1]=="4" || button->objectName()[1]=="6"|| button->objectName()[1]=="7"){

            QChar secondChar;
            if(button->objectName()[1]=="3") secondChar='4';
            else if(button->objectName()[1]=="4") secondChar='5';
            else if(button->objectName()[1]=="6") secondChar='7';
            else if(button->objectName()[1]=="7") secondChar='8';

            possibleMoves.push_back(button->objectName()[0]+secondChar);

        }
    }

    if(enemyMoves==false){
        button->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-blueField.png);"));
        button->setEnabled(true);

        poonColision(button);
        if(!pinned || !pinnedPoonStraight) poonTaking(button,"black");

        if(isItCheck){
            for(int i=0; i<possibleMoves.size();i++){
                bool validMove = false;
                for(int j=0;j<checkingMoves.size();j++){
                    if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                }
                if(validMove) validMove=false;
                else {
                    blockMove(possibleMoves.at(i));
                    i=-1;
                }
            }
        }
        matchCoordinates();
    }
    else if(enemyMoves==true){
       if(!check) {
           possibleMoves.clear();
           poonTaking(button);
       }
       else {
           poonColision(button);
           poonTaking(button,"black");
       }

       if(!check) qDebug()<<"poon"<<possibleMoves;

        for(int i=0; i<possibleMoves.size();i++){
            if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
            else protectingMoves.push_back(possibleMoves.at(i));
        }

        if(!check) isKingChecked(button);
    }
}
void Widget::poonMovementBlack(QPushButton *button, bool enemyMoves, bool check)
{
    possibleMoves.clear();
    if(!check) disableAllButons();                                      //disable all buttons in order to enable only permitted moves

    pinned = false;
    pinnedPoonStraight = false;

    for(int i=0;i<pinnedFigures.size();i++){
        if(button == pinnedFigures.at(i)) {
            pinned = true;
            if(attackingFigures.at(i)->objectName()[0] == pinnedFigures.at(i)->objectName()[0]) pinnedPoonStraight = true;
            else pinnedPoonStraight = false;
            break;
        }
    }


    if(!pinned || pinnedPoonStraight)
    {
        if(button->objectName()[1]=="7"){                   //FIRST MOVE
            possibleMoves.push_back(button->objectName()[0]+"6");
            possibleMoves.push_back(button->objectName()[0]+"5");

        } else if(button->objectName()[1]=="4"){         //EN PASSANT
            possibleMoves.push_back(button->objectName()[0]+"3");

            QChar poonCanTakeOnLeft = button->objectName()[0];
            QString left;
            QString right;
            char secondCord='2';
            char thirdCord='4';
            QString enter = " \n";

            if(poonCanTakeOnLeft == 'a'){
                left="x";
                right="b";
            }
            else if(poonCanTakeOnLeft == 'b'){
                left="a";
                right="c";
            }
            else if(poonCanTakeOnLeft == 'c'){
                left="b";
                right="d";
            }
            else if(poonCanTakeOnLeft == 'd'){
                left="c";
                right="e";
            }
            else if(poonCanTakeOnLeft == 'e'){
                left="d";
                right="f";
            }
            else if(poonCanTakeOnLeft == 'f'){
                left="e";
                right="g";
            }
            else if(poonCanTakeOnLeft == 'g'){
                left="f";
                right="h";
            }
            else if(poonCanTakeOnLeft == 'h'){
                left="g";
                right="x";
            }

            QString fullname_left = left+secondCord+"-"+left+thirdCord+enter;
            QString fullname_right = right+secondCord+"-"+right+thirdCord+enter;

            enPassantLeft = left+"3";
            enPassantRight = right+"3";

            if(text == fullname_right){
                possibleMoves.push_back(enPassantRight);
                enPassant = true;
            } else if(text == fullname_left){
                possibleMoves.push_back(enPassantLeft);
                enPassant = true;
            }
        } else if(button->objectName()[1]=="6" || button->objectName()[1]=="5" || button->objectName()[1]=="3"|| button->objectName()[1]=="2"){

            QChar secondChar;
            if(button->objectName()[1]=="6") secondChar='5';
            else if(button->objectName()[1]=="5") secondChar='4';
            else if(button->objectName()[1]=="3") secondChar='2';
            else if(button->objectName()[1]=="2") secondChar='1';

            possibleMoves.push_back(button->objectName()[0]+secondChar);

        }
    }

    if(enemyMoves==false){
        button->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-blueField.png);"));
        button->setEnabled(true);

        poonColision(button);
        if(!pinned || !pinnedPoonStraight) poonTaking(button,"white");

        if(isItCheck){
            for(int i=0; i<possibleMoves.size();i++){
                bool validMove = false;
                for(int j=0;j<checkingMoves.size();j++){
                    if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                }
                if(validMove) validMove=false;
                else {
                    blockMove(possibleMoves.at(i));
                    i=-1;
                }
            }
        }

        matchCoordinates();
    }
    else if(enemyMoves==true){
        if(!check) {
            possibleMoves.clear();
            poonTaking(button);

        }
        else {
            poonColision(button);
            poonTaking(button,"white");
        }

        if(!check) qDebug()<<"poon"<<possibleMoves;

        for(int i=0; i<possibleMoves.size();i++){
            if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
            else protectingMoves.push_back(possibleMoves.at(i));
        }

        if(!check) isKingChecked(button);
    }
}
void Widget::poonColision(QPushButton *button)
{
    if(whiteMove)
    {
        if(button->objectName()[1]=="2"){
            convertStringToButton(button->objectName()[0]+"3");
            checkIfThereIsAPiece(requiredButton);
             if(ifExist == true){
                 ifExist=false;
                 blockMove(button->objectName()[0]+"3");
                 blockMove(button->objectName()[0]+"4");
             }
             else{
                 convertStringToButton(button->objectName()[0]+"4");
                 checkIfThereIsAPiece(requiredButton);
                     if(ifExist == true){
                         ifExist = false;
                         blockMove(button->objectName()[0]+"4");
                     }
             }
        } else if(button->objectName()[1]=="3" || button->objectName()[1]=="4" || button->objectName()[1]=="5" || button->objectName()[1]=="6" || button->objectName()[1]=="7"){
            QChar firstCord = button->objectName()[0];

            char secondCord = 'x';
            if(button->objectName()[1]=="3") secondCord='4';
            else if(button->objectName()[1]=="4") secondCord='5';
            else if(button->objectName()[1]=="5") secondCord='6';
            else if(button->objectName()[1]=="6") secondCord='7';
            else if(button->objectName()[1]=="7") secondCord='8';

            convertStringToButton(firstCord+secondCord);
            checkIfThereIsAPiece(requiredButton);
            if(ifExist == true){
                ifExist = false;
                blockMove(firstCord+secondCord);
            }
        }
    }
    else if(!whiteMove)
    {
        if(button->objectName()[1]=="7"){
            convertStringToButton(button->objectName()[0]+"6");
            checkIfThereIsAPiece(requiredButton);

             if(ifExist == true){
                 ifExist=false;
                 blockMove(button->objectName()[0]+"6");
                 blockMove(button->objectName()[0]+"5");
             }
             else{
                 convertStringToButton(button->objectName()[0]+"5");
                 checkIfThereIsAPiece(requiredButton);
                     if(ifExist == true){
                         ifExist = false;
                         blockMove(button->objectName()[0]+"5");
                     }
             }
        } else if(button->objectName()[1]=="3" || button->objectName()[1]=="4" || button->objectName()[1]=="5" || button->objectName()[1]=="6" || button->objectName()[1]=="7"){
            QChar firstCord = button->objectName()[0];

            char secondCord = 'x';
            if(button->objectName()[1]=="6") secondCord='5';
            else if(button->objectName()[1]=="5") secondCord='4';
            else if(button->objectName()[1]=="4") secondCord='3';
            else if(button->objectName()[1]=="3") secondCord='2';
            else if(button->objectName()[1]=="2") secondCord='1';

            convertStringToButton(firstCord+secondCord);
            checkIfThereIsAPiece(requiredButton);
            if(ifExist == true){
                ifExist = false;
                blockMove(firstCord+secondCord);
            }
        }
    }
}
void Widget::poonTaking(QPushButton *button, QString color, bool abstract)
{
    QChar poonCanTakeOnLeft = button->objectName()[0];
    QChar poonCanTakeOnRight = button->objectName()[0];
    if(poonCanTakeOnLeft == 'a'){
        poonCanTakeOnLeft='x';
        poonCanTakeOnRight='b';
    }
    else if(poonCanTakeOnLeft == 'b'){
        poonCanTakeOnLeft='a';
        poonCanTakeOnRight='c';
    }
    else if(poonCanTakeOnLeft == 'c'){
        poonCanTakeOnLeft='b';
        poonCanTakeOnRight='d';
    }
    else if(poonCanTakeOnLeft == 'd'){
        poonCanTakeOnLeft='c';
        poonCanTakeOnRight='e';
    }
    else if(poonCanTakeOnLeft == 'e'){
        poonCanTakeOnLeft='d';
        poonCanTakeOnRight='f';
    }
    else if(poonCanTakeOnLeft == 'f'){
        poonCanTakeOnLeft='e';
        poonCanTakeOnRight='g';
    }
    else if(poonCanTakeOnLeft == 'g'){
        poonCanTakeOnLeft='f';
        poonCanTakeOnRight='h';
    }
    else if(poonCanTakeOnLeft == 'h'){
        poonCanTakeOnLeft='g';
        poonCanTakeOnRight='x';
    }

    char secondCord='x';
    if(whiteMove)
    {
        if(button->objectName()[1]=="2") secondCord='3';
        else if(button->objectName()[1]=="3") secondCord='4';
        else if(button->objectName()[1]=="4") secondCord='5';
        else if(button->objectName()[1]=="5") secondCord='6';
        else if(button->objectName()[1]=="6") secondCord='7';
        else if(button->objectName()[1]=="7") secondCord='8';
    }
    else if(!whiteMove)
    {
        if(button->objectName()[1]=="7") secondCord='6';
        else if(button->objectName()[1]=="6") secondCord='5';
        else if(button->objectName()[1]=="5") secondCord='4';
        else if(button->objectName()[1]=="4") secondCord='3';
        else if(button->objectName()[1]=="3") secondCord='2';
        else if(button->objectName()[1]=="2") secondCord='1';
    }
    if(abstract == false){
        if(color != "none")
        {
            coords = poonCanTakeOnLeft+secondCord;
            if(coords[0] != 'x' && coords[1] != 'x') {
                convertStringToButton(coords);
                checkIfThereIsAPiece(requiredButton,color);
                if(ifExist==true) {
                    ifExist=false;
                    possibleMoves.push_back(coords);
                }
            }
            coords = poonCanTakeOnRight+secondCord;
            if(coords[0] != 'x' && coords[1] != 'x') {
                convertStringToButton(coords);
                checkIfThereIsAPiece(requiredButton,color);
                if(ifExist==true) {
                    ifExist=false;
                    possibleMoves.push_back(coords);
                }
            }
        }
        else            //moves from opponent side
        {
            coords = poonCanTakeOnLeft+secondCord;
            if(coords[0] != 'x' && coords[1] != 'x'){
                possibleMoves.push_back(coords);
            }
            coords = poonCanTakeOnRight+secondCord;
            if(coords[0] != 'x' && coords[1] != 'x'){
                possibleMoves.push_back(coords);
            }
        }
    }
    else{
        pinned = false;

        coords = poonCanTakeOnLeft+secondCord;
        if(coords[0] != 'x' && coords[1] != 'x') {
            convertStringToButton(coords);
            if(requiredButton == attackingFigures[index]) pinned = true;
        }
        coords = poonCanTakeOnRight+secondCord;
        if(coords[0] != 'x' && coords[1] != 'x') {
            convertStringToButton(coords);
            if(requiredButton == attackingFigures[index]) pinned = true;
        }
    }

}

void Widget::knightMovement(QPushButton *button, bool enemyMoves, bool check)
{
    possibleMoves.clear();
    if(!check) disableAllButons();

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

    coords=left+down_further;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }
    coords=left_further+down;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }
    coords=left_further+up;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }
    coords=left+up_further;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }
    coords=right+down_further;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }
    coords=right_further+down;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }
    coords=right_further+up;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }
    coords=right+up_further;
    if(coords[0]!='x' && coords[1]!='x'){
        possibleMoves.push_back(coords);
    }

    if(whiteMove)
    {      
        if(enemyMoves==false){
            colision(button,"white");
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/whiteKnight-blueField.png);");

            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }

            matchCoordinates();
        }
        else if (enemyMoves == true) {
            for(int i=0;i<possibleMoves.size();i++){
               if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
               else protectingMoves.push_back(possibleMoves.at(i));
            }
           if(!check) isKingChecked(button);

           if(!check) qDebug()<<"knight"<<possibleMoves;
        }
    }
    else if(!whiteMove)
    {
        if(enemyMoves==false){
            colision(button,"black");
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/blackKnight-blueField.png);");

            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }
            matchCoordinates();
        }
        else if (enemyMoves == true) {
            for(int i=0;i<possibleMoves.size();i++){
                if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
                else protectingMoves.push_back(possibleMoves.at(i));
            }
           if(!check) isKingChecked(button);
            if(!check) qDebug()<<"knight"<<possibleMoves;
        }
    }

}
void Widget::bishopMovement(QPushButton *button, bool enemyMoves, bool check)
{
    possibleMoves.clear();
    if(!check) disableAllButons();

    char up;
    char down;
    char left;
    char right;

    if(button->objectName()[0]=='a'){
        left='x';
        right='b';
    } else if(button->objectName()[0]=='b'){
        left='a';
        right='c';
    } else if(button->objectName()[0]=='c'){
        left='b';
        right='d';
    } else if(button->objectName()[0]=='d'){
        left='c';
        right='e';
    } else if(button->objectName()[0]=='e'){
        left='d';
        right='f';
    } else if(button->objectName()[0]=='f'){
        left='e';
        right='g';
    } else if(button->objectName()[0]=='g'){
        left='f';
        right='h';
    } else if(button->objectName()[0]=='h'){
        left='g';
        right='x';
    } else{
        left='x';
        right='x';
    }

    if(button->objectName()[1]=='1'){
        down='x';
        up='2';
    } else if(button->objectName()[1]=='2'){
        down='1';
        up='3';
    } else if(button->objectName()[1]=='3'){
        down='2';
        up='4';
    } else if(button->objectName()[1]=='4'){
        down='3';
        up='5';
    } else if(button->objectName()[1]=='5'){
        down='4';
        up='6';
    } else if(button->objectName()[1]=='6'){
        down='5';
        up='7';
    } else if(button->objectName()[1]=='7'){
        down='6';
        up='8';
    } else if(button->objectName()[1]=='8'){
        down='7';
        up='x';
    } else{
        down='x';
        up='x';
    }

    QString firstCord;
    QString secondCord;
    char storageUp=up;
    char storageDown=down;
    char storageLeft=left;
    char storageRight=right;

    if(whiteMove)
    {

        if(up!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="right";
                if(up=='9') break;
            }
           pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
        if(down!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="right";
                if(down=='0') break;
            }
           pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
        if(up!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="left";
                if(up=='9') break;
            }
            pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
        if(down!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="left";
                if(down=='0') break;
            }
            pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }

        if(enemyMoves == false) {
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/whiteBishop-blueField.png);");
            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }

            matchCoordinates();
        }
        else if(enemyMoves == true){
            for(int i=0;i<possibleMoves.size();i++){
                if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
                else protectingMoves.push_back(possibleMoves.at(i));
            }
          if(!check)  qDebug()<<"bishop"<<possibleMoves;
        }
        possibleMovesStorage.clear();
        abstractPossibleMoves.clear();

    }
    else if(!whiteMove)
    {
        if(up!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="right";
                if(up=='9') break;
            }
            pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
        if(down!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="right";
                if(down=='0') break;
            }
            pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
       if(up!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="left";
                if(up=='9') break;
            }
           pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        if(down!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="left";
                if(down=='0') break;
            }
           pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }

        if(enemyMoves == false) {
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/blackBishop-blueField.png);");
            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }
            matchCoordinates();
        }
        else if(enemyMoves == true){
            for(int i=0;i<possibleMoves.size();i++){
                if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
                else protectingMoves.push_back(possibleMoves.at(i));
            }
           if(!check)  qDebug()<<"bishop"<<possibleMoves;
        }
        possibleMovesStorage.clear();
    }

}
void Widget::rookMovement(QPushButton *button, bool enemyMoves, bool check)
{
    possibleMoves.clear();
    if(!check) disableAllButons();

    char up;
    char down;
    char left;
    char right;

    QChar firstCordButton = button->objectName()[0];
    QChar secondCordButton= button->objectName()[1];

    if(button->objectName()[0]=='a'){
        left='x';
        right='b';
    } else if(button->objectName()[0]=='b'){
        left='a';
        right='c';
    } else if(button->objectName()[0]=='c'){
        left='b';
        right='d';
    } else if(button->objectName()[0]=='d'){
        left='c';
        right='e';
    } else if(button->objectName()[0]=='e'){
        left='d';
        right='f';
    } else if(button->objectName()[0]=='f'){
        left='e';
        right='g';
    } else if(button->objectName()[0]=='g'){
        left='f';
        right='h';
    } else if(button->objectName()[0]=='h'){
        left='g';
        right='x';
    } else{
        left='x';
        right='x';
    }

    if(button->objectName()[1]=='1'){
        down='x';
        up='2';
    } else if(button->objectName()[1]=='2'){
        down='1';
        up='3';
    } else if(button->objectName()[1]=='3'){
        down='2';
        up='4';
    } else if(button->objectName()[1]=='4'){
        down='3';
        up='5';
    } else if(button->objectName()[1]=='5'){
        down='4';
        up='6';
    } else if(button->objectName()[1]=='6'){
        down='5';
        up='7';
    } else if(button->objectName()[1]=='7'){
        down='6';
        up='8';
    } else if(button->objectName()[1]=='8'){
        down='7';
        up='x';
    } else{
        down='x';
        up='x';
    }

    if(whiteMove)
    {

        if(up!='x'){
            for(char i=up;i<='8';i++){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="up";
            }
           pinnedMovement(button,"white",enemyMoves);
        }
        if(down!='x'){
            for(char i=down;i>='1';i--){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="down";
            }
          pinnedMovement(button,"white",enemyMoves);
        }
        if(right!='x'){
            for(char i=right;i<='h';i++){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="right";
            }
           pinnedMovement(button,"white",enemyMoves);
        }
        if(left!='x'){
            for(char i=left;i>='a';i--){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="left";
            }
          pinnedMovement(button,"white",enemyMoves);
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }

        if(enemyMoves == false) {
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/whiteRook-blueField.png);");
            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }
            matchCoordinates();
        }
        else if(enemyMoves == true){
            for(int i=0;i<possibleMoves.size();i++){
                if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
                else protectingMoves.push_back(possibleMoves.at(i));
            }
           if(!check)  qDebug()<<"rook"<<possibleMoves;
        }
        possibleMovesStorage.clear();

    }    
    else if(!whiteMove)
    {
        if(up!='x'){
            for(char i=up;i<='8';i++){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="up";
            }
          pinnedMovement(button,"black",enemyMoves);
        }
        if(down!='x'){
            for(char i=down;i>='1';i--){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="down";
            }
          pinnedMovement(button,"black",enemyMoves);
        }
        if(right!='x'){
            for(char i=right;i<='h';i++){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="right";
            }
           pinnedMovement(button,"black",enemyMoves);
        }
        if(left!='x'){
            for(char i=left;i>='a';i--){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="left";
            }
          pinnedMovement(button,"black",enemyMoves);
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }

        if(enemyMoves == false) {
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/blackRook-blueField.png);");
            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }
            matchCoordinates();
        }
        else if(enemyMoves == true){
            for(int i=0;i<possibleMoves.size();i++){
                if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
                else protectingMoves.push_back(possibleMoves.at(i));
            }
           if(!check)  qDebug()<<"rook"<<possibleMoves;
        }
        possibleMovesStorage.clear();
    }
}
void Widget::queenMovement(QPushButton *button, bool enemyMoves, bool check)
{
    possibleMoves.clear();
    if(!check) disableAllButons();
    QVector <QString> connectMoves;

    //BISHOP
    char up;
    char down;
    char left;
    char right;

    if(button->objectName()[0]=='a'){
        left='x';
        right='b';
    } else if(button->objectName()[0]=='b'){
        left='a';
        right='c';
    } else if(button->objectName()[0]=='c'){
        left='b';
        right='d';
    } else if(button->objectName()[0]=='d'){
        left='c';
        right='e';
    } else if(button->objectName()[0]=='e'){
        left='d';
        right='f';
    } else if(button->objectName()[0]=='f'){
        left='e';
        right='g';
    } else if(button->objectName()[0]=='g'){
        left='f';
        right='h';
    } else if(button->objectName()[0]=='h'){
        left='g';
        right='x';
    } else{
        left='x';
        right='x';
    }

    if(button->objectName()[1]=='1'){
        down='x';
        up='2';
    } else if(button->objectName()[1]=='2'){
        down='1';
        up='3';
    } else if(button->objectName()[1]=='3'){
        down='2';
        up='4';
    } else if(button->objectName()[1]=='4'){
        down='3';
        up='5';
    } else if(button->objectName()[1]=='5'){
        down='4';
        up='6';
    } else if(button->objectName()[1]=='6'){
        down='5';
        up='7';
    } else if(button->objectName()[1]=='7'){
        down='6';
        up='8';
    } else if(button->objectName()[1]=='8'){
        down='7';
        up='x';
    } else{
        down='x';
        up='x';
    }

    QString firstCord;
    QString secondCord;
    char storageUp=up;
    char storageDown=down;
    char storageLeft=left;
    char storageRight=right;

    if(whiteMove)
    {
        if(up!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="right";
                if(up=='9') break;
            }
            pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
        if(down!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="right";
                if(down=='0') break;
            }
            pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
       if(up!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="left";
                if(up=='9') break;
            }
            pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        if(down!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="left";
                if(down=='0') break;
            }
            pinnedMovement(button,"white",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }
    }
    else if(!whiteMove)
    {
        if(up!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="right";
                if(up=='9') break;
            }
            pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
        if(down!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="right";
                if(down=='0') break;
            }
            pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }
       if(up!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                up++;
                coords="left";
                if(up=='9') break;
            }
            pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        if(down!='x' && left!='x'){
            for(char i=left;i>='a';i--){
                firstCord=i;
                secondCord=down;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                down--;
                coords="left";
                if(down=='0') break;
            }
            pinnedMovement(button,"black",enemyMoves);

            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }

    }
    possibleMovesStorage.clear();


    //CONNECTING
    for(int i=0;i<possibleMoves.size();i++){
        connectMoves.push_back(possibleMoves.at(i));
        }
    possibleMoves.clear();


    //ROOK

    QChar firstCordButton = button->objectName()[0];
    QChar secondCordButton= button->objectName()[1];

    if(button->objectName()[0]=='a'){
        left='x';
        right='b';
    } else if(button->objectName()[0]=='b'){
        left='a';
        right='c';
    } else if(button->objectName()[0]=='c'){
        left='b';
        right='d';
    } else if(button->objectName()[0]=='d'){
        left='c';
        right='e';
    } else if(button->objectName()[0]=='e'){
        left='d';
        right='f';
    } else if(button->objectName()[0]=='f'){
        left='e';
        right='g';
    } else if(button->objectName()[0]=='g'){
        left='f';
        right='h';
    } else if(button->objectName()[0]=='h'){
        left='g';
        right='x';
    } else{
        left='x';
        right='x';
    }

    if(button->objectName()[1]=='1'){
        down='x';
        up='2';
    } else if(button->objectName()[1]=='2'){
        down='1';
        up='3';
    } else if(button->objectName()[1]=='3'){
        down='2';
        up='4';
    } else if(button->objectName()[1]=='4'){
        down='3';
        up='5';
    } else if(button->objectName()[1]=='5'){
        down='4';
        up='6';
    } else if(button->objectName()[1]=='6'){
        down='5';
        up='7';
    } else if(button->objectName()[1]=='7'){
        down='6';
        up='8';
    } else if(button->objectName()[1]=='8'){
        down='7';
        up='x';
    } else{
        down='x';
        up='x';
    }

    if(whiteMove)
    {
        if(up!='x'){
            for(char i=up;i<='8';i++){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="up";
            }
            pinnedMovement(button,"white",enemyMoves);
        }
        if(down!='x'){
            for(char i=down;i>='1';i--){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="down";
            }
            pinnedMovement(button,"white",enemyMoves);
        }
        if(right!='x'){
            for(char i=right;i<='h';i++){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="right";
            }
            pinnedMovement(button,"white",enemyMoves);
        }
        if(left!='x'){
            for(char i=left;i>='a';i--){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="left";
            }
            pinnedMovement(button,"white",enemyMoves);
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }
    }
    else if(!whiteMove)
    {
        if(up!='x'){
            for(char i=up;i<='8';i++){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="up";
            }
            pinnedMovement(button,"black",enemyMoves);
        }
        if(down!='x'){
            for(char i=down;i>='1';i--){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="down";
            }
            pinnedMovement(button,"black",enemyMoves);
        }
        if(right!='x'){
            for(char i=right;i<='h';i++){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="right";
            }
            pinnedMovement(button,"black",enemyMoves);
        }
        if(left!='x'){
            for(char i=left;i>='a';i--){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                if(enemyMoves == true) abstractPossibleMoves.push_back(coords);
                coords="left";
            }
            pinnedMovement(button,"black",enemyMoves);
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }
    }




    //CONNECTING
    for(int i=0;i<connectMoves.size();i++){
        possibleMoves.push_back(connectMoves.at(i));
    }

    if(whiteMove)
    {
        if(enemyMoves == false){
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/whiteQueen-blueField.png);");
            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }
            matchCoordinates();
        }
        else if(enemyMoves == true){
            for(int i=0;i<possibleMoves.size();i++){
                if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
                else protectingMoves.push_back(possibleMoves.at(i));
            }
           if(!check)  qDebug()<<"queen"<<possibleMoves;
        }
        possibleMovesStorage.clear();
    }
    else if(!whiteMove)
    {
        if(enemyMoves == false){
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/blackQueen-blueField.png);");
            if(isItCheck){
                for(int i=0; i<possibleMoves.size();i++){
                    bool validMove = false;
                    for(int j=0;j<checkingMoves.size();j++){
                        if(checkingMoves.at(j) == possibleMoves.at(i)) validMove = true;
                    }
                    if(validMove) validMove=false;
                    else {
                        blockMove(possibleMoves.at(i));
                        i=-1;
                    }
                }
            }
            matchCoordinates();
        }
        else if(enemyMoves == true){
            for(int i=0;i<possibleMoves.size();i++){
                if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
                else protectingMoves.push_back(possibleMoves.at(i));
            }
         if(!check)   qDebug()<<"queen"<<possibleMoves;
        }
        possibleMovesStorage.clear();
    }
}
void Widget::kingMovement(QPushButton *button, bool enemyMoves,bool check)
{
    possibleMoves.clear();
    if(!check) disableAllButons();

    QString up;
    QString down;
    QString left;
    QString right;

    if(button->objectName()[0]=='a'){
        left="x";
        right="b";
    } else if(button->objectName()[0]=='b'){
        left="a";
        right="c";
    } else if(button->objectName()[0]=='c'){
        left="b";
        right="d";
    } else if(button->objectName()[0]=='d'){
        left="c";
        right="e";
    } else if(button->objectName()[0]=='e'){
        left="d";
        right="f";
    } else if(button->objectName()[0]=='f'){
        left="e";
        right="g";
    } else if(button->objectName()[0]=='g'){
        left="f";
        right="h";
    } else if(button->objectName()[0]=='h'){
        left="g";
        right="x";
    }

    if(button->objectName()[1]=='1'){
        down="x";
        up="2";
    } else if(button->objectName()[1]=='2'){
        down="1";
        up="3";
    } else if(button->objectName()[1]=='3'){
        down="2";
        up="4";
    } else if(button->objectName()[1]=='4'){
        down="3";
        up="5";
    } else if(button->objectName()[1]=='5'){
        down="4";
        up="6";
    } else if(button->objectName()[1]=='6'){
        down="5";
        up="7";
    } else if(button->objectName()[1]=='7'){
        down="6";
        up="8";
    } else if(button->objectName()[1]=='8'){
        down="7";
        up="x";
    }

    if(up!="x"){
        coords = button->objectName()[0]+up;
        possibleMoves.push_back(coords);
    }
    if(down!="x"){
        coords = button->objectName()[0]+down;
        possibleMoves.push_back(coords);
    }
    if(left!="x"){
        coords = left+button->objectName()[1];
        possibleMoves.push_back(coords);
    }
    if(right!="x"){
        coords = right+button->objectName()[1];
        possibleMoves.push_back(coords);
    }
    if(down!="x" && left!="x"){
        coords = left+down;
        possibleMoves.push_back(coords);
    }
    if(down!="x" && right!="x"){
        coords = right+down;
        possibleMoves.push_back(coords);
    }
    if(up!="x" && left!="x"){
        coords = left+up;
        possibleMoves.push_back(coords);
    }
    if(up!="x" && right!="x"){
        coords = right+up;
        possibleMoves.push_back(coords);

    }
    if(checkingMoves.size() == 0) kingCastle();
    if(whiteMove)
    {

        if(enemyMoves == false){
            colision(button,"white");
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/whiteKing-blueField.png);");

            for(int i=0;i<opponentPossibleMoves.size();i++){
                for(int j=0;j<possibleMoves.size();j++){
                    if(possibleMoves.at(j) == opponentPossibleMoves.at(i)) {
                        possibleMoves.remove(j);
                        j= -1;
                    }
                }
            }

            for(int i=0;i<opponentPossibleMovesStorage.size();i++){
                for(int j=0;j<possibleMoves.size();j++){
                    if(possibleMoves.at(j) == opponentPossibleMovesStorage.at(i)) {
                        possibleMoves.remove(j);
                        j= -1;
                    }
                }
            }
            matchCoordinates();
        }
        else if(enemyMoves == true){
            if(check) {
                colision(button,"white");

                for(int i=0;i<opponentPossibleMoves.size();i++){
                    for(int j=0;j<possibleMoves.size();j++){
                        if(possibleMoves.at(j) == opponentPossibleMoves.at(i)) {
                            possibleMoves.remove(j);
                            j= -1;
                        }
                    }
                }


            }
            for(int i=0;i<possibleMoves.size();i++){
               if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
               else protectingMoves.push_back(possibleMoves.at(i));
            }
         if(!check)   qDebug()<<"king"<<possibleMoves;
        }
    }
    else if(!whiteMove)
    {
        if(enemyMoves == false){
            colision(button,"black");
            button->setEnabled(true);
            button->setStyleSheet("background-image: url(:/img/blackKing-blueField.png);");

            for(int i=0;i<opponentPossibleMoves.size();i++){
                for(int j=0;j<possibleMoves.size();j++){
                    if(possibleMoves.at(j) == opponentPossibleMoves.at(i)){
                        possibleMoves.remove(j);
                         j= -1;
                    }
                }
            }

            for(int i=0;i<opponentPossibleMovesStorage.size();i++){
                for(int j=0;j<possibleMoves.size();j++){
                    if(possibleMoves.at(j) == opponentPossibleMovesStorage.at(i)) {
                        possibleMoves.remove(j);
                        j= -1;
                    }
                }
            }
            matchCoordinates();
        }
        else if(enemyMoves == true){
            if(check) {
                colision(button,"black");

                for(int i=0;i<opponentPossibleMoves.size();i++){
                    for(int j=0;j<possibleMoves.size();j++){
                        if(possibleMoves.at(j) == opponentPossibleMoves.at(i)) {
                            possibleMoves.remove(j);
                            j= -1;
                        }
                    }
                }
            }
            for(int i=0;i<possibleMoves.size();i++){
               if(!check) opponentPossibleMoves.push_back(possibleMoves.at(i));
               else protectingMoves.push_back(possibleMoves.at(i));
            }
         if(!check)   qDebug()<<"king"<<possibleMoves;
        }
    }
}
void Widget::kingCastle()
{
    if(whiteMove){
        if(whiteCastleShort){
            if(ui->f1->styleSheet()=="background-color: #035623;\nborder: 1px solid black;" && ui->g1->styleSheet()=="background-color: white;\nborder: 1px solid black;"){
                coords = "short";
                possibleMoves.push_back("g1");
            }
        }
        if(whiteCastleLong){
            if (ui->d1->styleSheet()=="background-color: #035623;\nborder: 1px solid black;" && ui->c1->styleSheet()=="background-color: white;\nborder: 1px solid black;"
                    && ui->b1->styleSheet()=="background-color: #035623;\nborder: 1px solid black;"){
                coords = "long";
                possibleMoves.push_back("c1");
            }
        }
    }
    else if(!whiteMove){
        if(blackCastleShort){
            if(ui->f8->styleSheet()=="background-color: white;\nborder: 1px solid black;" && ui->g8->styleSheet()=="background-color: #035623;\nborder: 1px solid black;"){
                coords = "short";
                possibleMoves.push_back("g8");
            }
        }
        if(blackCastleLong){
            if (ui->d8->styleSheet()=="background-color: white;\nborder: 1px solid black;" && ui->c8->styleSheet()=="background-color: #035623;\nborder: 1px solid black;"
                    && ui->b8->styleSheet()=="background-color: white;\nborder: 1px solid black;"){
                coords = "long";
                possibleMoves.push_back("c8");
            }
        }
    }
}

void Widget::pinnedMovement(QPushButton *button,QString color, bool enemyMoves, bool check)
{
    pinned = false;
    index = 0;

    for(int i=0;i<pinnedFigures.size();i++){
        if(button == pinnedFigures.at(i)) {
            pinned = true;
            index=i;
            break;
        }
    }

    if(pinned){
        for(int i=0;i<possibleMoves.size();i++){
            convertStringToButton(possibleMoves.at(i));
            if(requiredButton == attackingFigures.at(index)){

                pinned = false;
                colision(button,color,true);
            }
        }

        if(pinned){
            possibleMoves.clear();
        }
    }

    else if(!pinned){
        if(enemyMoves == false) colision(button,color,true);
        else {

            colision(button,color,true,true);
            abstractColision(button);
            if(!check) isKingChecked(button);
            abstractPossibleMoves.clear();

        }
        possibleMoves.clear();
    }

}
