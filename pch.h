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
    Set(T arr_); // ç ïàðàìåòðîì
    Set(const Set& S);
    ~Set();
    Set operator = (const Set& S);
    void add(T x); // äîäàºì åëåìåíò .
    void remove(T x); // âèëó÷àºì åëåìåíò
    void clear(); // Î÷èùóºì âåñü ìàñèâ
    bool Check(T x); // Ïåðåâ³ðêà íàÿâíîñò³ åëåìåíòà â ìíîæèí³
    int set_size(); //Ðîçì³ð ìíîæèíè
    Set union_(Set& S); //Îáºäíàííÿ ìíîæèí
    Set intersect(Set& S); // Ïåðåòèí ìíîæèí
    Set difference(Set& S); // Ð³çíèöÿ äâîõ ìíîæèí
    void print(ostream& os); // âèâ³ä â ïîò³ê


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
    position = S.position; // çáåð³ãàºì ê³ëüê³ñòü åëåìåíò³â ó ïîòî÷í³é ìíîæèí³ òàêîþ æ ÿê ó ìíîæèí³ S
    for (int i = 0; i < S.position; ++i)
    {
        arr[i] = S.arr[i]; // êîï³þº åëåìåíòè ç ìàñèâó arr ìíîæèíè S äî ìàñèâó arr ïîòî÷íî¿ ìíîæèíè.
    }
}

template<typename T>
Set<T>::Set(T arr_)
{
    position = 0;
    for (int i = 0; i < size_t; ++i)  // Â³í êîï³þº åëåìåíòè ç arr_ â arr ìíîæèíè äî òèõ ï³ð,
        // ïîêè íå çóñòð³íå íóëüîâå çíà÷åííÿ â arr_ àáî íå çàïîâíèòüñÿ ìàêñèìàëüíà ê³ëüê³ñòü åëåìåíò³â ó arr.
        // Êîæåí íåïîðîæí³é åëåìåíò arr_ äîäàºòüñÿ äî ìíîæèíè, ³ çì³ííà position çá³ëüøóºòüñÿ íà îäèíèöþ.
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
 position= 0;
}
template<typename T>
void Set<T>::add(T x) // додаєм елемент .
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
void Set<T>::remove(T x) // вилучаєм елемент
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
void Set<T>::clear() // Очищуєм весь масив
{
  for (int i = 0; i < position; ++i)
  {
      arr[i] = 0;
  }
}
template<typename T>
bool Set<T>::Check(T x) // Перевірка наявності елемента в множині
{
  bool check = false;
  for ( int i = 0; i < position; ++i)
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
int Set<T>::set_size() //Розмір множини
{
 return position;  // повертає кількість елементів які вже є в множині
}
template<typename T>
Set<T> Set<T>::union_(Set& S) //Обєднання множин
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
Set<T> Set<T>::intersect(Set& S) // Перетин множин
{
    Set in;
    for (int i = 0; i < position; ++i)
    {
        for (int j = 0; j < S.position; ++j )
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
Set<T> Set<T>::difference (Set& S) // Різниця двох множин
{
    Set dif;
    for (int i = 0; i < position; ++i)
    {
        bool check = true;
        for (int j = 0; j < S.position; ++j )
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
void Set<T>::print(ostream& os) // вивід в потік
{
 for (int i = 0; i < position; ++i)
 {
     os << arr[i] << ' ';
 }
 os << endl;
}

