#include <cctype>

#include "LongInt.h"


LongInt::LongInt()
{
    
}

LongInt& LongInt::operator=(const LongInt& rhs)
{
    
    this->myStack = rhs.myStack;
}

LongInt& LongInt::operator+(const LongInt& rhs) const
{
    
    int a, b, c, next;
    
    LongInt left, right;
    LongInt* answer = new LongInt();
    next = 0;
    left = (*this);
    right = rhs;
    while(!left.myStack.isEmpty() && !right.myStack.isEmpty())
    {
        a = left.myStack.topAndPop();
        b = right.myStack.topAndPop();
        //cout << a << " " << b << " " << next << endl;
        c = a + b + next;
        if (c < 10)
        {
            answer->myStack.push(c);
            next = 0;
        }
        else
        {
            answer->myStack.push(c-10);
            //cout << answer->myStack.top();
            next = 1;
        }
    }
    while (!left.myStack.isEmpty())
    {
        a = left.myStack.topAndPop();
        c = a + next;
        if (c < 10)
        {
            answer->myStack.push(c);
            next = 0;
        }
        else
        {
            answer->myStack.push(c-10);
            next = 1;
        }
            
    }
    
    
    while (!right.myStack.isEmpty())
    {
        b = right.myStack.topAndPop();
        c = b + next;
        if (c < 10)
        {
            answer->myStack.push(c);
            next = 0;
        }
        else
        {
            answer->myStack.push(c-10);
            next = 1;
        }
            
    }
        
    if (next != 0)
    {
        answer->myStack.push(1);
    }
    return *answer;
}

istream& operator>>(istream& is, LongInt &rhs)
{
    char newChar;
    string str;
    newChar = (is>>ws).peek();
    while (isdigit(newChar))
    {
        is.get(newChar);
        rhs.myStack.push((int)newChar - '0');
        newChar = is.peek();
    }
    return is;
}

ostream& operator<<(ostream& os, const LongInt &rhs)
{
    LongInt outstack;
    outstack = rhs;
    while(!outstack.myStack.isEmpty())
    {
        os << outstack.myStack.topAndPop();
    }
    return os;
}

