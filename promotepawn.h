#ifndef PROMOTEPAWN_H
#define PROMOTEPAWN_H

#include <QDialog>


namespace Ui {
class PromotePawn;
}

class PromotePawn : public QDialog
{
    Q_OBJECT

public:
    explicit PromotePawn(QWidget *parent = nullptr);
    QString choosenFigure;
    QString color;


    ~PromotePawn();

private slots:
    void on_knight_clicked();
    void on_bishop_clicked();
    void on_rook_clicked();
    void on_queen_clicked();

private:
 Ui::PromotePawn *ui;

};

#endif // PROMOTEPAWN_H
