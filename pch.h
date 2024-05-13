//
// pch.h
//

#pragma once
#include <iostream>
#include <fstream>
using namespace std;


template <typename T>
class Set
{
    static const int size_t = 10;
    T arr[size_t] = { 0 };
    int position;
public:
    Set();
    Set(T arr_); // � ����������
    Set(const Set& S);
    ~Set();
    Set operator = (const Set& S);
    void add(T x); // ����� ������� .
    void remove(T x); // ������� �������
    void clear(); // ������ ���� �����
    bool Check(T x); // �������� �������� �������� � ������
    int set_size(); //����� �������
    Set union_(Set& S); //�������� ������
    Set intersect(Set& S); // ������� ������
    Set difference(Set& S); // г����� ���� ������
    void print(ostream& os); // ���� � ����


};
template<typename T>
Set<T> Set<T>::operator=(const Set& S)
{
    for (int i = 0; i < size_t; ++i)
    {
        arr[i] = S.arr[i];
    }
    return *this;
}

template<typename T>
Set<T>::~Set()
{

}

template<typename T>
Set<T>::Set(const Set& S)
{
    position = S.position; // ������� ������� �������� � ������� ������ ����� � �� � ������ S
    for (int i = 0; i < S.position; ++i)
    {
        arr[i] = S.arr[i]; // ����� �������� � ������ arr ������� S �� ������ arr ������� �������.
    }
}

template<typename T>
Set<T>::Set(T arr_)
{
    position = 0;
    for (int i = 0; i < size_t; ++i)  // ³� ����� �������� � arr_ � arr ������� �� ��� ��,
        // ���� �� ������� ������� �������� � arr_ ��� �� ����������� ����������� ������� �������� � arr.
        // ����� ��������� ������� arr_ �������� �� �������, � ����� position ���������� �� �������.
    {
        if (arr_[i] == 0)
        {
            break;
        }
        else
        {
            arr[i] = arr_[i];
            position++;
        }

    }
}

template<typename T>
Set<T>::Set()
{
    position = 0;
}
template<typename T>
void Set<T>::add(T x) // ����� ������� .
{
    if (position != size_t - 1)
    {
        bool check = true;
        for (int j = 0; j < position; ++j)
        {
            if (x == arr[j])
            {
                check = false;
                break;
            }
            else
            {
                continue;
            }
        }
        if (check)
        {

            arr[position] = x;
            position++;
        }
    }
    else
    {
        cout << "Set is full, can't add new element \n";
    }
}

template<typename T>
void Set<T>::remove(T x) // ������� �������
{
    for (int i = 0; i < position; ++i)
    {
        if (arr[i] == x)
        {
            for (int j = i; j < position; ++j)
            {
                arr[j] = arr[j + 1];
            }
            arr[position] = 0;
        }
    }
    position--;
}
template<typename T>
void Set<T>::clear() // ������ ���� �����
{
    for (int i = 0; i < position; ++i)
    {
        arr[i] = 0;
    }
}
template<typename T>
bool Set<T>::Check(T x) // �������� �������� �������� � ������
{
    bool check = false;
    for (int i = 0; i < position; ++i)
    {
        if (arr[i] == x)
        {
            check = true;
            break;
        }
    }
    return check;
}
template<typename T>
int Set<T>::set_size() //����� �������
{
    return position;  // ������� ������� �������� �� ��� � � ������
}
template<typename T>
Set<T> Set<T>::union_(Set& S) //�������� ������
{
    Set un = S;
    for (int i = 0; i < position; ++i)
    {
        if (!un.Check(arr[i]))
        {
            if (un.set_size() < size_t)
            {
                un.add(arr[i]);
                un.position++;
            }
        }
    }
    return un;
}
template<typename T>
Set<T> Set<T>::intersect(Set& S) // ������� ������
{
    Set in;
    for (int i = 0; i < position; ++i)
    {
        for (int j = 0; j < S.position; ++j)
        {
            if (arr[i] == S.arr[j])
            {
                in.add(arr[i]);
                break;
            }
        }
    }
    return in;
}





template<typename T>
Set<T> Set<T>::difference(Set& S) // г����� ���� ������
{
    Set dif;
    for (int i = 0; i < position; ++i)
    {
        bool check = true;
        for (int j = 0; j < S.position; ++j)
        {
            if (arr[i] == S.arr[j])
            {
                check = false;
                break;
            }
            else
            {
                continue;
            }
        }
        if (check)
        {
            dif.add(arr[i]);
            dif.position++;
        }
    }
    return dif;
}
template<typename T>
void Set<T>::print(ostream& os) // ���� � ����
{
    for (int i = 0; i < position; ++i)
    {
        os << arr[i] << ' ';
    }
    os << endl;
}
#include "gtest/gtest.h"
