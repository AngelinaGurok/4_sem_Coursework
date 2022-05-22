/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QAction *actionback;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *ipEdit;
    QLineEdit *portEdit;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *DesktopBt;
    QSpacerItem *horizontalSpacer_8;
    QTextBrowser *rcvBrowser;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *msgEdit;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_10;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(1083, 2244);
        Menu->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	\n"
"	background-color: rgb(241, 241, 241);\n"
"}\n"
"#msgEdit\n"
"{\n"
"	\n"
"	border-image: url(:/sendmsg.png);\n"
"}\n"
"#pushButton\n"
"{\n"
"	border-image: url(:/sBt.png);\n"
"\n"
"}\n"
"#pushButton:press\n"
"{\n"
"	border-image: url(:/sBt_hover.png);\n"
"\n"
"}\n"
"#voiceBt\n"
"{\n"
"	\n"
"	border-image: url(:/voice.png);\n"
"}\n"
"#voiceBt:press\n"
"{\n"
"	\n"
"	border-image: url(:/voice2.png);\n"
"}\n"
"#imagBt\n"
"{\n"
"	\n"
"	border-image: url(:/photo.png);\n"
"}\n"
"#imagBt:press\n"
"{\n"
"	\n"
"	border-image: url(:/photo.png);\n"
"}\n"
"#photoBt\n"
"{\n"
"	\n"
"	border-image: url(:/cam.png);\n"
"}\n"
"\n"
"#photoBt:press\n"
"{\n"
"	\n"
"	border-image: url(:/cam2.png);\n"
"}\n"
"#fileBt\n"
"{\n"
"	\n"
"	border-image: url(:/file.png);\n"
"}\n"
"#fileBt:press\n"
"{\n"
"	\n"
"	border-image: url(:/file2.png);\n"
"}\n"
"\n"
"\n"
"#DesktopBt\n"
"{\n"
"	\n"
"	border-image: url(:/Rcontrl .png);\n"
"}\n"
"\n"
"#DesktopBt:press\n"
"{\n"
"	\n"
"	border-image: url(:/Rcontrl_hover .png);\n"
""
                        "}\n"
"\n"
""));
        actionback = new QAction(Menu);
        actionback->setObjectName(QString::fromUtf8("actionback"));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ipEdit = new QLineEdit(centralwidget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(60);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(ipEdit->sizePolicy().hasHeightForWidth());
        ipEdit->setSizePolicy(sizePolicy);
        ipEdit->setMinimumSize(QSize(450, 48));
        ipEdit->setMaximumSize(QSize(250, 100));

        horizontalLayout_2->addWidget(ipEdit);

        portEdit = new QLineEdit(centralwidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(portEdit->sizePolicy().hasHeightForWidth());
        portEdit->setSizePolicy(sizePolicy1);
        portEdit->setMinimumSize(QSize(450, 48));
        portEdit->setMaximumSize(QSize(250, 100));

        horizontalLayout_2->addWidget(portEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        DesktopBt = new QPushButton(centralwidget);
        DesktopBt->setObjectName(QString::fromUtf8("DesktopBt"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DesktopBt->sizePolicy().hasHeightForWidth());
        DesktopBt->setSizePolicy(sizePolicy2);
        DesktopBt->setMinimumSize(QSize(64, 64));
        DesktopBt->setMaximumSize(QSize(64, 64));

        horizontalLayout_2->addWidget(DesktopBt);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_8);

        rcvBrowser = new QTextBrowser(centralwidget);
        rcvBrowser->setObjectName(QString::fromUtf8("rcvBrowser"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(rcvBrowser->sizePolicy().hasHeightForWidth());
        rcvBrowser->setSizePolicy(sizePolicy3);
        rcvBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 241, 241);"));

        verticalLayout->addWidget(rcvBrowser);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        msgEdit = new QLineEdit(centralwidget);
        msgEdit->setObjectName(QString::fromUtf8("msgEdit"));
        sizePolicy2.setHeightForWidth(msgEdit->sizePolicy().hasHeightForWidth());
        msgEdit->setSizePolicy(sizePolicy2);
        msgEdit->setMinimumSize(QSize(720, 128));
        msgEdit->setMaximumSize(QSize(720, 128));

        horizontalLayout_3->addWidget(msgEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(30);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);
        pushButton->setMinimumSize(QSize(317, 128));
        pushButton->setMaximumSize(QSize(315, 128));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton->setFont(font);
        pushButton->setFocusPolicy(Qt::StrongFocus);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 18pt \"Palatino Linotype\";"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_10);

        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1083, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Menu->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionback);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "MainWindow", nullptr));
        actionback->setText(QCoreApplication::translate("Menu", "back", nullptr));
        ipEdit->setText(QCoreApplication::translate("Menu", "192.168.43.93", nullptr));
        ipEdit->setPlaceholderText(QCoreApplication::translate("Menu", "ip", nullptr));
        portEdit->setText(QCoreApplication::translate("Menu", "8080", nullptr));
        portEdit->setPlaceholderText(QCoreApplication::translate("Menu", "port", nullptr));
        DesktopBt->setText(QString());
        pushButton->setText(QCoreApplication::translate("Menu", "send", nullptr));
        menu->setTitle(QCoreApplication::translate("Menu", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
