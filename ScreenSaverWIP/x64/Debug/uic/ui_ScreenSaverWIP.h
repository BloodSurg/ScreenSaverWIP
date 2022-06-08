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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenSaverWIPClass
{
public:
    QWidget *centralWidget;
    QLabel *canvas;
    QComboBox *comboBoxShapes;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenSaverWIPClass)
    {
        if (ScreenSaverWIPClass->objectName().isEmpty())
            ScreenSaverWIPClass->setObjectName(QString::fromUtf8("ScreenSaverWIPClass"));
        ScreenSaverWIPClass->resize(870, 674);
        centralWidget = new QWidget(ScreenSaverWIPClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        canvas = new QLabel(centralWidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        canvas->setGeometry(QRect(10, 10, 501, 501));
        canvas->setAutoFillBackground(true);
        canvas->setFrameShape(QFrame::Box);
        canvas->setLineWidth(2);
        comboBoxShapes = new QComboBox(centralWidget);
        comboBoxShapes->setObjectName(QString::fromUtf8("comboBoxShapes"));
        comboBoxShapes->setGeometry(QRect(750, 60, 69, 22));
        ScreenSaverWIPClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScreenSaverWIPClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 21));
        ScreenSaverWIPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenSaverWIPClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ScreenSaverWIPClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScreenSaverWIPClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ScreenSaverWIPClass->setStatusBar(statusBar);

        retranslateUi(ScreenSaverWIPClass);

        QMetaObject::connectSlotsByName(ScreenSaverWIPClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenSaverWIPClass)
    {
        ScreenSaverWIPClass->setWindowTitle(QCoreApplication::translate("ScreenSaverWIPClass", "ScreenSaverWIP", nullptr));
        canvas->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScreenSaverWIPClass: public Ui_ScreenSaverWIPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSAVERWIP_H
