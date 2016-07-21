#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_buttonBox_accepted()
{
    cout << "Update to parameters\n";
    params par;

    par.tr_name = ui->tr_nameTracker->text().toUtf8().constData();
    par.cap_auxCam = ui->cap_auxCam->text().toUtf8().constData();

    par.cap_binSize = ui->cap_binSize->text().toUInt();
    par.cap_camID_IDS = ui->cap_camID_IDS->text().toUInt();
    par.cap_colsAux = ui->cap_colsAux->text().toUtf8().toUInt();
    par.cap_fpsAux = ui->cap_fpsAux->text().toUtf8().toUInt();
    par.cap_fpsEndo = ui->cap_fps_endo->text().toUtf8().toUInt();
    par.cap_queueSize = ui->cap_queueSize->text().toUtf8().toUInt();
    par.cap_rowsAux = ui->cap_rowAux->text().toUtf8().toUInt();
    par.cap_rowsEndo = ui->cap_rows_endo->text().toUtf8().toUInt();

    // setting the capture path;
    string input = ui->cap_path->text().toUtf8().constData();
    std::istringstream ss(input);
    std::string token;
    while(std::getline(ss, token, ','))
    {
        par.cap_paths.push_back(token);
    }

    emit makeUpdateParams(par);

}

void settings::on_buttonBox_rejected()
{
    cout << "No update to parameters\n";
}
