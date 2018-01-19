// Programmer: Curtis Lee
// Programmer's ID: 1489029

#ifndef MySortableArray_h
#define MySortableArray_h

#include <algorithm>
using namespace std;

template <typename V>
class MySortableArray
{
  V* values;
  int cap;
  V dummy;
  
  public:
  MySortableArray(int=2);
  ~MySortableArray(){delete[] values;}
  MySortableArray(const MySortableArray<V>&);
  MySortableArray<V>& operator=(const MySortableArray<V>&);
  int capacity() const {return cap;}
  V& operator[](int);
  V operator[](int) const;
  void capacity(int);
  void sort(int);
};

template <typename V>
MySortableArray<V>::MySortableArray(int cap)
{
  this->cap = cap;
  values = new V[cap];
  
  for (int index = 0; index < cap; index++)
  {
    values[index] = V();
  }
}

template <typename V>
MySortableArray<V>::MySortableArray(const MySortableArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
  {
    values[i] = original.values[i];
  }
}

template <typename V>
MySortableArray<V>& MySortableArray<V>::operator=(const MySortableArray<V>& original)
{
  if (this != &original)
  {
    delete [] values;
    
    cap = original.cap;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
    {
      values[i] = original.values[i];
    }
  }
  return *this;
}

template <typename V>
V& MySortableArray<V>::operator[](int index)
{
  if (index < 0)
  {
    return dummy;
  }
  else if (index >= cap)
  {
    capacity(2 * index);
  }
  return values[index];
}

template <typename V>
V MySortableArray<V>::operator[](int index) const
{
  if (index < 0 || index >= cap)
    return V();
  return values[index];
}

template <typename V>
void MySortableArray<V>::capacity(int newCap)
{
  V* temp = new V[newCap];
  
  // get the lesser of the new and old capacities
  int limit = min(newCap,cap);
  
  // copy the contents
  for(int i = 0; i < limit; i++)
  {
    temp[i] = values[i];
  }
  
  // set added values to their defaults
  for(int i = limit; i < cap; i++)
  {
    temp[i] = V();
  }
  
  // deallocate original array
  delete[] values;
  
  // switch newly allocated array into the object
  values = temp;
  
  // update the capacity
  cap = newCap;
}

template <typename V>
void MySortableArray<V>::sort(int endIndex)
{
  int* temp = new int[endIndex];
  for (int delta = 1; delta < endIndex; delta *= 2)
  {
    int index = 0;
    for (int i = 0; i < endIndex; i++)
    {
      temp[i] = values[i];
    }
    for (int i = 0; i < endIndex; i += 2 * delta)
    {
      int left = i;
      int leftMax = min(left + delta, endIndex);
      int right = leftMax;
      int rightMax = min(right + delta, endIndex);
      while (true)
      {
        if (left == leftMax && right == rightMax) break;
        if (left == leftMax) values[index++] = temp[right++];
        else if (right == rightMax) values[index++] = temp[left++];
        else if (temp[right] < temp[left]) values[index++] = temp[right++];
        else values[index++] = temp[left++];
      }
    }
  }
}

#endif
