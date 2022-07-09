/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralWidget;
    QPushButton *connBt;
    QLineEdit *portEdit;
    QTextBrowser *ipBrowser;
    QPushButton *stopBt;
    QTextBrowser *msgBrowser;
    QTextEdit *sendEdit;
    QFrame *frame;
    QPushButton *closeBt;
    QPushButton *minBt;
    QPushButton *maxBt;
    QPushButton *sendmsgBt;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(772, 572);
        Server->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: rgb(43, 26, 49);\n"
"}\n"
"#closeBt\n"
"{\n"
"	\n"
"	border-image: url(:/close.png);\n"
"}\n"
"#closeBt:hover\n"
"{\n"
"	\n"
"	border-image: url(:/close_hover.png);\n"
"}\n"
"#minBt\n"
"{\n"
"	\n"
"	border-image: url(:/min.png);\n"
"}\n"
"#minBt:hover\n"
"{\n"
"	\n"
"	border-image: url(:/min_hover.png);\n"
"}\n"
"#maxBt\n"
"{\n"
"	\n"
"	border-image: url(:/max.png);\n"
"}\n"
"#maxBt:hover\n"
"{\n"
"	\n"
"	border-image: url(:/max.png);\n"
"}\n"
"#sendmsgBt\n"
"{\n"
"border-image: url(:/send.png);\n"
"}\n"
"#sendmsgBt:hover\n"
"{\n"
"\n"
"border-image: url(:/send_hover.png);\n"
"}\n"
"#connBt\n"
"{\n"
"border-image: url(:/RMS.png);\n"
"}\n"
"#connBt:hover\n"
"{\n"
"border-image: url(:/RMS_hover.png);\n"
"}\n"
"#stopBt\n"
"{\n"
"border-image: url(:/stop.png);\n"
"}\n"
"#stopBt:hover\n"
"{\n"
"border-image: url(:/stop_hover.png);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connBt = new QPushButton(centralWidget);
        connBt->setObjectName(QString::fromUtf8("connBt"));
        connBt->setGeometry(QRect(590, 50, 45, 45));
        QIcon icon;
        icon.addFile(QString::fromUtf8("connect.svg"), QSize(), QIcon::Normal, QIcon::Off);
        connBt->setIcon(icon);
        connBt->setIconSize(QSize(45, 45));
        portEdit = new QLineEdit(centralWidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setGeometry(QRect(540, 100, 231, 61));
        portEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 26, 49);\n"
"font: 300 12pt \"Bahnschrift Light\";\n"
"border:1px solid#332637;\n"
"color: rgb(87, 247, 245);\n"
""));
        ipBrowser = new QTextBrowser(centralWidget);
        ipBrowser->setObjectName(QString::fromUtf8("ipBrowser"));
        ipBrowser->setGeometry(QRect(540, 160, 231, 421));
        ipBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 26, 49);\n"
"font: 300 10pt \"Bahnschrift Light\";\n"
"border:1px solid#332637;\n"
"color: rgb(87, 247, 245);\n"
""));
        stopBt = new QPushButton(centralWidget);
        stopBt->setObjectName(QString::fromUtf8("stopBt"));
        stopBt->setGeometry(QRect(690, 50, 45, 45));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("disconnect.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stopBt->setIcon(icon1);
        stopBt->setIconSize(QSize(45, 45));
        msgBrowser = new QTextBrowser(centralWidget);
        msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));
        msgBrowser->setGeometry(QRect(0, 40, 540, 361));
        msgBrowser->setStyleSheet(QString::fromUtf8("	background-color:rgb(51, 38, 55);\n"
"font: 300 12pt \"Bahnschrift Light\";\n"
"border:1,5px solid#775e7e;\n"
"color: rgb(87, 247, 245);\n"
""));
        msgBrowser->setLineWrapMode(QTextEdit::WidgetWidth);
        sendEdit = new QTextEdit(centralWidget);
        sendEdit->setObjectName(QString::fromUtf8("sendEdit"));
        sendEdit->setGeometry(QRect(0, 400, 540, 181));
        sendEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 26, 49);\n"
"font: 300 12pt \"Bahnschrift Light\";\n"
"border:1px solid#332637;\n"
"color: rgb(87, 247, 245);\n"
""));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 781, 41));
        frame->setStyleSheet(QString::fromUtf8("background-color:rgb(43, 26, 49);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        closeBt = new QPushButton(frame);
        closeBt->setObjectName(QString::fromUtf8("closeBt"));
        closeBt->setGeometry(QRect(15, 13, 20, 20));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeBt->sizePolicy().hasHeightForWidth());
        closeBt->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        closeBt->setIcon(icon2);
        closeBt->setIconSize(QSize(19, 19));
        minBt = new QPushButton(frame);
        minBt->setObjectName(QString::fromUtf8("minBt"));
        minBt->setGeometry(QRect(40, 13, 19, 19));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("collapse.svg"), QSize(), QIcon::Normal, QIcon::Off);
        minBt->setIcon(icon3);
        maxBt = new QPushButton(frame);
        maxBt->setObjectName(QString::fromUtf8("maxBt"));
        maxBt->setGeometry(QRect(65, 13, 19, 19));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("resize.svg"), QSize(), QIcon::Normal, QIcon::Off);
        maxBt->setIcon(icon4);
        maxBt->setIconSize(QSize(18, 18));
        sendmsgBt = new QPushButton(centralWidget);
        sendmsgBt->setObjectName(QString::fromUtf8("sendmsgBt"));
        sendmsgBt->setGeometry(QRect(480, 510, 48, 48));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("send.svg"), QSize(), QIcon::Normal, QIcon::Off);
        sendmsgBt->setIcon(icon5);
        sendmsgBt->setIconSize(QSize(48, 48));
        sendmsgBt->setAutoDefault(false);
        sendmsgBt->setFlat(false);
        Server->setCentralWidget(centralWidget);

        retranslateUi(Server);

        sendmsgBt->setDefault(false);


        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QCoreApplication::translate("Server", "Server", nullptr));
        connBt->setText(QString());
        portEdit->setPlaceholderText(QCoreApplication::translate("Server", "port: 8080", nullptr));
        stopBt->setText(QString());
        closeBt->setText(QString());
        minBt->setText(QString());
        maxBt->setText(QString());
        sendmsgBt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
