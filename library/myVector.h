//
// Created by Admin on 20.10.2021.
//

#ifndef CMAKE_TUR_MYVECTOR_H
#define CMAKE_TUR_MYVECTOR_H
template<typename T>
class myVector
{
private:
    T* vector = nullptr;
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
    T operator[](int i) {
        return vector[i];
    }
    T* get_vector() { return vector; }
    void push_back(char _c) { vector[_size++] = _c; }
    T pop_back() { return vector[--_size]; }
    int size() { return _size; }
private:
    int _size = 0;
    int _capacity = 0;
};
#endif //CMAKE_TUR_MYVECTOR_H
