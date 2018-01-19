// Programmer: Curtis Lee
// Programmer's ID: 1489029

#ifndef MYASSOCIATIVEARRAY_H_INCLUDED
#define MYASSOCIATIVEARRAY_H_INCLUDED

#include <queue>
using namespace std;

template <typename K, typename V>
class MyAssociativeArray
{
  struct Node
  {
    K key;
    V value;
    Node* next;
  };
  
  Node* firstNode;
  int siz;
  Node* dummy;
  
public:
  MyAssociativeArray();
  ~MyAssociativeArray(){clear();}
  MyAssociativeArray(const MyAssociativeArray<K, V>&);
  MyAssociativeArray<K, V>& operator=(const MyAssociativeArray<K, V>&);
  V& operator[](const K&); // setter
  V operator[](const K&) const; // getter
  bool containsKey(const K&) const; // getter
  void deleteKey(const K&); // setter
  int size() const {return siz;}
  void clear();
  queue<K> keys() const;
};

template <typename K, typename V>
MyAssociativeArray<K, V>::MyAssociativeArray()
{
  firstNode = 0;
  siz = 0;
}

template <typename K, typename V>
MyAssociativeArray<K, V>::MyAssociativeArray(const MyAssociativeArray<K, V>& original)
{
  firstNode = 0;
  Node* lastNode = 0; // temporary tail
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->key = p->key;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template <typename K, typename V>
MyAssociativeArray<K, V>& MyAssociativeArray<K, V>::operator=(const MyAssociativeArray<K, V>& original)
{
  if (this != &original)
  {
    // deallocate existing list
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }
    
    // build new MyAssociativeArray
    Node* lastNode = 0;
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->key = p->key;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

template <typename K, typename V>
V& MyAssociativeArray<K, V>::operator[](const K& key)
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
    {
      return p->value;
    }
  }
  ++siz;
  Node* temp = new Node;
  temp->key = key;
  temp->value = V();
  temp->next = firstNode;
  firstNode = temp;
  return firstNode->value;
}

template <typename K, typename V>
V MyAssociativeArray<K, V>::operator[](const K& key) const
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
    {
      return p->value;
    }
  }
  return dummy->value;
}

template <typename K, typename V>
bool MyAssociativeArray<K, V>::containsKey(const K& key) const
{
  for (Node* p = firstNode; p; p = p->next)
  {
    if (p->key == key)
    {
      return true;
    }
  }
  return false;
}

template <typename K, typename V>
void MyAssociativeArray<K, V>::deleteKey(const K& key)
{
  // find the matching node
  Node* p, *prev; // declare above loop so that it survives below the loop
  for (p = firstNode, prev = 0; p; prev = p, p = p->next)
  {
    if (p->key == key)
    {
      break;
    }
  }
  
  // if found (that is, p did not run off the end of the list)
  if (p)
  {
    --siz;
    if (prev) prev->next = p->next; // skips over the node at p
    else firstNode = p->next; // there's a new head, possibly zero
    delete p; // we're done with this node
  }
}

template <typename K, typename V>
void MyAssociativeArray<K, V>::clear()
{
  while(firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
  firstNode = 0;
  siz = 0;
}

template <typename K, typename V>
queue<K> MyAssociativeArray<K, V>::keys() const
{
  queue<K> retQ;
  Node* p;
  for (p = firstNode; p; p = p->next)
  {
    retQ.push(p->key);
  }
  return retQ;
}


#endif
