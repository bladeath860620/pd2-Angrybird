#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = 0);
    ~Result();
    void showScore(int);
    void showText(int, int, int);

private:
    Ui::Result *ui;
};

#endif // RESULT_H
