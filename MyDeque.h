//
// Created by Administrator on 2022/7/12.
//

#ifndef TESTTIMU_MYDEQUE_H
#define TESTTIMU_MYDEQUE_H
#include <assert.h>

template<class T>
class MyDeque
{
public:
    MyDeque(int defaultSize= 10);
    ~MyDeque(void);
    void enMyDeque(T& newElem);
    void enMyDeque(T&& newElem);
    T deMyDeque();
    T getFront();
    void makeEmpty(){length = 0;}
    int isFull() const { return length == maxSize;}
    int isEmpty() const { return length == 0;}
private:
    int rear, length;
    T* elem;
    int maxSize;
};

template<class T>
MyDeque<T>::MyDeque(int size) : rear(maxSize - 1), length(0), maxSize(size)
{
    elem = new T[maxSize];
    assert(elem != 0);

}

template<class T>
MyDeque<T>::~MyDeque()
{
    delete[] elem;
}

template<class T>
void MyDeque<T>::enMyDeque(T &newElem)
{
    assert(!isFull());
    length++;
    rear = (rear + 1) % maxSize;
    elem[rear] = newElem;
}

template<class T>
void MyDeque<T>::enMyDeque(T&& newElem)
{
    assert(!isFull());
    length++;
    rear = (rear + 1) % maxSize;
    elem[rear] = newElem;
}

template<class T>
T MyDeque<T>::deMyDeque()
{
    assert(!isEmpty());
    length--;
    return elem[(rear- length + maxSize) % maxSize];
}

template<class T>
T MyDeque<T>::getFront()
{
    assert(!isEmpty());
    return elem[(rear - length + 1 +  maxSize) % maxSize];
}

#endif //TESTTIMU_MYDEQUE_H
