#include <iostream>
#include <cstring>
#include "memory"
#include <assert.h>
#include "MyDeque.h"
#include "MyString.h"
#include "MyStack.h"

using namespace std;

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

    char* ptr1 = "abc";
    cout << &ptr1 << endl;
    char ptr2[] = "abcd";
    cout << &ptr2 << endl;

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

    MyDeque<int> myDeque(5);
    myDeque.enMyDeque(1);
    myDeque.enMyDeque(2);
    myDeque.deMyDeque();
    cout << myDeque.getFront() << endl;

    MyStack<int> myStack(5);
    myStack.push(1);
    myStack.push(2);
    cout << myStack.pop() << endl;

    int testInt = 5;
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(testInt);
    cout << sharedPtr.use_count() << "   " << *sharedPtr << endl;


    return 0;
}
