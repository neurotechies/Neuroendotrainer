#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <iostream>
#include <sstream>
#include "params.h"

using namespace std;

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

signals:
    void makeUpdateParams(const params &);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
