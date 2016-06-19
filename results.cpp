#include "results.h"
#include "ui_results.h"

Results::Results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
    Media = new QMediaPlayer;
}

Results::~Results()
{
    delete ui;
}

void Results::showScore(int score)
{
    ui->lcdNumber->display(score);
}

void Results::showText(int pignum, int score, int birdnum)
{
    if(pignum == 0 && score == 33000 && birdnum == 0)
    {
        ui->label_2->setText("BIG SUCCESS !!! (but you used the HACK...)");
        Media->setMedia(QUrl("qrc:/snd/sound effects/victory.wav"));
        Media->play();
    }
    else if(pignum == 0)
    {
        ui->label_2->setText("BIG SUCCESS !!! And you didn't rely on the HACK !!!");
        Media->setMedia(QUrl("qrc:/snd/sound effects/victory.wav"));
        Media->play();
    }
    else
    {
        ui->label_2->setText("FAILURE...Seriously???");
        Media->setMedia(QUrl("qrc:/snd/sound effects/defeat.wav"));
        Media->play();
    }
}
