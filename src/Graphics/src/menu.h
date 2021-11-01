//
// Created by Admin on 01.11.2021.
//

#ifndef CMAKE_TUR_MENU_H
#define CMAKE_TUR_MENU_H
#include "C:\Qt\Qt5.12.10\cmake_tur\src\Dynamic\bigInt.h"
#include <QPushButton>
#include <QBoxLayout>
#include <iostream>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QListWidget>
#include <QPixmap>
#include <QTextStream>
#include <QMainWindow>
#include <QSound>
//#include <QMenu>
//#include <QMenuBar>
//#include <QStatusBar>
//#include <QAction>
//#include <QToolBar>
//#include <QIcon>
#include <QString>
//#include"bigInt.h"
#include <QMenu>
#include <QMenuBar>
class menu:public QWidget{//Сделать отнаст=ледованным от QMainMenu
    Q_OBJECT
private:
    QWidget* parent = nullptr;
    QPushButton* a = 0;
    QPushButton* b = 0;
    QLineEdit* e = 0;
    QGridLayout *grid = 0;
    QLabel* lbl = 0;
    int n = 0;
    bigInt h = 0;
public:
    menu(QWidget * p = nullptr){
        parent = new QWidget();
        e = new QLineEdit("Enter text",parent);
        a = new QPushButton("Plus",parent);
        QListWidget *lw = new QListWidget(this);
        lw->addItem("ferf");
        lw->addItem("The Exorcist");
        lw->addItem("Notes on a scandal");
        lw->addItem("Fargo");
        lw->addItem("Capote");
        QPushButton* qp = new QPushButton("Minus",this);
        QPushButton* qp1 = new QPushButton("DelTen",this);
        QPushButton* qp2 = new QPushButton("MulTen",this);
        QVBoxLayout *vbox = new QVBoxLayout();
        QVBoxLayout *vbox2 = new QVBoxLayout(this);
        QPixmap pixma("C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\imagee.jpg");
       // QAction *quit = new QAction(pixma, "&Quit", this);
       // quit->setShortcut(tr("CTRL+Q"));
//    QMenuBar menuBar;
//    QMenu *menu= new QMenu("Menu");
//    menu->addAction("Display");
//    menu->addAction("Exit");
//    menuBar.addMenu(menu);
//    menuBar.show();
        lbl = new QLabel("0",this);
        lbl->setStyleSheet("color:red");
        vbox->setSpacing(1);
        vbox2->setSpacing(1);

        vbox2->addWidget(lw);
        vbox2->setSpacing(15);
        vbox2->addWidget(e);
        vbox->addWidget(lbl);
        vbox->addWidget(a);
        vbox->addWidget(qp);
        vbox->addWidget(qp1);
        vbox->addWidget(qp2);
        QLabel *label = new QLabel(this);
        label->setPixmap(pixma);

        vbox2->addWidget(label, 0, Qt::AlignCenter);

        vbox2->addLayout(vbox);

        connect(a,&QPushButton::clicked,this,&menu::plus);
        connect(qp,&QPushButton::clicked,this,&menu::minus);
        connect(qp1,&QPushButton::clicked,this,&menu::delten);
        connect(qp2,&QPushButton::clicked,this,&menu::multen);
    }
    ~menu(){
        delete(parent);
    }
public slots:
    void plus(){
        QString nw = e->text();

        h+=nw.toLocal8Bit().data();//newn;
         e->clear();
        const char* p = to_str(h);
        lbl->setText(p);
    }
    void minus(){
        QString nw = e->text();
        h-=nw.toLocal8Bit().data();//newn;
        e->clear();
        const char* p = to_str(h);
        lbl->setText(p);
    }
    void delten(){
        h>>=1;//newn;
        const char* p = to_str(h);
        lbl->setText(p);
    }
    void multen(){
        h<<=1;//newn;
        const char* p = to_str(h);
        lbl->setText(p);
    }
};
#endif //CMAKE_TUR_MENU_H
