#include "promotepawn.h"
#include "ui_promotepawn.h"
#include <QDebug>


PromotePawn::PromotePawn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PromotePawn)
{
    ui->setupUi(this);

    if(color == "white"){
        ui->knight->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteKnight-whiteField.png);"));
        ui->bishop->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteBishop-whiteField.png);"));
        ui->rook->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteRook-whiteField.png);"));
        ui->queen->setStyleSheet(QString::fromUtf8("background-image: url(:/img/whiteQueen-whiteField.png);"));
    }else{
        ui->knight->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackKnight-whiteField.png);"));
        ui->bishop->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackBishop-whiteField.png);"));
        ui->rook->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackRook-whiteField.png);"));
        ui->queen->setStyleSheet(QString::fromUtf8("background-image: url(:/img/blackQueen-whiteField.png);"));
    }
}

PromotePawn::~PromotePawn()
{
    delete ui;
}

void PromotePawn::on_knight_clicked()
{
    choosenFigure = "Knight";
    this->close();
}

void PromotePawn::on_bishop_clicked()
{
    choosenFigure = "Bishop";
    this->close();
}

void PromotePawn::on_rook_clicked()
{
    choosenFigure = "Rook";
    this->close();
}

void PromotePawn::on_queen_clicked()
{
    choosenFigure = "Queen";
    this->close();
}




