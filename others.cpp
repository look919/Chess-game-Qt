#include "widget.h"
#include "ui_widget.h"

void Widget::setStartingParameters()
{
    numberOfMove = 1;
    whiteMove = true; 
    action = false;
    isItCheck = false;
    isItCheckMate = false;
    enPassant = false;
    whiteCastleShort = true;
    whiteCastleLong = true;
    blackCastleShort = true;
    blackCastleLong = true;


    QString blackPoon_blueField = "background-image: url(:/img/blackPoon-blueField.png);";
    QString whitePoon_blueField = "background-image: url(:/img/blackPoon-blueField.png);";
    QString blackBishop_blueField = "background-image: url(:/img/blackBishop-blueField.png);";
    QString whiteBishop_blueField = "background-image: url(:/img/whiteBishop-blueField.png);";
    QString blackKnight_blueField ="background-image: url(:/img/blackKnight-blueField.png);";
    QString whiteKnight_blueField ="background-image: url(:/img/whiteKnight-blueField.png);";

    QString blackRook_blueField = "background-image: url(:/img/blackRook-blueField.png);";
    QString whiteRook_blueField = "background-image: url(:/img/whiteRook-blueField.png);";
    QString blackQueen_blueField = "background-image: url(:/img/blackQueen-blueField.png);";
    QString whiteQueen_blueField = "background-image: url(:/img/whiteQueen-blueField.png);";
    QString blackKing_blueField =  "background-image: url(:/img/blackKing-blueField.png);";
    QString whiteKing_blueField =  "background-image: url(:/img/whiteKing-blueField.png);";

    blueFigures.push_back(blackPoon_blueField);
    blueFigures.push_back(whitePoon_blueField);
    blueFigures.push_back(blackBishop_blueField);
    blueFigures.push_back(whiteBishop_blueField);
    blueFigures.push_back(blackKnight_blueField);
    blueFigures.push_back(whiteKnight_blueField);
    blueFigures.push_back(blackRook_blueField);
    blueFigures.push_back(whiteRook_blueField);
    blueFigures.push_back(blackQueen_blueField);
    blueFigures.push_back(whiteQueen_blueField);
    blueFigures.push_back(blackKing_blueField);
    blueFigures.push_back(whiteKing_blueField);


}
void Widget::placePiecesOnBoard()
{
    //white poons
    ui->a2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-greenField.png);"));
    ui->b2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-whiteField.png);"));
    ui->c2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-greenField.png);"));
    ui->d2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-whiteField.png);"));
    ui->e2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-greenField.png);"));
    ui->f2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-whiteField.png);"));
    ui->g2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-greenField.png);"));
    ui->h2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whitePoon-whiteField.png);"));


    //white figures
    ui->c1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteBishop-whiteField.png);"));
    ui->f1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteBishop-greenField.png);"));
    ui->b1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteKnight-greenField.png);"));
    ui->g1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteKnight-whiteField.png);"));


    ui->a1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteRook-whiteField.png);"));
    ui->h1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteRook-greenField.png);"));
    ui->d1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteQueen-greenField.png);"));
    ui->e1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteKing-whiteField.png);"));



    //black poons
    ui->b7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->a7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));
    ui->d7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->c7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));
    ui->f7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->e7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));
    ui->h7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->g7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));

    //black figures
    ui->f8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackBishop-whiteField.png);"));
    ui->c8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackBishop-greenField.png);"));
    ui->g8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackKnight-greenField.png);"));
    ui->b8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackKnight-whiteField.png);"));



    ui->h8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackRook-whiteField.png);"));
    ui->a8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackRook-greenField.png);"));
    ui->d8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackQueen-whiteField.png);"));
    ui->e8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackKing-greenField.png);"));



}
void Widget::setFiguresPosition()
{
        whiteFiguresButtons.clear();
        //whiteFiguresButtons
        whiteFiguresButtons.push_back(ui->a2);
        whiteFiguresButtons.push_back(ui->b2);
        whiteFiguresButtons.push_back(ui->c2);
        whiteFiguresButtons.push_back(ui->d2);
        whiteFiguresButtons.push_back(ui->e2);
        whiteFiguresButtons.push_back(ui->f2);
        whiteFiguresButtons.push_back(ui->g2);
        whiteFiguresButtons.push_back(ui->h2);
        whiteFiguresButtons.push_back(ui->b1);
        whiteFiguresButtons.push_back(ui->g1);
        whiteFiguresButtons.push_back(ui->c1);
        whiteFiguresButtons.push_back(ui->f1);
        whiteFiguresButtons.push_back(ui->a1);
        whiteFiguresButtons.push_back(ui->h1);
        whiteFiguresButtons.push_back(ui->d1);
        whiteFiguresButtons.push_back(ui->e1);

        blackFiguresButtons.clear();
        //blackFiguresButtons
        blackFiguresButtons.push_back(ui->a7);
        blackFiguresButtons.push_back(ui->b7);
        blackFiguresButtons.push_back(ui->c7);
        blackFiguresButtons.push_back(ui->d7);
        blackFiguresButtons.push_back(ui->e7);
        blackFiguresButtons.push_back(ui->f7);
        blackFiguresButtons.push_back(ui->g7);
        blackFiguresButtons.push_back(ui->h7);
        blackFiguresButtons.push_back(ui->b8);
        blackFiguresButtons.push_back(ui->g8);
        blackFiguresButtons.push_back(ui->c8);
        blackFiguresButtons.push_back(ui->f8);
        blackFiguresButtons.push_back(ui->a8);
        blackFiguresButtons.push_back(ui->h8);
        blackFiguresButtons.push_back(ui->d8);
        blackFiguresButtons.push_back(ui->e8);
}



