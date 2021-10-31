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
//#include <QMenu>
//#include <QMenuBar>
//#include <QStatusBar>
//#include <QAction>
//#include <QToolBar>
//#include <QIcon>
#include <QString>
//#include"bigInt.h"
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
        QVBoxLayout *vbox = new QVBoxLayout();
        QVBoxLayout *vbox2 = new QVBoxLayout(this);
        QPixmap pixma("/home/nikita/Загрузки/object.png");
        lbl = new QLabel("0",this);
        vbox->setSpacing(1);
        vbox2->setSpacing(1);

        vbox2->addWidget(lw);
        vbox2->setSpacing(15);
        vbox2->addWidget(e);
        vbox->addWidget(lbl);
        vbox->addWidget(a);
        vbox->addWidget(qp);

        QLabel *label = new QLabel(this);
        label->setPixmap(pixma);

        vbox2->addWidget(label, 0, Qt::AlignCenter);

        vbox2->addLayout(vbox);

        connect(a,&QPushButton::clicked,this,&menu::plus);
        connect(qp,&QPushButton::clicked,this,&menu::minus);

    }
    ~menu(){
        delete(parent);
    }
public slots:
    void plus(){
 QString nw = e->text();
// int c = nw.toInt();
   //  bigInt newn();
    h+=nw.toLocal8Bit().data();//newn;
     e->clear();
    const char* p = to_str(h);
    lbl->setText(p);
    // h +=c;
    // e->clear();
// QString a = QString::number(n);
// lbl->setText(a);
// QTextStream out(stdout);//For debugging
// out«"minus\n";
    }
    void minus(){

// QString nw = e->text();
// int c = nw.toInt();
// bigInt newn(nw.toLocal8Bit().data())
//h-=newn;
// e->clear();
//const char* p = to_str(h);
//lbl->setText(p);
// n -=c;
// e->clear();
// QString a = QString::number(n);
// lbl->setText(a);
// QTextStream out(stdout);//For debugging
// out«"minus\n";
    }
    void delten(){}
    void multen(){}
};
#endif //CMAKE_TUR_MENU_H
