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

void Widget::poonMovementWhite(QPushButton *button)
{
    disableAllButons();                                      //disable all buttons in order to enable only permitted moves


    button->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-blueField.png);"));
    button->setEnabled(true);

    if(button->objectName()[1]=="2"){                   //FIRST MOVE
        possibleMoves.push_back(button->objectName()[0]+"3");
        possibleMoves.push_back(button->objectName()[0]+"4");

        poonColision(button);
        poonTaking(button,"black");

    } else if(button->objectName()[1]=="5"){            //EN PASSANT
        possibleMoves.push_back(button->objectName()[0]+"6");
        poonColision(button);
        poonTaking(button,"black");


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
        poonColision(button);
        poonTaking(button,"black");
    }

    matchCoordinates();
}

void Widget::poonMovementBlack(QPushButton *button)
{
    disableAllButons();                                      //disable all buttons in order to enable only permitted moves


    button->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-blueField.png);"));
    button->setEnabled(true);

    if(button->objectName()[1]=="7"){                   //FIRST MOVE
        possibleMoves.push_back(button->objectName()[0]+"6");
        possibleMoves.push_back(button->objectName()[0]+"5");

        poonColision(button);
        poonTaking(button,"white");
    } else if(button->objectName()[1]=="4"){         //EN PASSANT
        possibleMoves.push_back(button->objectName()[0]+"3");
        poonColision(button);
        poonTaking(button,"white");


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
        poonColision(button);
        poonTaking(button,"white");
    }
    matchCoordinates();
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
void Widget::poonTaking(QPushButton *button, QString color)
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
void Widget::poonPromotion(QPushButton *button, QString figureColor)
{
    PromotePawn promotion(this);
    if(whiteMove) promotion.color="white";
    else promotion.color="black";
    promotion.setModal(true);
    promotion.exec();

    if(promotion.choosenFigure=="Queen" && button->font().bold() == true ){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Queen-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }else if(promotion.choosenFigure=="Queen" && button->font().bold() == false ){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Queen-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }else if(promotion.choosenFigure=="Rook" && button->font().bold() == true ){
        button->setStyleSheet(("background-image: url(:/img/"+figureColor+"Rook-greenField.png);"));
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }else if(promotion.choosenFigure=="Rook" && button->font().bold() == false ){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Rook-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }else if(promotion.choosenFigure=="Bishop" && button->font().bold() == true ){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Bishop-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }else if(promotion.choosenFigure=="Bishop" && button->font().bold() == false ){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Bishop-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
    }else if(promotion.choosenFigure=="Knight" && button->font().bold() == true ){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Knight-greenField.png);");
        currentFigureButton->setStyleSheet("background-color: white;\nborder: 1px solid black;");
    }else if(promotion.choosenFigure=="Knight" && button->font().bold() == false ){
        button->setStyleSheet("background-image: url(:/img/"+figureColor+"Knight-whiteField.png);");
        currentFigureButton->setStyleSheet("background-color: #035623;\nborder: 1px solid black;");
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
        colision(button,"white");
        matchCoordinates();
    }
    else if(!whiteMove)
    {
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/blackKnight-blueField.png);");
        colision(button,"black");
        matchCoordinates();
    }


}

void Widget::bishopMovement(QPushButton *button)
{
    disableAllButons();

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
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/whiteBishop-blueField.png);");

        if(up!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                up++;
                coords="right";
                if(up=='9') break;
            }
            colision(button,"white",true);
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
                down--;
                coords="right";
                if(down=='0') break;
            }
            colision(button,"white",true);
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
                up++;
                coords="left";
                if(up=='9') break;
            }
            colision(button,"white",true);
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
                down--;
                coords="left";
                if(down=='0') break;
            }
            colision(button,"white",true);
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
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/blackBishop-blueField.png);");

        if(up!='x' && right!='x'){
            for(char i=right;i<='h';i++){
                firstCord=i;
                secondCord=up;
                coords=firstCord+secondCord;
                possibleMoves.push_back(coords);
                up++;
                coords="right";
                if(up=='9') break;
            }
            colision(button,"black",true);
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
                down--;
                coords="right";
                if(down=='0') break;
            }
            colision(button,"black",true);
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
                up++;
                coords="left";
                if(up=='9') break;
            }
            colision(button,"black",true);
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
                down--;
                coords="left";
                if(down=='0') break;
            }
            colision(button,"black",true);
            up=storageUp;
            down=storageDown;
            left=storageLeft;
            right=storageRight;
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }
    }

    matchCoordinates();
    possibleMovesStorage.clear();
}

void Widget::rookMovement(QPushButton *button)
{
    disableAllButons();

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
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/whiteRook-blueField.png);");

        if(up!='x'){
            for(char i=up;i<='8';i++){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                coords="up";
            }
            colision(button,"white",true);
        }
        if(down!='x'){
            for(char i=down;i>='1';i--){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                coords="down";
            }
            colision(button,"white",true);
        }
        if(right!='x'){
            for(char i=right;i<='h';i++){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                coords="right";
            }
            colision(button,"white",true);
        }
        if(left!='x'){
            for(char i=left;i>='a';i--){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                coords="left";
            }
            colision(button,"white",true);
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }
    }
    else if(!whiteMove)
    {
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/blackRook-blueField.png);");

        if(up!='x'){
            for(char i=up;i<='8';i++){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                coords="up";
            }
            colision(button,"black",true);
        }
        if(down!='x'){
            for(char i=down;i>='1';i--){
                coords=firstCordButton+i;
                possibleMoves.push_back(coords);
                coords="down";
            }
            colision(button,"black",true);
        }
        if(right!='x'){
            for(char i=right;i<='h';i++){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                coords="right";
            }
            colision(button,"black",true);
        }
        if(left!='x'){
            for(char i=left;i>='a';i--){
                coords=i+secondCordButton;
                possibleMoves.push_back(coords);
                coords="left";
            }
            colision(button,"black",true);
        }

        for(int i=0;i<possibleMovesStorage.size();i++){         // taking avaiable moves from memory, that sets in colision function
            possibleMoves.push_back(possibleMovesStorage.at(i));
        }
    }

    matchCoordinates();
    possibleMovesStorage.clear();
}

void Widget::queenMovement(QPushButton *button)
{
    disableAllButons();
    QVector <QString> connectMoves;

    bishopMovement(button);
    for(int i=0;i<possibleMoves.size();i++){
        connectMoves.push_back(possibleMoves.at(i));
    }
    possibleMoves.clear();
    rookMovement(button);

    for(int i=0;i<connectMoves.size();i++){
        possibleMoves.push_back(connectMoves.at(i));
    }

    if(whiteMove)
    {
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/whiteQueen-blueField.png);");
    }
    else if(!whiteMove)
    {
        button->setEnabled(true);
        button->setStyleSheet("background-image: url(:/img/blackQueen-blueField.png);");
    }

    matchCoordinates();
    possibleMovesStorage.clear();
}
void Widget::kingMovement(QPushButton *button)
{

}