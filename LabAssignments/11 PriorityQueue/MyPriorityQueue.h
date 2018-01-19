// Programmer: Curtis Lee
// Programmer's ID: 1489029

#ifndef MyPriorityQueue_h
#define MyPriorityQueue_h

#include <algorithm>
using namespace std;

template <typename V>
class MyPriorityQueue
{
  int siz;
  int cap;
  V* values;
  void capacity(int);
  
public:
  MyPriorityQueue(int=2);
  void push(const V&);
  void pop();
  V top() const{return values[0];}
  int size(){return siz;}
  bool empty(){return siz==0;}
  void clear(){siz=0;}
  MyPriorityQueue(const MyPriorityQueue<V>&);
  ~MyPriorityQueue() {delete[] values;}
  MyPriorityQueue<V>& operator=(const MyPriorityQueue<V>&);
};

template <typename V>
MyPriorityQueue<V>::MyPriorityQueue(int CAP)
{
  this->cap = CAP;
  siz = 0;
  values = new V[cap];
  
  for (int index = 0; index < cap; index++)
  {
    values[index] = V();
  }
}

template <typename V>
void MyPriorityQueue<V>::capacity(int newCap)
{
  V* temp = new V[newCap];
  
  // get the lesser of the new and old capacities
  int limit = min(newCap, cap);
  
  // copy the contents
  for (int i = 0; i < limit; i++)
  {
    temp[i] = values[i];
  }
  
  // set added values to their defaults
  for (int i = limit; i < cap; i++)
  {
    temp[i] = V();
  }
  
  // deallocate original array
  delete [] values;
  
  // switch newly allocated array into the object
  values = temp;
  
  // update the capacity
  cap = newCap;
}


template <typename V>
void MyPriorityQueue<V>::push(const V& e)
{
  if (siz >= cap)
  {
    capacity(2 * cap);
  }
  values[siz] = e;
  int index = siz;
  int pIndex = ((index + 1) / 2) - 1;
  while (!(pIndex < 0 || values[index] < values[pIndex]))
  {
    swap(values[index], values[pIndex]);
    index = pIndex;
    pIndex = ((index + 1) / 2) - 1;
  }
  siz++;
}

template <typename V>
void MyPriorityQueue<V>::pop()
{
  siz--;
  int index = 0;
  while(true)
  {
    int lIndex = 2 * index + 1;
    int rIndex = 2 * index + 2;
    if(rIndex < siz)
    {
      if(values[lIndex] < values[siz] && values[rIndex] < values[siz])
      {
        break;
      }
      else if(values[siz] < values[lIndex] && values[rIndex] < values[lIndex])
      {
        values[index] = values[lIndex];
        index = lIndex;
      }
      else
      {
        values[index] = values[rIndex];
        index = rIndex;
      }
    }
    else if(lIndex < siz)
    {
      if(values[lIndex] < values[siz])
      {
        break;
      }
      else
      {
        values[index] = values[lIndex];
        index = lIndex;
      }
    }
    else
    {
      break;
    }
  }
  values[index] = values[siz];
}

template <typename V>
MyPriorityQueue<V>::MyPriorityQueue(const MyPriorityQueue<V>& original)
{
  siz = original.siz;
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
  {
    values[i] = original.values[i];
  }
}

template <typename V>
MyPriorityQueue<V>& MyPriorityQueue<V>::operator=(const MyPriorityQueue<V>& original)
{
  if (this != &original)
  {
    delete[] values;
    
    cap = original.cap;
    siz = original.siz;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
    {
      values[i] = original.values[i];
    }
  }
  return *this;
}

#endif
