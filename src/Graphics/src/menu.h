//
// Created by Admin on 01.11.2021.
//
///Цель:сделать мессенджер на qt
#ifndef CMAKE_TUR_MENU_H
#define CMAKE_TUR_MENU_H
#include "../../Dynamic/bigInt.h"


#include <QGraphicsObject>
#include <QtGui>



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
#include <QQuickView>
#include <QQmlContext>

#include <qqmlapplicationengine.h>
#include <qmainwindow.h>
#include "qmainwindow.h"

#include <QObject>
#include <QQmlPropertyMap>

namespace Ui {
    class MainWindow;
}


class MainWindow:public QMainWindow{//Работает
     Q_OBJECT
     
public:
    explicit MainWindow(QWidget* parent) :
        QMainWindow(parent)
    {
        //Включаем наш QML
        ui = new QQuickView;
        ui->setSource(QUrl("glory.qml"));
     //   setCentralWidget(ui);
        ui->setResizeMode(QQuickView::SizeRootObjectToView);
    }
    ~MainWindow();

    Q_INVOKABLE void FunctionC()
    {
        //Найдем строку ввода
        QObject* textinput = Root->findChild<QObject*>("textinput");

        //Найдем поле вывода 
        QObject* memo = Root->findChild<QObject*>("memo");

        QString str;//Создадим новую строковую переменную

        //Считаем информацию со строки ввода через свойство text
        str = (textinput->property("text")).toString();

        int a;
        a = str.toInt();//Переведем строку в число
        a++;//Добавим к числу 1

        QString str2;//Создадим еще одну строковую переменную
        str2 = QString::number(a);//Переведем число в строку

        //Ну и наконец выведем в поле вывода нашу информацию
        memo->setProperty("text", str + "+1=" + str2);
    }

private:
    QQuickView* ui;
    QObject* Root;//корневой элемент QML модели
};
/// <summary>
/// 
/// </summary>
#endif //CMAKE_TUR_MENU_H
