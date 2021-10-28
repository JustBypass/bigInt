//
// Created by Admin on 22.10.2021.
//

#ifndef CMAKE_TUR_MYVECTOR_H
#define CMAKE_TUR_MYVECTOR_H


struct myVector
{
    char* vector = nullptr;
    int _size; = 0
    myVector(int n = 0):_size(0)
    {
        vector = new char[n];
    }
    ~myVector() {
        delete(vector);
    }
    void push_back(char _c) { vector[_size++] = _c; }
    char pop_back() { return vector[--_size]; }
};

#endif //CMAKE_TUR_MYVECTOR_H
