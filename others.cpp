#include "widget.h"
#include "ui_widget.h"

void Widget::setStartingParameters()
{
    numberOfMove = 1;
    whiteMove = true; 
    action = false;
    isItCheck = false;
    isItCheckMate = false;




    //Adding pieces to vectors
    QString whitePoon_whiteField = "background-image: url(:/img/whitePoon-whiteField.png);";
    QString whitePoon_greenField = "background-image: url(:/img/whitePoon-greenField.png);";
    QString whiteBishop_whiteField = "background-image: url(:/img/whiteBishop-whiteField.png);";
    QString whiteBishop_greenField = "background-image: url(:/img/whiteBishop-greenField.png);";
    QString whiteKnight_whiteField ="background-image: url(:/img/whiteKnight-whiteField.png);";
    QString whiteKnight_greenField ="background-image: url(:/img/whiteKnight-greenField.png);";

    QString whiteRook_whiteField = "background-image: url(:/img/whiteRook-whiteField.png);";
    QString whiteRook_greenField = "background-image: url(:/img/whiteRook-greenField.png);";
    QString whiteQueen_whiteField = "background-image: url(:/img/whiteQueen-whiteField.png);";
    QString whiteQueen_greenField = "background-image: url(:/img/whiteQueen-greenField.png);";
    QString whiteKing_whiteField =  "background-image: url(:/img/whiteKing-whiteField.png);";
    QString whiteKing_greenField =  "background-image: url(:/img/whiteKing-greenField.png);";
    QString whiteKing_redField =  "background-image: url(:/img/whiteKing-redField.png);";

    whiteFigures.push_back(whitePoon_whiteField);
    whiteFigures.push_back(whitePoon_greenField);
    whiteFigures.push_back(whiteBishop_whiteField);
    whiteFigures.push_back(whiteBishop_greenField);
    whiteFigures.push_back(whiteKnight_whiteField);
    whiteFigures.push_back(whiteKnight_greenField);
    whiteFigures.push_back(whiteRook_whiteField);
    whiteFigures.push_back(whiteRook_greenField);
    whiteFigures.push_back(whiteQueen_whiteField);
    whiteFigures.push_back(whiteQueen_greenField);
    whiteFigures.push_back(whiteKing_whiteField);
    whiteFigures.push_back(whiteKing_greenField);
    whiteFigures.push_back(whiteKing_redField);

    QString blackPoon_whiteField = "background-image: url(:/img/blackPoon-whiteField.png);";
    QString blackPoon_greenField = "background-image: url(:/img/blackPoon-greenField.png);";
    QString blackBishop_whiteField = "background-image: url(:/img/blackBishop-whiteField.png);";
    QString blackBishop_greenField = "background-image: url(:/img/blackBishop-greenField.png);";
    QString blackKnight_whiteField ="background-image: url(:/img/blackKnight-whiteField.png);";
    QString blackKnight_greenField ="background-image: url(:/img/blackKnight-greenField.png);";

    QString blackRook_whiteField = "background-image: url(:/img/blackRook-whiteField.png);";
    QString blackRook_greenField = "background-image: url(:/img/blackRook-greenField.png);";
    QString blackQueen_whiteField = "background-image: url(:/img/blackQueen-whiteField.png);";
    QString blackQueen_greenField = "background-image: url(:/img/blackQueen-greenField.png);";
    QString blackKing_whiteField =  "background-image: url(:/img/blackKing-whiteField.png);";
    QString blackKing_greenField =  "background-image: url(:/img/blackKing-greenField.png);";
    QString blackKing_redField =  "background-image: url(:/img/blackKing-redField.png);";

    blackFigures.push_back(blackPoon_whiteField);
    blackFigures.push_back(blackPoon_greenField);
    blackFigures.push_back(blackBishop_whiteField);
    blackFigures.push_back(blackBishop_greenField);
    blackFigures.push_back(blackKnight_whiteField);
    blackFigures.push_back(blackKnight_greenField);
    blackFigures.push_back(blackRook_whiteField);
    blackFigures.push_back(blackRook_greenField);
    blackFigures.push_back(blackQueen_whiteField);
    blackFigures.push_back(blackQueen_greenField);
    blackFigures.push_back(blackKing_whiteField);
    blackFigures.push_back(blackKing_greenField);
    blackFigures.push_back(blackKing_redField);

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

    whitePoon1 = ui->a2;
    whitePoon2 = ui->b2;
    whitePoon3 = ui->c2;
    whitePoon4 = ui->d2;
    whitePoon5 = ui->e2;
    whitePoon6 = ui->f2;
    whitePoon7 = ui->g2;
    whitePoon8 = ui->h2;

    //white figures
    ui->c1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteBishop-whiteField.png);"));
    ui->f1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteBishop-greenField.png);"));
    ui->b1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteKnight-greenField.png);"));
    ui->g1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteKnight-whiteField.png);"));

    whiteKnight1 = ui->b1;
    whiteKnight2 = ui->g1;
    whiteBishop1 = ui->c1;
    whiteBishop2 = ui->f1;

    ui->a1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteRook-whiteField.png);"));
    ui->h1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteRook-greenField.png);"));
    ui->d1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteQueen-greenField.png);"));
    ui->e1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteKing-whiteField.png);"));

    whiteRook1 = ui->a1;
    whiteRook2 = ui->h1;
    whiteQueen = ui->d1;
    whiteKing  = ui->e1;

    //black poons
    ui->b7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->a7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));
    ui->d7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->c7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));
    ui->f7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->e7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));
    ui->h7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-greenField.png);"));
    ui->g7->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackPoon-whiteField.png);"));

    blackPoon1 = ui->a7;
    blackPoon2 = ui->b7;
    blackPoon3 = ui->c7;
    blackPoon4 = ui->d7;
    blackPoon5 = ui->e7;
    blackPoon6 = ui->f7;
    blackPoon7 = ui->g7;
    blackPoon8 = ui->h7;

    //black figures
    ui->f8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackBishop-whiteField.png);"));
    ui->c8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackBishop-greenField.png);"));
    ui->g8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackKnight-greenField.png);"));
    ui->b8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackKnight-whiteField.png);"));

    blackKnight1 = ui->b8;
    blackKnight2 = ui->g8;
    blackBishop1 = ui->c8;
    blackBishop2 = ui->f8;

    ui->h8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackRook-whiteField.png);"));
    ui->a8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackRook-greenField.png);"));
    ui->d8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackQueen-whiteField.png);"));
    ui->e8->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackKing-greenField.png);"));

    blackRook1 = ui->a8;
    blackRook2 = ui->h8;
    blackQueen = ui->d8;
    blackKing  = ui->e8;


    whitePoon2 =nullptr;
    //adding pointers of pieces to vectors

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


Widget::~Widget()
{
    delete ui;
}

