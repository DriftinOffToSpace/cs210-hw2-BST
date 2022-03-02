#pragma once
#include "List.h"
template <typename Object>
class Stack
{
public:
    bool isEmpty() const
    {
        return theList.empty();
    }
    const Object& top() const
    {
        return theList.front();
    }
    void push(const Object& x)
    {
        theList.push_front(x);
    }
    Object& pop()
    {
        Object x = theList.front(); 
        theList.pop_front();
        return x;
    }
private:
    List<Object> theList;
};