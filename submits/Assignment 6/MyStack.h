// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Stack Template

#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include <algorithm>
using namespace std;

template <typename V>
class MyStack
{
  V* values;
  int cap;
  int siz; // track size
  void capacity(int);

  public:
  MyStack(int = 2);
  void push(const V&);
  V& peek();
  void pop(){if(siz > 0) --siz;}
  int size()const {return siz;}
  bool empty()const {return siz==0;}
  void clear(){siz = 0;}
  ~MyStack(){delete[] values;}
  MyStack<V>& operator=(const MyStack<V>&);
  MyStack(const MyStack<V>&);
};

template <typename V>
MyStack<V>::MyStack(int cap)
{
  this->cap = cap;
  values = new V[cap];
  for (int index = 0; index < cap; index++)
    values[index] = V();
  siz = 0;
}

template <typename V>
void MyStack<V>::push(const V& value)
{
  if (siz == cap) capacity(2 * cap); // double the capacity if full
  values[siz] = value;
  ++siz;
}

template <typename V>
V& MyStack<V>::peek()
{
  if (siz < 0)
    return values[0];
  else if (siz >= cap)
    capacity(2 * siz);
  return values[siz-1];
}

template <typename V>
MyStack<V>& MyStack<V>::operator=(const MyStack<V>& original)
{
  if (this != &original)
  {
    delete[] values;
    cap = original.cap;
    siz = original.siz;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
      values[i] = original.values[i];
  }
  return *this;
}

template <typename V>
MyStack<V>::MyStack(const MyStack<V>& original)
{
  siz = original.siz;
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <typename V>
void MyStack<V>::capacity(int newCap)
{
  V* temp = new V[newCap];
  int limit = min(newCap,cap);
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];
  for (int i = limit; i < cap; i++)
    temp[i] = V();
  delete[] values;
  values = temp;
  cap = newCap;
}

#endif // MYSTACK_H_INCLUDED
