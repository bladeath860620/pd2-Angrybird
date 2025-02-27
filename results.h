#ifndef RESULTS_H
#define RESULTS_H

#include <QDialog>
#include "pointtransfer.h"
namespace Ui {
class Results;
}

class Results : public QDialog
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = 0);
    ~Results();
    void showScore(int);
    void showText(int, int, int);

private:
    Ui::Results *ui;
    QMediaPlayer *Media;
};

#endif // RESULTS_H
