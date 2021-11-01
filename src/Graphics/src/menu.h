//
// Created by Admin on 01.11.2021.
//
///Цель:сделать мессенджер на qt
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
#include "errors.h"
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
    QSound* qs = 0;
    QSound* news = 0;
    errors* err = 0;
public:
    menu(QWidget * p = nullptr){
        parent = new QWidget();
        e = new QLineEdit("Enter text",parent);
        a = new QPushButton("Plus",parent);
        QListWidget *lw = new QListWidget(this);
        qs = new QSound("C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\zvuk41.wav");
      //  news = new QSound("C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\sungha.wav");
      //  news->play();
        lw->addItem("ferf");
        lw->addItem("The Exorcist");
        lw->addItem("Notes on a scandal");
        lw->addItem("Fargo");
        lw->addItem("Capote");
        QPushButton* qp = new QPushButton("Minus",this);

        QPushButton* qp1 = new QPushButton("DelTen",this);
        QPushButton* qp2 = new QPushButton("MulTen",this);
        QPushButton* exit= new QPushButton("Exit",this);
        exit->setStyleSheet(
                "QPushButton{"
                "background-color: rgb(6, 0, 60);"
                "border-radius: 20px 20px 20px 20px;"
                "QPushButton:hover{"
                "background-color: rgb(25,13,00);} "
                "QPushButton:pressed  {"
                "background-color: rgb(232,95,76); } "
        );
        QVBoxLayout *vbox = new QVBoxLayout();
        QHBoxLayout *vbox2 = new QHBoxLayout(this);
        lbl = new QLabel("0",this);
        lbl->setStyleSheet("color:red");
        vbox2->addWidget(lw);
         vbox->setSpacing(3);
        vbox->addStretch(10);
        vbox->addWidget(lbl);
        vbox->addWidget(e);
        vbox->addWidget(a);

        vbox->addWidget(qp);
        vbox->addWidget(qp1);
        vbox->addWidget(qp2);

        vbox->addStretch(10);
        vbox->addWidget(exit);
        vbox->addStretch(3);
        QLabel *label = new QLabel(this);
        setLayout(vbox);
        setLayout(vbox2);

        vbox2->addLayout(vbox);

        connect(a,&QPushButton::clicked,this,&menu::plus);
        connect(qp,&QPushButton::clicked,this,&menu::minus);
        connect(qp1,&QPushButton::clicked,this,&menu::delten);
        connect(qp2,&QPushButton::clicked,this,&menu::multen);
        connect(exit,&QPushButton::clicked,this,&menu::qui);
        err = new errors();
    }
    ~menu()
    {
        delete(parent);
    }
public slots:
    void plus(){
        err->show();
        qs->play();
        QString nw = e->text();
        h+=nw.toLocal8Bit().data();//newn;
         e->clear();
        const char* p = to_str(h);
        lbl->setText(p);
    }
    void minus(){
        qs->play();
        QString nw = e->text();
        h-=nw.toLocal8Bit().data();//newn;
        e->clear();
        const char* p = to_str(h);
        lbl->setText(p);
    }
    void delten(){
        qs->play();
        h>>=1;//newn;
        const char* p = to_str(h);
        lbl->setText(p);
    }
    void multen(){
        qs->play();
        h<<=1;//newn;
        const char* p = to_str(h);
        lbl->setText(p);
    }
    void qui(){
        this->close();
    }
};
#endif //CMAKE_TUR_MENU_H
