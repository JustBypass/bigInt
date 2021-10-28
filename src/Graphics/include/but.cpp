//
// Created by Admin on 25.10.2021.
//

#include "but.h


MyButton::MyButton(QWidget *parent)
        : QWidget(parent) {
    QPushButton *quitBtn = new QPushButton("Quit",this); // создаем новую кнопку
    quitBtn->setGeometry(50, 40, 75, 30); // изменяем размеры кнопки в пикселях и помещаем на форму окна
}