void Widget::whiteHistory(QPushButton *button)
{
    if(numberOfMove==1 || numberOfMove ==31 || numberOfMove == 61){
        ui->gameHistory_black->clear();
        ui->gameHistory_white->clear();
        ui->gameHistory_numberOfMove->clear();
        matchHistory_black.clear();
        matchHistory_white.clear();
        matchHistory_numberOfMove.clear();

        text ="\n";
        matchHistory_black+=text;
        ui->gameHistory_black->setText(matchHistory_black);
        ui->gameHistory_black->setAlignment(Qt::AlignCenter);

        matchHistory_white+=text;
        ui->gameHistory_white->setText(matchHistory_white);
        ui->gameHistory_white->setAlignment(Qt::AlignCenter);

        matchHistory_numberOfMove+=text;
        ui->gameHistory_numberOfMove->setText(matchHistory_numberOfMove);
        ui->gameHistory_numberOfMove->setAlignment(Qt::AlignCenter);
    }

    if(currentFigure == "poon"){                                                        //Setting information about last move on the board
            text=QString("%1.\n").arg(numberOfMove);

            matchHistory_numberOfMove +=text;
            ui->gameHistory_numberOfMove->setText(matchHistory_numberOfMove);
            ui->gameHistory_numberOfMove->setAlignment(Qt::AlignCenter);

            text = QString("%1-%2 \n").arg(currentFigureButton->objectName()).arg(button->objectName());
            matchHistory_white+= text;
            ui->gameHistory_white->setText(matchHistory_white);
            ui->gameHistory_white->setAlignment(Qt::AlignCenter);


        }
    else if(currentFigure == "Knight"){

            text=QString("%1.\n").arg(numberOfMove);
            matchHistory_numberOfMove+=text;
            ui->gameHistory_numberOfMove->setText(matchHistory_numberOfMove);
            ui->gameHistory_numberOfMove->setAlignment(Qt::AlignCenter);

            text = QString("N%1-%2 \n").arg(currentFigureButton->objectName()).arg(button->objectName());
            matchHistory_white+=text;
            ui->gameHistory_white->setText(matchHistory_white);
            ui->gameHistory_white->setAlignment(Qt::AlignCenter);

        }
    else if(currentFigure == "King" && (coords=="short" || coords == "long")){

        text=QString("%1.\n").arg(numberOfMove);

        matchHistory_numberOfMove+=text;
        ui->gameHistory_numberOfMove->setText(matchHistory_numberOfMove);
        ui->gameHistory_numberOfMove->setAlignment(Qt::AlignCenter);

        if(coords=="short") text = QString("O-O\n");
        if(coords=="long") text = QString("O-O-O\n");

        matchHistory_white+=text;
        ui->gameHistory_white->setText(matchHistory_white);
        ui->gameHistory_white->setAlignment(Qt::AlignCenter);
    }
    else
    {
        text=QString("%1.\n").arg(numberOfMove);
        matchHistory_numberOfMove+=text;
        ui->gameHistory_numberOfMove->setText(matchHistory_numberOfMove);
        ui->gameHistory_numberOfMove->setAlignment(Qt::AlignCenter);

        text = QString("%1%2-%3 \n").arg(currentFigure[0]).arg(currentFigureButton->objectName()).arg(button->objectName());
        matchHistory_white+=text;
        ui->gameHistory_white->setText(matchHistory_white);
        ui->gameHistory_white->setAlignment(Qt::AlignCenter);
    }
}
void Widget::blackHistory(QPushButton *button)
{
    if(currentFigure == "poon"){                                                        //Setting information about last move on the board
           text = QString("%1-%2 \n").arg(currentFigureButton->objectName()).arg(button->objectName());
           matchHistory_black+=text;
           ui->gameHistory_black->setText(matchHistory_black);
           ui->gameHistory_black->setAlignment(Qt::AlignCenter);
        }
    else if(currentFigure == "Knight"){
           text = QString("N%1-%2 \n").arg(currentFigureButton->objectName()).arg(button->objectName());
           matchHistory_black+=text;
           ui->gameHistory_black->setText(matchHistory_black);
           ui->gameHistory_black->setAlignment(Qt::AlignCenter);
        }
    else if(currentFigure == "King" && (coords=="short" || coords == "long")){

        if(coords=="short") text = "O-O\n";
        if(coords=="long") text = "O-O-O\n";

        matchHistory_black+=text;
        ui->gameHistory_black->setText(matchHistory_black);
        ui->gameHistory_black->setAlignment(Qt::AlignCenter);
    }
    else
        {
           text = QString("%1%2-%3 \n").arg(currentFigure[0]).arg(currentFigureButton->objectName()).arg(button->objectName());
           matchHistory_black+=text;
           ui->gameHistory_black->setText(matchHistory_black);
           ui->gameHistory_black->setAlignment(Qt::AlignCenter);
        }
}

