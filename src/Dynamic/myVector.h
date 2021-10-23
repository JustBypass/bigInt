//
// Created by Admin on 22.10.2021.
//

#ifndef CMAKE_TUR_MYVECTOR_H
#define CMAKE_TUR_MYVECTOR_H

template<class T>
class myVector
{
private:
    int _size = 0;
    T* vector = nullptr;
    int _capacity = 0;
public:
    myVector(int n = 0) {
        _size = 0;
        _capacity = n;
        vector = new T[n];
    }
    ~myVector() {
        _size = 0;
        delete(vector);
    }
    char operator[](int i) {
        return vector[i];
    }
    char* get_vector() { return vector; }
    void push_back(T _c) { vector[_size++] = _c; }
    char pop_back() { return vector[--_size]; }
    int size() { return _size; }
};


#endif //CMAKE_TUR_MYVECTOR_H
