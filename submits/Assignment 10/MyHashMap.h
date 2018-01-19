// Programmer: Curtis Lee
// Programmer's ID: 1489029

#ifndef MyHashMap_h
#define MyHashMap_h

#include <list>
#include <queue>
using namespace std;

template <typename K, typename V, int CAP>
class MyHashMap
{
  struct Node
  {
    K key;
    V value;
  };
  
  list<Node> data[CAP];
  int(*hc)(const K&);
  int siz;
  Node dummy;
  
public:
  MyHashMap(int(*)(const K&)=0);
  V operator[](const K&) const; // getter
  V& operator[](const K&); // setter
  bool containsKey(const K&) const; // getter
  void deleteKey(const K&); // setter
  int size() const {return siz;}
  void clear();
  queue<K> keys() const;
};

template <typename K, typename V, int CAP>
MyHashMap<K, V, CAP>::MyHashMap(int(*p)(const K&))
{
  siz = CAP;
  hc = p;
}

template <typename K, typename V, int CAP>
void MyHashMap<K, V, CAP>::clear()
{
  for(int i = 0; i < siz; i++)
  {
    data[i].clear();
  }
}

template <typename K, typename V, int CAP>
V MyHashMap<K, V, CAP>::operator[](const K& key) const
{
  int index = hc(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it; // getters need to use const_iterator
  for (it = data[index].begin(); it != data[index].end(); it++)
  {
    if (it->key == key)
    {
      return it->value;
    }
  }
  return dummy.value;
}

template <typename K, typename V, int CAP>
V& MyHashMap<K, V, CAP>::operator[](const K& key)
{
  int index = hc(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
  {
    if (it->key == key)
    {
      return it->value;
    }
  }
  Node temp;
  temp.key = key;
  temp.value = V();
  data[index].push_back(temp);
  return data[index].back().value;
}

template <typename K, typename V, int CAP>
void MyHashMap<K, V, CAP>::deleteKey(const K& key)
{
  int index = hc(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
  {
    if (it->key == key)
    {
      delete data[index];
    }
  }
}

template <typename K, typename V, int CAP>
bool MyHashMap<K, V, CAP>::containsKey(const K& key) const
{
  
  int index = hc(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
  {
    if (it->key == key)
    {
      return true;
    }
  }
  return false;
}

template <typename K, typename V, int CAP>
queue<K> MyHashMap<K, V, CAP>::keys() const
{
  queue<K> retQ;
  typename list<Node>::const_iterator it;
  for(int i = 0; i < siz; i++)
  {
    for (it = data[i].begin(); it != data[i].end(); ++it)
    {
      retQ.push(it->key);
    }
  }
  return retQ;
}

#endif