void Widget::isKingChecked(QPushButton *button)
{
    if(!whiteMove){
        for(int i=0;i<possibleMoves.size();i++){
            if(whiteFiguresButtons[15]->objectName() == possibleMoves.at(i)){
                isItCheck = true;
                if(currentFigure == "Knight" || currentFigure == "poon") checkingMoves.push_back(button->objectName());
                else if(currentFigure == "Bishop" || currentFigure == "Rook" || currentFigure == "Queen") {

                    checkingMoves.push_back(button->objectName());
                    for(int j=0;j<possibleMoves.size();j++){
                        checkingMoves.push_back(possibleMoves.at(j));
                    }

                }

                break;
            }
        }

    }
    else if(whiteMove){
        for(int i=0;i<possibleMoves.size();i++){
            if(blackFiguresButtons[15]->objectName() == possibleMoves.at(i)){
                isItCheck = true;

                if(currentFigure == "Knight" || currentFigure == "poon") checkingMoves.push_back(button->objectName());
                else if(currentFigure == "Bishop" || currentFigure == "Rook" || currentFigure == "Queen") {

                    checkingMoves.push_back(button->objectName());
                    for(int j=0;j<possibleMoves.size();j++){
                        checkingMoves.push_back(possibleMoves.at(j));
                    }
                }

                break;
            }
        }

    }
}

void Widget::isKingMated()
{
    qDebug()<<"GGGGGG";
    disableAllButons();
    if(whiteMove)
    {
        ui->startGameButton->setStyleSheet("background-color: red;color:white;border: 1px solid blue; border-radius: 25px;");
        ui->startGameButton->setText("Black Won!");
    }
    else if(!whiteMove)
    {
        ui->startGameButton->setStyleSheet("background-color: red;color:white;border: 1px solid blue; border-radius: 25px;");
        ui->startGameButton->setText("White Won!");
    }
}

void Widget::markKings()
{
    if(whiteMove){
        if(isItCheck){
            whiteFiguresButtons[15]->setStyleSheet("background-image: url(:/img/whiteKing-redField.png);");
        }else if(!isItCheck && whiteFiguresButtons[15]->font().bold()){
            whiteFiguresButtons[15]->setStyleSheet("background-image: url(:/img/whiteKing-greenField.png);");
        }else if(!isItCheck && whiteFiguresButtons[15]->font().bold()==false){
            whiteFiguresButtons[15]->setStyleSheet("background-image: url(:/img/whiteKing-whiteField.png);");
        }

        if(blackFiguresButtons[15]->font().bold()) blackFiguresButtons[15]->setStyleSheet("background-image: url(:/img/blackKing-greenField.png);");
        else if(blackFiguresButtons[15]->font().bold()==false) blackFiguresButtons[15]->setStyleSheet("background-image: url(:/img/blackKing-whiteField.png);");
    }
    else if(!whiteMove)
    {
        if(isItCheck){
            blackFiguresButtons[15]->setStyleSheet("background-image: url(:/img/blackKing-redField.png);");
        }else if(!isItCheck && blackFiguresButtons[15]->font().bold()){
            blackFiguresButtons[15]->setStyleSheet("background-image: url(:/img/blackKing-greenField.png);");
        }else if(!isItCheck && blackFiguresButtons[15]->font().bold()==false){
            blackFiguresButtons[15]->setStyleSheet("background-image: url(:/img/blackKing-whiteField.png);");
        }

        if(whiteFiguresButtons[15]->font().bold()) whiteFiguresButtons[15]->setStyleSheet("background-image: url(:/img/whiteKing-greenField.png);");
        else if(whiteFiguresButtons[15]->font().bold()==false) whiteFiguresButtons[15]->setStyleSheet("background-image: url(:/img/whiteKing-whiteField.png);");
    }
}

Widget::~Widget()
{
    delete ui;
}

