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
#include <QUrl>
#include<QDesktopServices>
#include <QString>
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
    menu(QWidget * p = nullptr)
    {
        parent = new QWidget();
        e = new QLineEdit(parent);
        e->setPlaceholderText("Вводите число...");
        a = new QPushButton("Plus",parent);
        a->setStyleSheet(
                " QPushButton {\n"
                "     border: 2px solid #8f8f91;\n"
                "     border-radius: 6px;\n"
                "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
                "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
                "     min-width: 80px;\n"
                " }"

        );
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
        qp->setStyleSheet(
                " QPushButton {\n"
                "     border: 2px solid #8f8f91;\n"
                "     border-radius: 6px;\n"
                "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
                "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
                "     min-width: 80px;\n"
                " }"

        );
        QPushButton* qp1 = new QPushButton("DelTen",this);
        qp1->setStyleSheet(
                " QPushButton {\n"
                "     border: 2px solid #8f8f91;\n"
                "     border-radius: 6px;\n"
                "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
                "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
                "     min-width: 80px;\n"
                " }"

        );
        QPushButton* qp2 = new QPushButton("MulTen",this);
        qp2->setStyleSheet(
                " QPushButton {\n"
                "     border: 2px solid #8f8f91;\n"
                "     border-radius: 6px;\n"
                "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
                "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
                "     min-width: 80px;\n"
                " }"

        );
        QPushButton* exit= new QPushButton("Exit",this);
        exit->setStyleSheet(
              " QPushButton {\n"
              "     border: 2px solid #8f8f91;\n"
              "     border-radius: 6px;\n"
              "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
              "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
              "     min-width: 80px;\n"
              " }"

        );
        QPushButton* myGit= new QPushButton("Github",this);
        myGit->setStyleSheet(
                " QPushButton {\n"
                "     border: 2px solid #8f8f91;\n"
                "     border-radius: 6px;\n"
                "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
                "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
                "     min-width: 80px;\n"
                " }"

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
        vbox->setSpacing(3);
        vbox->addWidget(myGit);
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
        connect(myGit,&QPushButton::clicked,this,&menu::link);

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
    void link(){
        QDesktopServices::openUrl(QUrl("https://dumponce.github.io"));
    }
};
#endif //CMAKE_TUR_MENU_H
