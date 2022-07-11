#include <iostream>
#include <cstring>
#include "memory"
#include <assert.h>
using namespace std;

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
    string getStr();
    void setStr(const char* str);
};

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

MyString::~MyString()
{
    delete[] m_data;
    m_data = nullptr;
    cout << this << endl;
}

MyString& MyString::operator=(const MyString &other)
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

string MyString::getStr()
{
    return string(m_data);
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

unsigned int testOneNum(char log)
{
    unsigned int num = 1, val;
    for (int i = 0; i < 8; ++i)
    {
        val = log >> i;
        val = val & 0x01;
        if (val != 0)
        {
            num++;
        }
    }
    return num;
}

void countNum()
{
    int a[128] = {0};
    string s;
    cout << "please input s" << endl;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        a[s[i]]++;
    }
    for (int j = 0; j < 300; ++j)
    {
        if (a[j])
        {
            cout << (char)j << "  " << a[j] << endl;
        }
    }
}

template<class T>
class MyDeque
{
public:
    MyDeque(int defaultSize= 10);
    ~MyDeque(void);
    void enMyDeque(T& newElem);
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
T MyDeque<T>::deMyDeque()
{
    assert(isEmpty());
    length--;
    return elem[(rear- length + maxSize) % maxSize];
}

template<class T>
T MyDeque<T>::getFront()
{
    assert(isEmpty());
    return elem[(rear - length + 1 +  maxSize) % maxSize];
}

int main()
{
    char a[6];
    memset(a, '0', sizeof(a));
    cin.getline(a, 6, '\n');
    int i ,j;
    char tmp;
    for(i = 0, j = strlen(a) - 1; i < strlen(a) / 2; i++, j--)
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    cout << a << endl;


    MyString myString1("hello");
    MyString myString2(myString1);
    MyString myString3 = myString2;

    cout << myString1.getStr() << endl;
    cout << myString2.getStr() << endl;
    cout << myString3.getStr() << endl;

    myString1.setStr("hellomystring1");
    cout << myString1.getStr() << endl;

    myString3.setStr("myString3");
    cout << myString3.getStr() << endl;

    cout << testOneNum(5) << endl;

    countNum();
}
