// Programmer: Curtis Lee
// Programmer's ID: 1489029

#ifndef MYDYNAMICARRAY_H_INCLUDED
#define MYDYNAMICARRAY_H_INCLUDED

#include <algorithm>
using namespace std;

template <typename V>
class MyDynamicArray
{
  V* data;
  V dummy;
  int cap;

  public:
  MyDynamicArray(int = 2);
  ~MyDynamicArray(){delete[] data;}
  MyDynamicArray(const MyDynamicArray<V>&);
  MyDynamicArray<V>& operator=(const MyDynamicArray<V>&);
  V& operator[](int); // setter
  V operator[](int) const; // getter
  int capacity()const {return cap;}
  void capacity(int);
};

template <typename V>
MyDynamicArray<V>::MyDynamicArray(int cap)
{
  this->cap = cap;
  data = new V[cap];
  for(int i = 0; i < cap; i++)
    data[i] = V();
  dummy = V();
}

template <typename V>
MyDynamicArray<V>::MyDynamicArray(const MyDynamicArray<V>& original)
{
  cap = original.cap;
  data = new V[cap];
  for (int i = 0; i < cap; i++)
    data[i] = original.data[i];
  dummy = original.dummy;
}

template <typename V>
MyDynamicArray<V>& MyDynamicArray<V>::operator=(const MyDynamicArray<V>& original)
{
  if (this != &original)
  {
    delete[] data;
    cap = original.cap;
    data = new V[cap];
    for (int i = 0; i < cap; i++)
      data[i] = original.data[i];
    dummy = original.dummy;
  }
  return *this;
}

template <typename V>
V& MyDynamicArray<V>::operator[](int index)
{
  if(index < 0)
    return dummy;
  if(index >= cap)
    capacity(2 * index);
  return data[index];

}

template <typename V>
V MyDynamicArray<V>::operator[](int index)const
{
  if(index >= 0 && index < cap)
    return data[index];
  return dummy;
}

template <typename V>
void MyDynamicArray<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit = min(cap, this->cap);
  for (int i = 0; i < limit; i++)
    temp[i] = data[i];
  for (int i = limit; i < cap; i++)
    temp[i] = V();
  delete[] data;
  data = temp;
  this->cap = cap;
}

#endif // MYDYNAMICARRAY_H_INCLUDED
