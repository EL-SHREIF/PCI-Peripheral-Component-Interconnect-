/********************************************************************************
** Form generated from reading UI file 'pci.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCI_H
#define UI_PCI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PCI
{
public:
    QWidget *centralWidget;
    QPushButton *devA;
    QPushButton *devB;
    QLineEdit *lineEdit;
    QPushButton *devC;
    QPushButton *arb;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QTableWidget *TA;
    QTableWidget *TB;
    QTableWidget *TC;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *INIT;
    QLineEdit *TARG;
    QLineEdit *lineEdit_8;
    QLineEdit *data;
    QLineEdit *idx;
    QLineEdit *index_enter;
    QLineEdit *data_enter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *R1;
    QRadioButton *R2;
    QLineEdit *idx_2;
    QLineEdit *no;
    QPushButton *arb_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *chart;
    QHBoxLayout *horizontalLayout;
    QPushButton *arb_6;
    QPushButton *arb_7;
    QPushButton *arb_8;
    QPushButton *arb_9;
    QPushButton *arb_10;
    QPushButton *arb_11;
    QPushButton *arb_12;
    QPushButton *arb_13;
    QPushButton *arb_14;
    QPushButton *arb_15;
    QPushButton *arb_16;
    QPushButton *arb_17;
    QPushButton *arb_18;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PCI)
    {
        if (PCI->objectName().isEmpty())
            PCI->setObjectName(QStringLiteral("PCI"));
        PCI->setWindowModality(Qt::ApplicationModal);
        PCI->setEnabled(true);
        PCI->resize(1375, 676);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(PCI->sizePolicy().hasHeightForWidth());
        PCI->setSizePolicy(sizePolicy);
        PCI->setBaseSize(QSize(1, 3));
        centralWidget = new QWidget(PCI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        devA = new QPushButton(centralWidget);
        devA->setObjectName(QStringLiteral("devA"));
        devA->setGeometry(QRect(0, 130, 91, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        devA->setFont(font);
        devA->setCursor(QCursor(Qt::OpenHandCursor));
        devA->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: red;\n"
"}"));
        devB = new QPushButton(centralWidget);
        devB->setObjectName(QStringLiteral("devB"));
        devB->setGeometry(QRect(210, 130, 101, 41));
        devB->setFont(font);
        devB->setCursor(QCursor(Qt::OpenHandCursor));
        devB->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: blue;\n"
"}"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(0, 0, 381, 31));
        lineEdit->setMinimumSize(QSize(0, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-radius: 15px;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        devC = new QPushButton(centralWidget);
        devC->setObjectName(QStringLiteral("devC"));
        devC->setGeometry(QRect(430, 130, 101, 41));
        devC->setFont(font);
        devC->setCursor(QCursor(Qt::OpenHandCursor));
        devC->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: green;\n"
"}"));
        arb = new QPushButton(centralWidget);
        arb->setObjectName(QStringLiteral("arb"));
        arb->setEnabled(false);
        arb->setGeometry(QRect(650, 190, 91, 71));
        arb->setFont(font1);
        arb->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: yellow;\n"
"}"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(20, 230, 631, 5));
        lineEdit_2->setAutoFillBackground(false);
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #000000;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(40, 170, 6, 65));
        lineEdit_3->setAutoFillBackground(false);
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #000000;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(250, 170, 6, 65));
        lineEdit_4->setAutoFillBackground(false);
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #000000;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setGeometry(QRect(480, 170, 6, 65));
        lineEdit_5->setAutoFillBackground(false);
        lineEdit_5->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #000000;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        TA = new QTableWidget(centralWidget);
        if (TA->columnCount() < 1)
            TA->setColumnCount(1);
        QFont font2;
        font2.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font2);
        TA->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (TA->rowCount() < 10)
            TA->setRowCount(10);
        QFont font3;
        font3.setPointSize(10);
        font3.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font3);
        TA->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QFont font4;
        font4.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font4);
        TA->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font4);
        TA->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font4);
        TA->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font4);
        TA->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font4);
        TA->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font4);
        TA->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font4);
        TA->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font4);
        TA->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font4);
        TA->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        font5.setKerning(false);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font5);
        __qtablewidgetitem11->setFlags(Qt::NoItemFlags);
        TA->setItem(0, 0, __qtablewidgetitem11);
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font6);
        __qtablewidgetitem12->setFlags(Qt::NoItemFlags);
        TA->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font6);
        __qtablewidgetitem13->setFlags(Qt::NoItemFlags);
        TA->setItem(2, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font6);
        __qtablewidgetitem14->setFlags(Qt::NoItemFlags);
        TA->setItem(3, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font6);
        __qtablewidgetitem15->setFlags(Qt::NoItemFlags);
        TA->setItem(4, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font6);
        __qtablewidgetitem16->setFlags(Qt::NoItemFlags);
        TA->setItem(5, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font6);
        __qtablewidgetitem17->setFlags(Qt::NoItemFlags);
        TA->setItem(6, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font6);
        __qtablewidgetitem18->setFlags(Qt::NoItemFlags);
        TA->setItem(7, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font6);
        __qtablewidgetitem19->setFlags(Qt::NoItemFlags);
        TA->setItem(8, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font6);
        __qtablewidgetitem20->setFlags(Qt::NoItemFlags);
        TA->setItem(9, 0, __qtablewidgetitem20);
        TA->setObjectName(QStringLiteral("TA"));
        TA->setEnabled(true);
        TA->setGeometry(QRect(90, 40, 111, 161));
        TB = new QTableWidget(centralWidget);
        if (TB->columnCount() < 1)
            TB->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem21->setFont(font2);
        TB->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        if (TB->rowCount() < 10)
            TB->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font3);
        TB->setVerticalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font4);
        TB->setVerticalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font4);
        TB->setVerticalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font4);
        TB->setVerticalHeaderItem(3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font4);
        TB->setVerticalHeaderItem(4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font4);
        TB->setVerticalHeaderItem(5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font4);
        TB->setVerticalHeaderItem(6, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font4);
        TB->setVerticalHeaderItem(7, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font4);
        TB->setVerticalHeaderItem(8, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font4);
        TB->setVerticalHeaderItem(9, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font5);
        __qtablewidgetitem32->setFlags(Qt::NoItemFlags);
        TB->setItem(0, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font6);
        __qtablewidgetitem33->setFlags(Qt::NoItemFlags);
        TB->setItem(1, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font6);
        __qtablewidgetitem34->setFlags(Qt::NoItemFlags);
        TB->setItem(2, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font6);
        __qtablewidgetitem35->setFlags(Qt::NoItemFlags);
        TB->setItem(3, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font6);
        __qtablewidgetitem36->setFlags(Qt::NoItemFlags);
        TB->setItem(4, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font6);
        __qtablewidgetitem37->setFlags(Qt::NoItemFlags);
        TB->setItem(5, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font6);
        __qtablewidgetitem38->setFlags(Qt::NoItemFlags);
        TB->setItem(6, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFont(font6);
        __qtablewidgetitem39->setFlags(Qt::NoItemFlags);
        TB->setItem(7, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setFont(font6);
        __qtablewidgetitem40->setFlags(Qt::NoItemFlags);
        TB->setItem(8, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setFont(font6);
        __qtablewidgetitem41->setFlags(Qt::NoItemFlags);
        TB->setItem(9, 0, __qtablewidgetitem41);
        TB->setObjectName(QStringLiteral("TB"));
        TB->setEnabled(true);
        TB->setGeometry(QRect(310, 40, 111, 161));
        TC = new QTableWidget(centralWidget);
        if (TC->columnCount() < 1)
            TC->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem42->setFont(font2);
        TC->setHorizontalHeaderItem(0, __qtablewidgetitem42);
        if (TC->rowCount() < 10)
            TC->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setFont(font3);
        TC->setVerticalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setFont(font4);
        TC->setVerticalHeaderItem(1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setFont(font4);
        TC->setVerticalHeaderItem(2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setFont(font4);
        TC->setVerticalHeaderItem(3, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setFont(font4);
        TC->setVerticalHeaderItem(4, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setFont(font4);
        TC->setVerticalHeaderItem(5, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setFont(font4);
        TC->setVerticalHeaderItem(6, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setFont(font4);
        TC->setVerticalHeaderItem(7, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setFont(font4);
        TC->setVerticalHeaderItem(8, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setFont(font4);
        TC->setVerticalHeaderItem(9, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setFont(font5);
        __qtablewidgetitem53->setFlags(Qt::NoItemFlags);
        TC->setItem(0, 0, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setFont(font6);
        __qtablewidgetitem54->setFlags(Qt::NoItemFlags);
        TC->setItem(1, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setFont(font6);
        __qtablewidgetitem55->setFlags(Qt::NoItemFlags);
        TC->setItem(2, 0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setFont(font6);
        __qtablewidgetitem56->setFlags(Qt::NoItemFlags);
        TC->setItem(3, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setFont(font6);
        __qtablewidgetitem57->setFlags(Qt::NoItemFlags);
        TC->setItem(4, 0, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setFont(font6);
        __qtablewidgetitem58->setFlags(Qt::NoItemFlags);
        TC->setItem(5, 0, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setFont(font6);
        __qtablewidgetitem59->setFlags(Qt::NoItemFlags);
        TC->setItem(6, 0, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setFont(font6);
        __qtablewidgetitem60->setFlags(Qt::NoItemFlags);
        TC->setItem(7, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setFont(font6);
        __qtablewidgetitem61->setFlags(Qt::NoItemFlags);
        TC->setItem(8, 0, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setFont(font6);
        __qtablewidgetitem62->setFlags(Qt::NoItemFlags);
        TC->setItem(9, 0, __qtablewidgetitem62);
        TC->setObjectName(QStringLiteral("TC"));
        TC->setEnabled(true);
        TC->setGeometry(QRect(530, 40, 111, 161));
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setEnabled(false);
        lineEdit_6->setGeometry(QRect(10, 270, 81, 31));
        lineEdit_6->setMinimumSize(QSize(0, 31));
        lineEdit_6->setFont(font1);
        lineEdit_6->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-radius: 15px;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setEnabled(false);
        lineEdit_7->setGeometry(QRect(140, 270, 81, 31));
        lineEdit_7->setMinimumSize(QSize(0, 31));
        lineEdit_7->setFont(font1);
        lineEdit_7->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-radius: 25px;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        INIT = new QLineEdit(centralWidget);
        INIT->setObjectName(QStringLiteral("INIT"));
        INIT->setEnabled(false);
        INIT->setGeometry(QRect(100, 270, 21, 31));
        INIT->setMinimumSize(QSize(0, 31));
        INIT->setFont(font1);
        INIT->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #00FF00;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"  border-radius: 10px;\n"
"}"));
        TARG = new QLineEdit(centralWidget);
        TARG->setObjectName(QStringLiteral("TARG"));
        TARG->setEnabled(false);
        TARG->setGeometry(QRect(240, 270, 21, 31));
        TARG->setMinimumSize(QSize(0, 31));
        TARG->setFont(font1);
        TARG->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #00FF00;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"  border-radius: 10px;\n"
"}"));
        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setEnabled(false);
        lineEdit_8->setGeometry(QRect(280, 270, 71, 31));
        lineEdit_8->setMinimumSize(QSize(0, 31));
        lineEdit_8->setFont(font1);
        lineEdit_8->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-radius: 25px;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        data = new QLineEdit(centralWidget);
        data->setObjectName(QStringLiteral("data"));
        data->setEnabled(false);
        data->setGeometry(QRect(10, 320, 121, 31));
        data->setMinimumSize(QSize(0, 31));
        data->setFont(font1);
        data->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-radius: 25px;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        idx = new QLineEdit(centralWidget);
        idx->setObjectName(QStringLiteral("idx"));
        idx->setEnabled(false);
        idx->setGeometry(QRect(240, 320, 211, 31));
        idx->setMinimumSize(QSize(0, 31));
        idx->setFont(font1);
        idx->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-radius: 25px;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        index_enter = new QLineEdit(centralWidget);
        index_enter->setObjectName(QStringLiteral("index_enter"));
        index_enter->setEnabled(true);
        index_enter->setGeometry(QRect(470, 320, 31, 31));
        index_enter->setMinimumSize(QSize(0, 31));
        index_enter->setFont(font1);
        index_enter->setAcceptDrops(true);
        index_enter->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #00FF00;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"  border-radius: 10px;\n"
"}"));
        data_enter = new QLineEdit(centralWidget);
        data_enter->setObjectName(QStringLiteral("data_enter"));
        data_enter->setEnabled(true);
        data_enter->setGeometry(QRect(140, 320, 91, 31));
        data_enter->setMinimumSize(QSize(0, 31));
        data_enter->setFont(font1);
        data_enter->setAcceptDrops(true);
        data_enter->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #00FF00;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"  border-radius: 10px;\n"
"}"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(370, 260, 71, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        R1 = new QRadioButton(verticalLayoutWidget);
        R1->setObjectName(QStringLiteral("R1"));
        R1->setStyleSheet(QLatin1String("QRadioButton{\n"
"	background:green;\n"
"	color:#CBF57D;\n"
"	font:bold;\n"
"}"));

        verticalLayout->addWidget(R1);

        R2 = new QRadioButton(verticalLayoutWidget);
        R2->setObjectName(QStringLiteral("R2"));
        R2->setEnabled(true);
        R2->setCursor(QCursor(Qt::PointingHandCursor));
        R2->setAcceptDrops(true);
        R2->setStyleSheet(QLatin1String("QRadioButton{\n"
"	background:green;\n"
"	color:#CBF57D;\n"
"	font:bold;\n"
"}"));

        verticalLayout->addWidget(R2);

        idx_2 = new QLineEdit(centralWidget);
        idx_2->setObjectName(QStringLiteral("idx_2"));
        idx_2->setEnabled(false);
        idx_2->setGeometry(QRect(450, 270, 191, 31));
        idx_2->setMinimumSize(QSize(0, 31));
        idx_2->setFont(font1);
        idx_2->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: white;\n"
"  background-color: #27a9e3;\n"
"  border-radius: 25px;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"}"));
        no = new QLineEdit(centralWidget);
        no->setObjectName(QStringLiteral("no"));
        no->setEnabled(true);
        no->setGeometry(QRect(660, 270, 31, 31));
        no->setMinimumSize(QSize(0, 31));
        no->setFont(font1);
        no->setAcceptDrops(true);
        no->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"  color: black;\n"
"  background-color: #00FF00;\n"
"  border-width: 0px;\n"
"  border-radius: 3px;\n"
"  border-radius: 10px;\n"
"}"));
        arb_2 = new QPushButton(centralWidget);
        arb_2->setObjectName(QStringLiteral("arb_2"));
        arb_2->setEnabled(true);
        arb_2->setGeometry(QRect(540, 310, 111, 41));
        arb_2->setFont(font1);
        arb_2->setCursor(QCursor(Qt::PointingHandCursor));
        arb_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: #FFA500;\n"
"}"));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(820, 10, 551, 641));
        chart = new QVBoxLayout(verticalLayoutWidget_2);
        chart->setSpacing(6);
        chart->setContentsMargins(11, 11, 11, 11);
        chart->setObjectName(QStringLiteral("chart"));
        chart->setSizeConstraint(QLayout::SetNoConstraint);
        chart->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);

        chart->addLayout(horizontalLayout);

        arb_6 = new QPushButton(centralWidget);
        arb_6->setObjectName(QStringLiteral("arb_6"));
        arb_6->setEnabled(false);
        arb_6->setGeometry(QRect(750, 70, 71, 31));
        arb_6->setFont(font);
        arb_6->setCursor(QCursor(Qt::PointingHandCursor));
        arb_6->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_7 = new QPushButton(centralWidget);
        arb_7->setObjectName(QStringLiteral("arb_7"));
        arb_7->setEnabled(false);
        arb_7->setGeometry(QRect(750, 110, 71, 31));
        arb_7->setFont(font);
        arb_7->setCursor(QCursor(Qt::PointingHandCursor));
        arb_7->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_8 = new QPushButton(centralWidget);
        arb_8->setObjectName(QStringLiteral("arb_8"));
        arb_8->setEnabled(false);
        arb_8->setGeometry(QRect(750, 150, 71, 31));
        arb_8->setFont(font);
        arb_8->setCursor(QCursor(Qt::PointingHandCursor));
        arb_8->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_9 = new QPushButton(centralWidget);
        arb_9->setObjectName(QStringLiteral("arb_9"));
        arb_9->setEnabled(false);
        arb_9->setGeometry(QRect(750, 190, 71, 31));
        arb_9->setFont(font);
        arb_9->setCursor(QCursor(Qt::PointingHandCursor));
        arb_9->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_10 = new QPushButton(centralWidget);
        arb_10->setObjectName(QStringLiteral("arb_10"));
        arb_10->setEnabled(false);
        arb_10->setGeometry(QRect(750, 240, 71, 31));
        arb_10->setFont(font);
        arb_10->setCursor(QCursor(Qt::PointingHandCursor));
        arb_10->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_11 = new QPushButton(centralWidget);
        arb_11->setObjectName(QStringLiteral("arb_11"));
        arb_11->setEnabled(false);
        arb_11->setGeometry(QRect(750, 280, 71, 31));
        arb_11->setFont(font);
        arb_11->setCursor(QCursor(Qt::PointingHandCursor));
        arb_11->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_12 = new QPushButton(centralWidget);
        arb_12->setObjectName(QStringLiteral("arb_12"));
        arb_12->setEnabled(false);
        arb_12->setGeometry(QRect(750, 320, 71, 31));
        arb_12->setFont(font);
        arb_12->setCursor(QCursor(Qt::PointingHandCursor));
        arb_12->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_13 = new QPushButton(centralWidget);
        arb_13->setObjectName(QStringLiteral("arb_13"));
        arb_13->setEnabled(false);
        arb_13->setGeometry(QRect(750, 360, 71, 31));
        arb_13->setFont(font);
        arb_13->setCursor(QCursor(Qt::PointingHandCursor));
        arb_13->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_14 = new QPushButton(centralWidget);
        arb_14->setObjectName(QStringLiteral("arb_14"));
        arb_14->setEnabled(false);
        arb_14->setGeometry(QRect(750, 410, 71, 41));
        arb_14->setFont(font);
        arb_14->setCursor(QCursor(Qt::PointingHandCursor));
        arb_14->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_15 = new QPushButton(centralWidget);
        arb_15->setObjectName(QStringLiteral("arb_15"));
        arb_15->setEnabled(false);
        arb_15->setGeometry(QRect(750, 460, 71, 31));
        arb_15->setFont(font);
        arb_15->setCursor(QCursor(Qt::PointingHandCursor));
        arb_15->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_16 = new QPushButton(centralWidget);
        arb_16->setObjectName(QStringLiteral("arb_16"));
        arb_16->setEnabled(false);
        arb_16->setGeometry(QRect(750, 500, 71, 31));
        arb_16->setFont(font);
        arb_16->setCursor(QCursor(Qt::PointingHandCursor));
        arb_16->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_17 = new QPushButton(centralWidget);
        arb_17->setObjectName(QStringLiteral("arb_17"));
        arb_17->setEnabled(false);
        arb_17->setGeometry(QRect(750, 540, 71, 31));
        arb_17->setFont(font);
        arb_17->setCursor(QCursor(Qt::PointingHandCursor));
        arb_17->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        arb_18 = new QPushButton(centralWidget);
        arb_18->setObjectName(QStringLiteral("arb_18"));
        arb_18->setEnabled(false);
        arb_18->setGeometry(QRect(750, 580, 71, 31));
        arb_18->setFont(font);
        arb_18->setCursor(QCursor(Qt::PointingHandCursor));
        arb_18->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  border: 2px solid gray;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"color: white;\n"
"  background: #895C94;\n"
"}"));
        PCI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PCI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1375, 21));
        PCI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PCI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        PCI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PCI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PCI->setStatusBar(statusBar);

        retranslateUi(PCI);

        QMetaObject::connectSlotsByName(PCI);
    } // setupUi

    void retranslateUi(QMainWindow *PCI)
    {
        PCI->setWindowTitle(QApplication::translate("PCI", "PCI", 0));
        devA->setText(QApplication::translate("PCI", "Device A", 0));
        devB->setText(QApplication::translate("PCI", "Device B", 0));
        lineEdit->setText(QApplication::translate("PCI", "please select the initiator and the target :", 0));
        devC->setText(QApplication::translate("PCI", "Device C", 0));
        arb->setText(QApplication::translate("PCI", "arbiter", 0));
        QTableWidgetItem *___qtablewidgetitem = TA->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PCI", "value", 0));
        QTableWidgetItem *___qtablewidgetitem1 = TA->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("PCI", "1", 0));
        QTableWidgetItem *___qtablewidgetitem2 = TA->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("PCI", "2", 0));
        QTableWidgetItem *___qtablewidgetitem3 = TA->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("PCI", "3", 0));
        QTableWidgetItem *___qtablewidgetitem4 = TA->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("PCI", "4", 0));
        QTableWidgetItem *___qtablewidgetitem5 = TA->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("PCI", "5", 0));
        QTableWidgetItem *___qtablewidgetitem6 = TA->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("PCI", "6", 0));
        QTableWidgetItem *___qtablewidgetitem7 = TA->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("PCI", "7", 0));
        QTableWidgetItem *___qtablewidgetitem8 = TA->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("PCI", "8", 0));
        QTableWidgetItem *___qtablewidgetitem9 = TA->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("PCI", "9", 0));
        QTableWidgetItem *___qtablewidgetitem10 = TA->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("PCI", "10", 0));

        const bool __sortingEnabled = TA->isSortingEnabled();
        TA->setSortingEnabled(false);
        TA->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem11 = TB->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("PCI", "value", 0));
        QTableWidgetItem *___qtablewidgetitem12 = TB->verticalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("PCI", "1", 0));
        QTableWidgetItem *___qtablewidgetitem13 = TB->verticalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("PCI", "2", 0));
        QTableWidgetItem *___qtablewidgetitem14 = TB->verticalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("PCI", "3", 0));
        QTableWidgetItem *___qtablewidgetitem15 = TB->verticalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("PCI", "4", 0));
        QTableWidgetItem *___qtablewidgetitem16 = TB->verticalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("PCI", "5", 0));
        QTableWidgetItem *___qtablewidgetitem17 = TB->verticalHeaderItem(5);
        ___qtablewidgetitem17->setText(QApplication::translate("PCI", "6", 0));
        QTableWidgetItem *___qtablewidgetitem18 = TB->verticalHeaderItem(6);
        ___qtablewidgetitem18->setText(QApplication::translate("PCI", "7", 0));
        QTableWidgetItem *___qtablewidgetitem19 = TB->verticalHeaderItem(7);
        ___qtablewidgetitem19->setText(QApplication::translate("PCI", "8", 0));
        QTableWidgetItem *___qtablewidgetitem20 = TB->verticalHeaderItem(8);
        ___qtablewidgetitem20->setText(QApplication::translate("PCI", "9", 0));
        QTableWidgetItem *___qtablewidgetitem21 = TB->verticalHeaderItem(9);
        ___qtablewidgetitem21->setText(QApplication::translate("PCI", "10", 0));

        const bool __sortingEnabled1 = TB->isSortingEnabled();
        TB->setSortingEnabled(false);
        TB->setSortingEnabled(__sortingEnabled1);

        QTableWidgetItem *___qtablewidgetitem22 = TC->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("PCI", "value", 0));
        QTableWidgetItem *___qtablewidgetitem23 = TC->verticalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("PCI", "1", 0));
        QTableWidgetItem *___qtablewidgetitem24 = TC->verticalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("PCI", "2", 0));
        QTableWidgetItem *___qtablewidgetitem25 = TC->verticalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("PCI", "3", 0));
        QTableWidgetItem *___qtablewidgetitem26 = TC->verticalHeaderItem(3);
        ___qtablewidgetitem26->setText(QApplication::translate("PCI", "4", 0));
        QTableWidgetItem *___qtablewidgetitem27 = TC->verticalHeaderItem(4);
        ___qtablewidgetitem27->setText(QApplication::translate("PCI", "5", 0));
        QTableWidgetItem *___qtablewidgetitem28 = TC->verticalHeaderItem(5);
        ___qtablewidgetitem28->setText(QApplication::translate("PCI", "6", 0));
        QTableWidgetItem *___qtablewidgetitem29 = TC->verticalHeaderItem(6);
        ___qtablewidgetitem29->setText(QApplication::translate("PCI", "7", 0));
        QTableWidgetItem *___qtablewidgetitem30 = TC->verticalHeaderItem(7);
        ___qtablewidgetitem30->setText(QApplication::translate("PCI", "8", 0));
        QTableWidgetItem *___qtablewidgetitem31 = TC->verticalHeaderItem(8);
        ___qtablewidgetitem31->setText(QApplication::translate("PCI", "9", 0));
        QTableWidgetItem *___qtablewidgetitem32 = TC->verticalHeaderItem(9);
        ___qtablewidgetitem32->setText(QApplication::translate("PCI", "10", 0));

        const bool __sortingEnabled2 = TC->isSortingEnabled();
        TC->setSortingEnabled(false);
        TC->setSortingEnabled(__sortingEnabled2);

        lineEdit_6->setText(QApplication::translate("PCI", "initiator:", 0));
        lineEdit_7->setText(QApplication::translate("PCI", "Target :", 0));
        INIT->setText(QString());
        TARG->setText(QString());
        lineEdit_8->setText(QApplication::translate("PCI", "mode:", 0));
        data->setText(QApplication::translate("PCI", "data to write:", 0));
        idx->setText(QApplication::translate("PCI", "index of data to read :", 0));
        index_enter->setText(QString());
        data_enter->setText(QString());
        R1->setText(QApplication::translate("PCI", "READ", 0));
        R2->setText(QApplication::translate("PCI", "WRITE", 0));
        idx_2->setText(QApplication::translate("PCI", "no. of transactions :", 0));
        no->setText(QString());
        arb_2->setText(QApplication::translate("PCI", "Simulate", 0));
        arb_6->setText(QApplication::translate("PCI", "clck", 0));
        arb_7->setText(QApplication::translate("PCI", "REQ_A", 0));
        arb_8->setText(QApplication::translate("PCI", "REQ_B", 0));
        arb_9->setText(QApplication::translate("PCI", "REQ_C", 0));
        arb_10->setText(QApplication::translate("PCI", "GNT_A", 0));
        arb_11->setText(QApplication::translate("PCI", "GNT_B", 0));
        arb_12->setText(QApplication::translate("PCI", "GNT_C", 0));
        arb_13->setText(QApplication::translate("PCI", "frame", 0));
        arb_14->setText(QApplication::translate("PCI", "A/D", 0));
        arb_15->setText(QApplication::translate("PCI", "C/ BE", 0));
        arb_16->setText(QApplication::translate("PCI", "I_RDY", 0));
        arb_17->setText(QApplication::translate("PCI", "TRDY", 0));
        arb_18->setText(QApplication::translate("PCI", "DEVSEL", 0));
    } // retranslateUi

};

namespace Ui {
    class PCI: public Ui_PCI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCI_H
