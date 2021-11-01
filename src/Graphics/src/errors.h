//
// Created by Admin on 01.11.2021.
//

#ifndef CMAKE_TUR_ERRORS_H
#define CMAKE_TUR_ERRORS_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
class errors:public QWidget{
    Q_OBJECT
private:
    QWidget* parent = 0;
public:

    errors(){
        parent = new QWidget();
        //parent->setGeometry(50,100,100,100);
        QLabel* lbl = new QLabel("Error occured!");
        QPushButton* b = new QPushButton("Ok",this);
        QHBoxLayout* h1 = new QHBoxLayout(this);
        QHBoxLayout* h2 = new QHBoxLayout(this);
        h1->addWidget(lbl);
        h2->addWidget(b);
        setLayout(h1);
        setLayout(h2);
        h1->addLayout(h2);
    }




};



#endif //CMAKE_TUR_ERRORS_H
