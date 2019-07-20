#include "widget.h"
#include "ui_widget.h"


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
