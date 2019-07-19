#include "widget.h"
#include "ui_widget.h"

void Widget::setStartingParameters()
{
    whiteMove = true;
    numberOfMoves = 0;




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
    whiteFigures.push_back(blackKing_redField);

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


Widget::~Widget()
{
    delete ui;
}

