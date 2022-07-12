//
// Created by Administrator on 2022/7/12.
//

#ifndef TESTTIMU_MYSTRING_H
#define TESTTIMU_MYSTRING_H
#include <string>
class MyString
{
public:
    MyString(const char* str = nullptr);
    MyString(const MyString& other);
    ~MyString(void);
    MyString& operator=(const MyString& other);
private:
    char* m_data;

public:
    std::string getStr();
    void setStr(const char* str);
};

#endif //TESTTIMU_MYSTRING_H
