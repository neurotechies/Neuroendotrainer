/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QDialogButtonBox *buttonBox;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLineEdit *cap_path;
    QLabel *label_22;
    QLineEdit *cap_auxCam;
    QLabel *label_9;
    QLineEdit *cap_queueSize;
    QLabel *label_10;
    QLineEdit *cap_binSize;
    QLabel *label_13;
    QLineEdit *cap_rowAux;
    QLabel *label_12;
    QLineEdit *cap_fpsAux;
    QLineEdit *cap_colsAux;
    QLabel *label_11;
    QLineEdit *cap_camID_IDS;
    QLabel *label_15;
    QLineEdit *cap_rows_endo;
    QLabel *label_18;
    QLineEdit *cap_cols_endo;
    QLabel *label_14;
    QLabel *label_20;
    QLineEdit *cap_fps_endo;
    QWidget *page_2;
    QLabel *label_23;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QLabel *label_24;
    QLineEdit *tr_nameTracker;
    QWidget *page_4;
    QLabel *label_39;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QStringLiteral("settings"));
        settings->resize(758, 503);
        settings->setStyleSheet(QStringLiteral("background-color: rgb(19, 5, 5);"));
        buttonBox = new QDialogButtonBox(settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(150, 460, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget = new QStackedWidget(settings);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 40, 339, 421));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        cap_path = new QLineEdit(page);
        cap_path->setObjectName(QStringLiteral("cap_path"));
        cap_path->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_path, 0, 1, 1, 1);

        label_22 = new QLabel(page);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_22, 1, 0, 1, 1);

        cap_auxCam = new QLineEdit(page);
        cap_auxCam->setObjectName(QStringLiteral("cap_auxCam"));
        cap_auxCam->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_auxCam, 1, 1, 1, 1);

        label_9 = new QLabel(page);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        cap_queueSize = new QLineEdit(page);
        cap_queueSize->setObjectName(QStringLiteral("cap_queueSize"));
        cap_queueSize->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_queueSize, 2, 1, 1, 1);

        label_10 = new QLabel(page);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_10, 3, 0, 1, 1);

        cap_binSize = new QLineEdit(page);
        cap_binSize->setObjectName(QStringLiteral("cap_binSize"));
        cap_binSize->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_binSize, 3, 1, 1, 1);

        label_13 = new QLabel(page);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        cap_rowAux = new QLineEdit(page);
        cap_rowAux->setObjectName(QStringLiteral("cap_rowAux"));
        cap_rowAux->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_rowAux, 4, 1, 1, 1);

        label_12 = new QLabel(page);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_12, 5, 0, 1, 1);

        cap_fpsAux = new QLineEdit(page);
        cap_fpsAux->setObjectName(QStringLiteral("cap_fpsAux"));
        cap_fpsAux->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_fpsAux, 6, 1, 1, 1);

        cap_colsAux = new QLineEdit(page);
        cap_colsAux->setObjectName(QStringLiteral("cap_colsAux"));
        cap_colsAux->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_colsAux, 5, 1, 1, 1);

        label_11 = new QLabel(page);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        cap_camID_IDS = new QLineEdit(page);
        cap_camID_IDS->setObjectName(QStringLiteral("cap_camID_IDS"));
        cap_camID_IDS->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_camID_IDS, 7, 1, 1, 1);

        label_15 = new QLabel(page);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_15, 7, 0, 1, 1);

        cap_rows_endo = new QLineEdit(page);
        cap_rows_endo->setObjectName(QStringLiteral("cap_rows_endo"));
        cap_rows_endo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_rows_endo, 8, 1, 1, 1);

        label_18 = new QLabel(page);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_18, 8, 0, 1, 1);

        cap_cols_endo = new QLineEdit(page);
        cap_cols_endo->setObjectName(QStringLiteral("cap_cols_endo"));
        cap_cols_endo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_cols_endo, 9, 1, 1, 1);

        label_14 = new QLabel(page);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_14, 9, 0, 1, 1);

        label_20 = new QLabel(page);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_20, 10, 0, 1, 1);

        cap_fps_endo = new QLineEdit(page);
        cap_fps_endo->setObjectName(QStringLiteral("cap_fps_endo"));
        cap_fps_endo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(cap_fps_endo, 10, 1, 1, 1);

        stackedWidget->addWidget(page);
        label_8->raise();
        cap_path->raise();
        label_9->raise();
        cap_queueSize->raise();
        label_10->raise();
        cap_binSize->raise();
        cap_fpsAux->raise();
        label_11->raise();
        cap_colsAux->raise();
        label_12->raise();
        cap_rowAux->raise();
        label_13->raise();
        cap_cols_endo->raise();
        cap_camID_IDS->raise();
        label_18->raise();
        cap_rows_endo->raise();
        label_15->raise();
        label_20->raise();
        cap_fps_endo->raise();
        label_14->raise();
        label_22->raise();
        cap_auxCam->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        label_23 = new QLabel(settings);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(130, 10, 169, 27));
        label_23->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        stackedWidget_2 = new QStackedWidget(settings);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(390, 40, 339, 51));
        stackedWidget_2->setStyleSheet(QStringLiteral(""));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_24 = new QLabel(page_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(label_24, 0, 0, 1, 1);

        tr_nameTracker = new QLineEdit(page_3);
        tr_nameTracker->setObjectName(QStringLiteral("tr_nameTracker"));
        tr_nameTracker->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(tr_nameTracker, 0, 1, 1, 1);

        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget_2->addWidget(page_4);
        label_39 = new QLabel(settings);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(480, 10, 169, 27));
        label_39->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        retranslateUi(settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Dialog", 0));
        label_8->setText(QApplication::translate("settings", "Capture path", 0));
#ifndef QT_NO_TOOLTIP
        cap_path->setToolTip(QApplication::translate("settings", "Set the full capture path. Separate by comma for multiple paths", 0));
#endif // QT_NO_TOOLTIP
        cap_path->setText(QApplication::translate("settings", "/home/terminalx/Desktop", 0));
        label_22->setText(QApplication::translate("settings", "Choose Auxiliary Camera", 0));
#ifndef QT_NO_TOOLTIP
        cap_auxCam->setToolTip(QApplication::translate("settings", "choose the auxiliry camera \"basler\" vs \"ids\"", 0));
#endif // QT_NO_TOOLTIP
        cap_auxCam->setText(QApplication::translate("settings", "basler", 0));
        label_9->setText(QApplication::translate("settings", "Queue Size", 0));
#ifndef QT_NO_TOOLTIP
        cap_queueSize->setToolTip(QApplication::translate("settings", "Size of the queue of fifo buffer", 0));
#endif // QT_NO_TOOLTIP
        cap_queueSize->setText(QApplication::translate("settings", "10", 0));
        label_10->setText(QApplication::translate("settings", "Bin Size", 0));
#ifndef QT_NO_TOOLTIP
        cap_binSize->setToolTip(QApplication::translate("settings", "No of images to dumped at one throgh", 0));
#endif // QT_NO_TOOLTIP
        cap_binSize->setText(QApplication::translate("settings", "1", 0));
        label_13->setText(QApplication::translate("settings", "Rows_Aux", 0));
#ifndef QT_NO_TOOLTIP
        cap_rowAux->setToolTip(QApplication::translate("settings", "No of Rows for the auxiliary camera", 0));
#endif // QT_NO_TOOLTIP
        cap_rowAux->setText(QApplication::translate("settings", "1024", 0));
        label_12->setText(QApplication::translate("settings", "Cols_Aux", 0));
#ifndef QT_NO_TOOLTIP
        cap_fpsAux->setToolTip(QApplication::translate("settings", "Frame rate for the auxiliary camera", 0));
#endif // QT_NO_TOOLTIP
        cap_fpsAux->setText(QApplication::translate("settings", "25", 0));
#ifndef QT_NO_TOOLTIP
        cap_colsAux->setToolTip(QApplication::translate("settings", "No of Cloumns for the auxiliary camera", 0));
#endif // QT_NO_TOOLTIP
        cap_colsAux->setText(QApplication::translate("settings", "1280", 0));
        label_11->setText(QApplication::translate("settings", "FrameRate_Aux", 0));
#ifndef QT_NO_TOOLTIP
        cap_camID_IDS->setToolTip(QApplication::translate("settings", "Camera ID for the IDS camera", 0));
#endif // QT_NO_TOOLTIP
        cap_camID_IDS->setText(QApplication::translate("settings", "2", 0));
        label_15->setText(QApplication::translate("settings", "CamID_IDS", 0));
#ifndef QT_NO_TOOLTIP
        cap_rows_endo->setToolTip(QApplication::translate("settings", "No of Rows for the Endoscopic camera", 0));
#endif // QT_NO_TOOLTIP
        cap_rows_endo->setText(QApplication::translate("settings", "720", 0));
        label_18->setText(QApplication::translate("settings", "Rows_Endo", 0));
#ifndef QT_NO_TOOLTIP
        cap_cols_endo->setToolTip(QApplication::translate("settings", "No of cols for the Endoscopic camera", 0));
#endif // QT_NO_TOOLTIP
        cap_cols_endo->setText(QApplication::translate("settings", "1280", 0));
        label_14->setText(QApplication::translate("settings", "Cols_Endo", 0));
        label_20->setText(QApplication::translate("settings", "Frame Rate Endo", 0));
#ifndef QT_NO_TOOLTIP
        cap_fps_endo->setToolTip(QApplication::translate("settings", "Frame rate for the Endoscopic camera", 0));
#endif // QT_NO_TOOLTIP
        cap_fps_endo->setText(QApplication::translate("settings", "25", 0));
        label_23->setText(QApplication::translate("settings", "Capture Settings", 0));
        label_24->setText(QApplication::translate("settings", "Tracker to be used", 0));
#ifndef QT_NO_TOOLTIP
        tr_nameTracker->setToolTip(QApplication::translate("settings", "choose tracker tld or markerBased", 0));
#endif // QT_NO_TOOLTIP
        tr_nameTracker->setText(QApplication::translate("settings", "tld", 0));
        label_39->setText(QApplication::translate("settings", "Tracker Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
