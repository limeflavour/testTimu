//
// Created by Administrator on 2022/7/12.
//

#ifndef TESTTIMU_MYSTACK_H
#define TESTTIMU_MYSTACK_H
#include <iostream>

template<class T>
class MyStack
{
private:
    T* m_data;
    int top;
    int _max_size;
public:
    MyStack(int max_size = 10);
    MyStack(const MyStack<T>& other);
    ~MyStack();
    void push(T& data);
    void push(T&& data);
    T pop();
    int isFull() const;
    int isEmpty() const;
    void clear();
};


template<class T>
MyStack<T>::MyStack(int max_size) : top(-1), _max_size(max_size)
{
    m_data = new T[_max_size];
}

template<class T>
MyStack<T>::MyStack(const MyStack<T> &other)
{
    int len = sizeof(other.m_data);
    m_data = new T[len];
    memcpy(m_data, other.m_data, len);
}

template<class T>
MyStack<T>::~MyStack()
{
    delete[] m_data;
    m_data = nullptr;
}

template<class T>
void MyStack<T>::clear()
{
    top = -1;
}

template<class T>
int MyStack<T>::isEmpty() const
{
    return (top == -1)?1:0;
}

template<class T>
int MyStack<T>::isFull() const
{
    return (top == _max_size)?1:0;
}

template<class T>
void MyStack<T>::push(T &data)
{
    if (isFull() == 0)
    {
        m_data[++top] = data;
    }
    else
    {
        std::cout << "Full" << std::endl;
    }
}

template<class T>
void MyStack<T>::push(T &&data)
{
    if (isFull() == 0)
    {
        m_data[++top] = data;
    }
    else
    {
        std::cout << "Full" << std::endl;
    }
}

template<class T>
T MyStack<T>::pop()
{
    if (isEmpty() == 0)
    {
        return m_data[top--];
    }
    else
    {
        std::cout << "Empty" << std::endl;
    }
}

#endif //TESTTIMU_MYSTACK_H
