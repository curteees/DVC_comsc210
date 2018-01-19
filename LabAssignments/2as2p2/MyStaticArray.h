// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Static Array Template

#ifndef MYSTATICARRAY_H_INCLUDED
#define MYSTATICARRAY_H_INCLUDED

template <typename V, int CAP>
class MyStaticArray
{
  V data[CAP];
  V dummy;

  public:
  MyStaticArray();
  int capacity() const{return CAP;}
  V& operator[](int); // setter
  V operator[](int) const; // getter
};

template <typename V, int CAP>
MyStaticArray<V, CAP>::MyStaticArray()
{
  for(int i = 0; i < CAP; i++)
    data[i] = V();
  dummy = V();
}

template <typename V, int CAP>
V& MyStaticArray<V, CAP>::operator[](int index)
{
  if(index >= 0 && index < CAP)
    return data[index];
  return dummy;
}

template <typename V, int CAP>
V MyStaticArray<V, CAP>::operator[](int index)const
{
  if(index >= 0 && index < CAP)
    return data[index];
  return dummy;
}

#endif // MYSTATICARRAY_H_INCLUDED
