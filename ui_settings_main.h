/********************************************************************************
** Form generated from reading UI file 'settings_main.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_MAIN_H
#define UI_SETTINGS_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings_main
{
public:
    QLabel *label_status;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QPushButton *pbOnline;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QListWidget *listWidgetAuxOnline;
    QLabel *label_7;
    QListWidget *listWidgetEndoOnline;
    QLabel *label_endo;
    QLabel *label_aux;
    QLabel *label_8;
    QLabel *label_11;
    QCheckBox *checkBox;
    QSlider *horizontalSlider;
    QCheckBox *checkBox_2;
    QSlider *horizontalSlider_2;
    QWidget *page_2;
    QCheckBox *checkBoxRecordEndo;
    QCheckBox *checkBoxRecordAux;
    QCheckBox *checkBox_3;
    QLabel *label;
    QWidget *tab;
    QPushButton *pbOffline;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QLabel *label_10;
    QListWidget *listWidgetAuxOffline;
    QListWidget *listWidgetEndoOffline;
    QLabel *label_9;
    QLabel *label_endo_2;
    QLabel *label_aux_2;
    QLabel *label_12;
    QWidget *page_4;
    QWidget *tab_2;
    QListWidget *listWidgetPractice;
    QPushButton *pbPractice;
    QLabel *label_5;
    QLabel *label_endo_3;
    QLabel *label_13;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QComboBox *selectLevel;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditDrName;
    QPushButton *pbQuit;
    QPushButton *pbSettings;
    QPushButton *pbRefresh;

    void setupUi(QDialog *settings_main)
    {
        if (settings_main->objectName().isEmpty())
            settings_main->setObjectName(QStringLiteral("settings_main"));
        settings_main->resize(920, 662);
        settings_main->setToolTipDuration(1);
        settings_main->setStyleSheet(QStringLiteral("background-color: rgba(11, 11, 30, 147);"));
        label_status = new QLabel(settings_main);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(10, 620, 791, 31));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_status->setFont(font);
        label_status->setToolTipDuration(1);
        label_status->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(34, 15, 15);\n"
""));
        tabWidget = new QTabWidget(settings_main);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 881, 561));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(12, 12, 31);"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setMovable(false);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        pbOnline = new QPushButton(tab_5);
        pbOnline->setObjectName(QStringLiteral("pbOnline"));
        pbOnline->setEnabled(false);
        pbOnline->setGeometry(QRect(390, 480, 131, 41));
        pbOnline->setStyleSheet(QLatin1String("background-color: rgb(251, 250, 250);\n"
"color: rgb(16, 0, 0);"));
        stackedWidget = new QStackedWidget(tab_5);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 50, 871, 421));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        listWidgetAuxOnline = new QListWidget(page);
        listWidgetAuxOnline->setObjectName(QStringLiteral("listWidgetAuxOnline"));
        listWidgetAuxOnline->setGeometry(QRect(440, 30, 191, 51));
        listWidgetAuxOnline->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(470, 0, 141, 27));
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        listWidgetEndoOnline = new QListWidget(page);
        listWidgetEndoOnline->setObjectName(QStringLiteral("listWidgetEndoOnline"));
        listWidgetEndoOnline->setGeometry(QRect(90, 30, 191, 51));
        listWidgetEndoOnline->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_endo = new QLabel(page);
        label_endo->setObjectName(QStringLiteral("label_endo"));
        label_endo->setGeometry(QRect(0, 90, 350, 250));
        label_endo->setStyleSheet(QLatin1String("background-color: rgb(171, 161, 152);\n"
"border-color: rgb(109, 45, 239);"));
        label_aux = new QLabel(page);
        label_aux->setObjectName(QStringLiteral("label_aux"));
        label_aux->setGeometry(QRect(370, 90, 350, 250));
        label_aux->setStyleSheet(QLatin1String("background-color: rgb(171, 161, 152);\n"
"border-color: rgb(109, 45, 239);"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(120, 0, 141, 27));
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(page);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(260, 390, 341, 27));
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        checkBox = new QCheckBox(page);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(730, 100, 131, 22));
        checkBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        horizontalSlider = new QSlider(page);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(730, 130, 121, 20));
        horizontalSlider->setValue(25);
        horizontalSlider->setOrientation(Qt::Horizontal);
        checkBox_2 = new QCheckBox(page);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(730, 170, 131, 22));
        checkBox_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        horizontalSlider_2 = new QSlider(page);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(730, 200, 121, 20));
        horizontalSlider_2->setValue(34);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        checkBoxRecordEndo = new QCheckBox(tab_5);
        checkBoxRecordEndo->setObjectName(QStringLiteral("checkBoxRecordEndo"));
        checkBoxRecordEndo->setGeometry(QRect(100, 10, 221, 22));
        checkBoxRecordEndo->setStyleSheet(QLatin1String("color: rgba(255, 255, 255, 254);\n"
"background-color: rgb(27, 27, 45);"));
        checkBoxRecordEndo->setChecked(false);
        checkBoxRecordAux = new QCheckBox(tab_5);
        checkBoxRecordAux->setObjectName(QStringLiteral("checkBoxRecordAux"));
        checkBoxRecordAux->setGeometry(QRect(440, 10, 204, 22));
        checkBoxRecordAux->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(27, 27, 44);"));
        checkBox_3 = new QCheckBox(tab_5);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(100, 490, 16, 22));
        label = new QLabel(tab_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 490, 251, 20));
        tabWidget->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pbOffline = new QPushButton(tab);
        pbOffline->setObjectName(QStringLiteral("pbOffline"));
        pbOffline->setEnabled(false);
        pbOffline->setGeometry(QRect(380, 480, 131, 41));
        pbOffline->setStyleSheet(QLatin1String("background-color: rgb(251, 250, 250);\n"
"color: rgb(16, 0, 0);"));
        stackedWidget_2 = new QStackedWidget(tab);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(10, 50, 871, 421));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(120, 0, 141, 27));
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        listWidgetAuxOffline = new QListWidget(page_3);
        listWidgetAuxOffline->setObjectName(QStringLiteral("listWidgetAuxOffline"));
        listWidgetAuxOffline->setGeometry(QRect(550, 30, 211, 51));
        listWidgetAuxOffline->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        listWidgetEndoOffline = new QListWidget(page_3);
        listWidgetEndoOffline->setObjectName(QStringLiteral("listWidgetEndoOffline"));
        listWidgetEndoOffline->setGeometry(QRect(90, 30, 211, 51));
        listWidgetEndoOffline->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(580, 0, 141, 27));
        label_9->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_endo_2 = new QLabel(page_3);
        label_endo_2->setObjectName(QStringLiteral("label_endo_2"));
        label_endo_2->setGeometry(QRect(0, 90, 420, 300));
        label_endo_2->setStyleSheet(QLatin1String("background-color: rgb(171, 161, 152);\n"
"border-color: rgb(109, 45, 239);"));
        label_aux_2 = new QLabel(page_3);
        label_aux_2->setObjectName(QStringLiteral("label_aux_2"));
        label_aux_2->setGeometry(QRect(440, 90, 420, 300));
        label_aux_2->setStyleSheet(QLatin1String("background-color: rgb(171, 161, 152);\n"
"border-color: rgb(109, 45, 239);"));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(250, 390, 341, 27));
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget_2->addWidget(page_4);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        listWidgetPractice = new QListWidget(tab_2);
        listWidgetPractice->setObjectName(QStringLiteral("listWidgetPractice"));
        listWidgetPractice->setGeometry(QRect(310, 50, 191, 51));
        listWidgetPractice->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pbPractice = new QPushButton(tab_2);
        pbPractice->setObjectName(QStringLiteral("pbPractice"));
        pbPractice->setEnabled(false);
        pbPractice->setGeometry(QRect(360, 480, 131, 41));
        pbPractice->setStyleSheet(QLatin1String("background-color: rgb(251, 250, 250);\n"
"color: rgb(16, 0, 0);"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 20, 141, 27));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_endo_3 = new QLabel(tab_2);
        label_endo_3->setObjectName(QStringLiteral("label_endo_3"));
        label_endo_3->setGeometry(QRect(210, 110, 420, 300));
        label_endo_3->setStyleSheet(QLatin1String("background-color: rgb(171, 161, 152);\n"
"border-color: rgb(109, 45, 239);"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(260, 420, 341, 27));
        label_13->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 534, 63));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(570, 40, 141, 41));
        tabWidget->addTab(tab_3, QString());
        selectLevel = new QComboBox(settings_main);
        selectLevel->setObjectName(QStringLiteral("selectLevel"));
        selectLevel->setGeometry(QRect(670, 4, 241, 27));
        selectLevel->setStyleSheet(QLatin1String("color: rgb(30, 11, 11);\n"
"background-color: rgb(251, 250, 250);"));
        label_2 = new QLabel(settings_main);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 10, 139, 17));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(settings_main);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(580, 10, 82, 17));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEditDrName = new QLineEdit(settings_main);
        lineEditDrName->setObjectName(QStringLiteral("lineEditDrName"));
        lineEditDrName->setGeometry(QRect(270, 4, 301, 27));
        lineEditDrName->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pbQuit = new QPushButton(settings_main);
        pbQuit->setObjectName(QStringLiteral("pbQuit"));
        pbQuit->setGeometry(QRect(810, 620, 99, 31));
        pbQuit->setStyleSheet(QLatin1String("color: rgb(255, 236, 236);\n"
"background-color: rgb(245, 18, 18);"));
        pbSettings = new QPushButton(settings_main);
        pbSettings->setObjectName(QStringLiteral("pbSettings"));
        pbSettings->setGeometry(QRect(10, 4, 99, 31));
        pbSettings->setStyleSheet(QLatin1String("color: rgb(255, 236, 236);\n"
"background-color: rgb(95, 151, 95);"));
        pbRefresh = new QPushButton(settings_main);
        pbRefresh->setObjectName(QStringLiteral("pbRefresh"));
        pbRefresh->setGeometry(QRect(800, 40, 99, 31));
        pbRefresh->setStyleSheet(QLatin1String("color: rgb(255, 236, 236);\n"
"background-color: rgb(3, 3, 3);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Refresh.png"), QSize(), QIcon::Normal, QIcon::On);
        pbRefresh->setIcon(icon);
        selectLevel->raise();
        label_3->raise();
        lineEditDrName->raise();
        tabWidget->raise();
        label_status->raise();
        label_2->raise();
        pbQuit->raise();
        pbSettings->raise();
        pbRefresh->raise();
        QWidget::setTabOrder(tabWidget, selectLevel);
        QWidget::setTabOrder(selectLevel, lineEditDrName);
        QWidget::setTabOrder(lineEditDrName, pbOffline);

        retranslateUi(settings_main);

        tabWidget->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(settings_main);
    } // setupUi

    void retranslateUi(QDialog *settings_main)
    {
        settings_main->setWindowTitle(QApplication::translate("settings_main", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        label_status->setToolTip(QApplication::translate("settings_main", "Status", 0));
#endif // QT_NO_TOOLTIP
        label_status->setText(QString());
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("settings_main", "Choose tab according to usage", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbOnline->setToolTip(QApplication::translate("settings_main", "Run the application", 0));
#endif // QT_NO_TOOLTIP
        pbOnline->setText(QApplication::translate("settings_main", "Run", 0));
#ifndef QT_NO_TOOLTIP
        listWidgetAuxOnline->setToolTip(QApplication::translate("settings_main", "Auxiliary cameras will be diplayed here", 0));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("settings_main", "Auxiliary Cameras", 0));
#ifndef QT_NO_TOOLTIP
        listWidgetEndoOnline->setToolTip(QApplication::translate("settings_main", "Endoscpic cameras will be diplayed here", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_endo->setToolTip(QApplication::translate("settings_main", "View output from the endoscopic cameras", 0));
#endif // QT_NO_TOOLTIP
        label_endo->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_aux->setToolTip(QApplication::translate("settings_main", "View output from the auxiliary cameras", 0));
#endif // QT_NO_TOOLTIP
        label_aux->setText(QString());
        label_8->setText(QApplication::translate("settings_main", "Endoscopy Cameras", 0));
        label_11->setText(QApplication::translate("settings_main", "Adjust camera parameters to get the proper view", 0));
        checkBox->setText(QApplication::translate("settings_main", "Peg Segment ?", 0));
        checkBox_2->setText(QApplication::translate("settings_main", "Ring Segment ?", 0));
#ifndef QT_NO_TOOLTIP
        checkBoxRecordEndo->setToolTip(QApplication::translate("settings_main", "Record endoscopy video during evaluation process", 0));
#endif // QT_NO_TOOLTIP
        checkBoxRecordEndo->setText(QApplication::translate("settings_main", "Record endoscopic camera ?", 0));
#ifndef QT_NO_TOOLTIP
        checkBoxRecordAux->setToolTip(QApplication::translate("settings_main", "Record auxiliary video during evaluation process", 0));
#endif // QT_NO_TOOLTIP
        checkBoxRecordAux->setText(QApplication::translate("settings_main", "Record Auxiliary camera ?", 0));
        checkBox_3->setText(QString());
        label->setText(QApplication::translate("settings_main", "I accept to give consent for the study", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("settings_main", "Online evaluation", 0));
#ifndef QT_NO_TOOLTIP
        pbOffline->setToolTip(QApplication::translate("settings_main", "Run the application", 0));
#endif // QT_NO_TOOLTIP
        pbOffline->setText(QApplication::translate("settings_main", "Record", 0));
        label_10->setText(QApplication::translate("settings_main", "Endoscopy Cameras", 0));
#ifndef QT_NO_TOOLTIP
        listWidgetAuxOffline->setToolTip(QApplication::translate("settings_main", "Auxiliary cameras will be diplayed here", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        listWidgetEndoOffline->setToolTip(QApplication::translate("settings_main", "Endoscpic cameras will be diplayed here", 0));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("settings_main", "Auxiliary Cameras", 0));
#ifndef QT_NO_TOOLTIP
        label_endo_2->setToolTip(QApplication::translate("settings_main", "View output from the endoscopic cameras", 0));
#endif // QT_NO_TOOLTIP
        label_endo_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_aux_2->setToolTip(QApplication::translate("settings_main", "View output from the auxiliary cameras", 0));
#endif // QT_NO_TOOLTIP
        label_aux_2->setText(QString());
        label_12->setText(QApplication::translate("settings_main", "Adjust camera parameters to get the proper view", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("settings_main", "Record", 0));
#ifndef QT_NO_TOOLTIP
        listWidgetPractice->setToolTip(QApplication::translate("settings_main", "Endoscpic cameras will be diplayed here", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbPractice->setToolTip(QApplication::translate("settings_main", "Run the application", 0));
#endif // QT_NO_TOOLTIP
        pbPractice->setText(QApplication::translate("settings_main", "Run", 0));
        label_5->setText(QApplication::translate("settings_main", "Endoscopy Cameras", 0));
#ifndef QT_NO_TOOLTIP
        label_endo_3->setToolTip(QApplication::translate("settings_main", "View output from the endoscopic cameras", 0));
#endif // QT_NO_TOOLTIP
        label_endo_3->setText(QString());
        label_13->setText(QApplication::translate("settings_main", "Adjust camera parameters to get the proper view", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("settings_main", "Practice", 0));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("settings_main", "Open Auxiliary Video", 0));
        pushButton_3->setText(QApplication::translate("settings_main", "Open timestamp file", 0));
        pushButton_2->setText(QApplication::translate("settings_main", "Open Endoscopy Video", 0));
        pushButton_4->setText(QApplication::translate("settings_main", "Evaluate", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("settings_main", "Evaluate existing videos", 0));
        selectLevel->clear();
        selectLevel->insertItems(0, QStringList()
         << QApplication::translate("settings_main", "Level 1 - No plate movement - 0 degree scope", 0)
         << QApplication::translate("settings_main", "Level 2 - No plate movement - 30 degree scope", 0)
         << QApplication::translate("settings_main", "Level 3 - No plate movement - 45degree scope", 0)
         << QApplication::translate("settings_main", "Level 4 - Slow plate movement - 0 degree scope", 0)
         << QApplication::translate("settings_main", "Level 5 - Slow plate movement - 30 degree scope", 0)
         << QApplication::translate("settings_main", "Level 6 - Slow plate movement - 45 degree scope", 0)
         << QApplication::translate("settings_main", "Level 7 - Fast plate movement - 0 degree scope", 0)
         << QApplication::translate("settings_main", "Level 8 - Fast plate movement - 30 degree scope", 0)
         << QApplication::translate("settings_main", "Level 9 - Fast plate movement - 45 degree scope", 0)
        );
#ifndef QT_NO_TOOLTIP
        selectLevel->setToolTip(QApplication::translate("settings_main", "Select levle of the difficulty", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("settings_main", "Name of the Trainee", 0));
        label_3->setText(QApplication::translate("settings_main", "Select Level", 0));
#ifndef QT_NO_TOOLTIP
        lineEditDrName->setToolTip(QApplication::translate("settings_main", "Give name of the Trainee", 0));
#endif // QT_NO_TOOLTIP
        lineEditDrName->setText(QApplication::translate("settings_main", "Dr. ", 0));
        pbQuit->setText(QApplication::translate("settings_main", "Quit", 0));
#ifndef QT_NO_TOOLTIP
        pbSettings->setToolTip(QApplication::translate("settings_main", "call the setting GUI", 0));
#endif // QT_NO_TOOLTIP
        pbSettings->setText(QApplication::translate("settings_main", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        pbRefresh->setToolTip(QApplication::translate("settings_main", "Refresh to connect to camera", 0));
#endif // QT_NO_TOOLTIP
        pbRefresh->setText(QApplication::translate("settings_main", "Refresh", 0));
    } // retranslateUi

};

namespace Ui {
    class settings_main: public Ui_settings_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_MAIN_H
