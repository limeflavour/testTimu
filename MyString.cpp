//
// Created by Administrator on 2022/7/12.
//
#include "MyString.h"
#include <string>
#include <cstring>
#include <iostream>

MyString::MyString(const char *str)
{
    if (str == nullptr)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int len = strlen(str);
        m_data = new char[len + 1];
        strcpy(m_data, str);
    }
}

MyString::MyString(const MyString &other)
{
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, other.m_data);
}

MyString::~MyString(void)
{
    delete[] m_data;
    m_data = nullptr;
    std::cout << this << std::endl;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this == &other)
    {
        return *this;
    }
    else
    {
        delete[] m_data;
        int len = strlen(other.m_data);
        m_data = new char[len + 1];
        strcpy(m_data, other.m_data);
        return *this;
    }
}

std::string MyString::getStr()
{
    return std::string(m_data);
}

void MyString::setStr(const char* str)
{
    if (str == nullptr)
    {
        delete[] this->m_data;
        this->m_data = nullptr;
        this->m_data = new char[1];
        this->m_data[0] = '\0';
    }
    else
    {
        delete[] this->m_data;
        this->m_data = nullptr;
        int len = strlen(str);
        this->m_data = new char[len + 1];
        strcpy(this->m_data, str);
    }
}