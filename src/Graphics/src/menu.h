//
// Created by Admin on 01.11.2021.
//
///Цель:сделать мессенджер на qt
#ifndef CMAKE_TUR_MENU_H
#define CMAKE_TUR_MENU_H
#include "C:\Users\Admin\CLionProjects\untitled12\bigInt\src\Dynamic\bigInt.h"

#include <QPushButton>
#include <QBoxLayout>

#include <QLineEdit>

#include <QLabel>
#include <QPalette>

#include <QListWidget>
#include <QPixmap>
#include <QTextStream>
#include <QUrl>

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QSound>

#include<QDesktopServices>
#include <QString>

#include <QMenu>
#include <QMenuBar>

#include <QApplication>

#include "errors.h"
#include "second.h"

#include <QTimer>

#include <QColor>
#include <QBrush>
#include <QPainter>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class figure:public QGraphicsPixmapItem{

public:
    figure(int xspread):QGraphicsPixmapItem(0)
    {
        std::cout<<"figure";
      //  QColor color = QColor(rand()%255,rand()%255,rand()%255);std::cout<<"end";
        //this->setBrush(color);
       // this->setRect(0,0,30,20);
        setPixmap( QPixmap("C:\\Users\\Admin\\CLionProjects\\untitled12\\bigInt\\src\\Graphics\\forms\\bot.jpg"));
        setPos(rand()%(xspread-30),0);
    }
public:
    virtual void advance(int phase);
private:
};



class menu:public QWidget {//Сделать отнаст=ледованным от QMainMenu
    Q_OBJECT
private:
      QWidget* parent = nullptr;
      QPushButton* a = 0;
      QPushButton* b = 0;
      QLineEdit* e = 0;
      QGridLayout *grid = 0;
      QLabel* lbl = 0;
      bigInt h = 0;
      QSound* qs = 0;
      QSound* news = 0;
      errors* err = 0;
      second* sec = {};
      QMenuBar* qmb = {};
      QMenu* qm = {};
      QVBoxLayout* lo = {};
      QPushButton* qp = {};
      QPushButton* qp2= {};
      QGraphicsScene* qgs = {};
      QGraphicsView* qgv = 0;
      QTimer* animTimer = {};
      QTimer* genTimer = {};
public:
         menu(QWidget* parent = nullptr);
         ~menu()
         {
             delete(parent);
             //delete(ui);
         }
public slots:
    void addSq()
    {
             std::cout<<"freger";
        qgs->addItem(new figure(qgs->sceneRect().width()));
        std::cout<<"exit";
    }
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
    void qui()
    {
        this->close();
    }
    void link(){
        QDesktopServices::openUrl(QUrl("https://dumponce.github.io"));
    }

    void changeBut(bool checked)
    {
        if (checked)
        {
            a->setStyleSheet
            (
                    " QPushButton {\n"
                    "     border: 2px solid #8f8f91;\n"
                    "     border-radius: 6px;\n"
                    "     min-width: 80px;\n"
                    " }"
            );
        } else {
            a->setStyleSheet(
                    " QPushButton {\n"
                    "     border: 2px solid #8f8f91;\n"
                    "     border-radius: 6px;\n"
                    "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
                    "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
                    "     min-width: 80px;\n"
                    " }"

            );
        }
    }
    void pressedFunc()
    {

    }
    void openNew() {
        this->close();
        sec->setWindowTitle("My first product");
        sec->setGeometry(500, 500, 500, 500);
        sec->show();
    }
};


#endif //CMAKE_TUR_MENU_H
