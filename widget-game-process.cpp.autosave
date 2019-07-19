#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    disableAllButons();

    setStartingParameters();
    placePiecesOnBoard();
    renderFiguresPosition();
}

void Widget::on_startGameButton_clicked(){
    ui->startGameButton->setEnabled(false);
    enableWhiteButtons();
}
