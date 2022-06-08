/********************************************************************************
** Form generated from reading UI file 'ScreenSaverWIP.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSAVERWIP_H
#define UI_SCREENSAVERWIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenSaverWIPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenSaverWIPClass)
    {
        if (ScreenSaverWIPClass->objectName().isEmpty())
            ScreenSaverWIPClass->setObjectName(QString::fromUtf8("ScreenSaverWIPClass"));
        ScreenSaverWIPClass->resize(600, 400);
        menuBar = new QMenuBar(ScreenSaverWIPClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ScreenSaverWIPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenSaverWIPClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ScreenSaverWIPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ScreenSaverWIPClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ScreenSaverWIPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ScreenSaverWIPClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ScreenSaverWIPClass->setStatusBar(statusBar);

        retranslateUi(ScreenSaverWIPClass);

        QMetaObject::connectSlotsByName(ScreenSaverWIPClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenSaverWIPClass)
    {
        ScreenSaverWIPClass->setWindowTitle(QCoreApplication::translate("ScreenSaverWIPClass", "ScreenSaverWIP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenSaverWIPClass: public Ui_ScreenSaverWIPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSAVERWIP_H
