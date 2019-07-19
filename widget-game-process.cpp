#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setStartingParameters();
    placePiecesOnBoard();
}

void Widget::on_startGameButton_clicked(){
    ui->startGameButton->setEnabled(false);
}
