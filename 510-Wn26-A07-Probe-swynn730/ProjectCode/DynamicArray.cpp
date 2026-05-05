#include "DynamicArray.h"


void DynamicArray::put(int index, int value)
{
    if (index >= MyDynamicArray.size())
    {
        for (int i = MyDynamicArray.size(); i < index; i++) 
        {
            MyDynamicArray.push_back(-1);
        }
        MyDynamicArray.push_back(value);
    }
    else 
    {
        if ((index > -1) && (index < MyDynamicArray.size()))
        {
            MyDynamicArray.at(index) = value;
        }
    }
}

int DynamicArray::get(int index) const 
{
    if((index > -1) && (index < MyDynamicArray.size()))
    {
        return MyDynamicArray.at(index);
    }
    return -1;
}

void DynamicArray::remove(int index)
{
    if ((index > -1) && (index < MyDynamicArray.size()))
    {
        if (MyDynamicArray.size() == 1) 
        {
            MyDynamicArray.at(index) = -1;
        }
        else 
        {
            for (int i = index; i < MyDynamicArray.size() - 1; i++) 
            {
                MyDynamicArray.at(i) = MyDynamicArray.at(i + 1);
            }
            MyDynamicArray.pop_back();
        }
    }
}

int DynamicArray::size() const
{
    return MyDynamicArray.size();
}

int DynamicArray::operator[](const int index) const 
{
    if ((index > -1) && (index < MyDynamicArray.size())) 
    {
        return MyDynamicArray[index];
    }
    return -1;
}

int& DynamicArray::operator[](const int index) 
{
    if ((index > -1) && (index < MyDynamicArray.size())) 
    {
        return MyDynamicArray[index];
    }
    return OutOfBounds;
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& dynamicArray)
{
    os << "[";
    for (int i = 0; i < dynamicArray.size(); i++) 
    {
        if(i != dynamicArray.size() - 1)
        {
            os << dynamicArray[i] << ", ";
        }
        else 
        {
            os << dynamicArray[i];
        }
    }
    os << "]";
    return os;
}