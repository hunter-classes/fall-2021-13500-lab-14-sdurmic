#include <iostream>
#include "MyVector.h"
using namespace std;

template <class T>
MyVector<T>::MyVector() 
{
    vector_size = 0;
    vector_capacity = 10;
    arr = new T[vector_capacity];
}

template <class T>
MyVector<T>::MyVector(int size)
{
    if (size < 0)
    {
        size = 10;
    } 
    vector_capacity = size;
    arr = new T[vector_capacity];
    vector_size = 0;
}

template <class T>
MyVector<T>::~MyVector() 
{
    delete [] arr;
    arr = 0;
}

template <class T>
int MyVector<T>::size()
{
        return vector_size;
}

template <class T>
int MyVector<T>::capacity()
{
    return vector_capacity;
}

template <class T>
bool MyVector<T>::empty()
{
    return (vector_size == 0);
}

template <class T>
void MyVector<T>::push_back(T n) 
{
    if (vector_size >= vector_capacity)
    {
        vector_capacity += 1;
        T* temp = arr;
        arr = new T[vector_capacity];
        for (int i = 0; i < vector_size; i++)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
        temp = 0;
    }
    arr[vector_size] = n;
    vector_size += 1;
}

template <class T>
void MyVector<T>::pop_back(int n)
{
    if ((n >= 0) && (n < vector_size))
    {
        for (int i = n; i < (vector_size - 1); i++)
        {
            arr[i] = arr[i+1];
        }
        vector_size -= 1;
    }
}

template <class T>
void MyVector<T>::pop_back()
{
    if (vector_size > 0)
    {
        T* temp = arr;
        arr = new T[vector_capacity];
        for (int i = 0; i < (vector_size - 1); i++)
        {
            arr[i] = temp[i];
        }
        vector_size -= 1;
        delete [] temp;
        temp = 0;
    }
}

template <class T>
void MyVector<T>::clear()
{
    vector_size = 0;
    arr = new T[vector_capacity];
}

template <class T>
T& MyVector<T>::operator[](int i)
{
    if ((i >= vector_size) || (i < 0))
    {
        cout << "Invalid index\n";
        exit(0);
    } else {
        return arr[i];
    }
}


template<class T>
void MyVector<T>::printVector()
{
    cout << "Vector: [";
    for (int i = 0; i < (vector_size - 1); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[vector_size - 1] << "]" << endl;
    cout << "Size: " << vector_size << endl;
    cout << "Capacity: " << vector_capacity << endl;
}