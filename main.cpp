#include <QPixmap>
#include "qmainwindow.h"
#include "settings_main.h"
#include <QApplication>
#include <QSplashScreen>
#include <qthread.h>

class I : public QThread
{
public:
    static void sleep(unsigned long secs) { QThread::sleep(secs); }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPixmap pixmap("endo.png");
    QSplashScreen splash(pixmap);
    splash.show();
    app.processEvents();
    I::sleep(1);

    settings_main settingObj;
    settingObj.setWindowTitle("Neuro-Endo-Trainer");
//    settingObj.setWindowFlags((Qt::Dialog | Qt::Desktop)); // source of error. took my whole goddamm day
    settingObj.setFixedSize(920, 666);
    settingObj.show();
    splash.finish(&settingObj);

    return app.exec();
}
