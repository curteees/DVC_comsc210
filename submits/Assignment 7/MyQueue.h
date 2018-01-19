// Programmer: Curtis Lee
// Programmer's ID: 1489029

#ifndef MyQueue_h
#define MyQueue_h

template <typename V>
class MyQueue
{
  struct Node
  {
    V value;
    Node* next;
  };
  Node* firstNode, *lastNode;
  int siz;
  
  public:
  MyQueue();
  void push(const V&);
  V& front(); // return a mutable reference to the oldest node
  V& back(); // return a mutable reference to the newest node
  void pop(); // remove the oldest node
  int size() const {return siz;}
  bool empty() const {return siz == 0;}
  void clear();
  ~MyQueue(){clear();}
  MyQueue<V>& operator=(const MyQueue<V>&);
  MyQueue(const MyQueue<V>&);
};

template <typename V>
MyQueue<V>::MyQueue()
{
  firstNode = lastNode = 0;
  siz = 0;
}

template <typename V>
void MyQueue<V>::push(const V& value)
{
  Node* temp = new Node;
  temp->value = value;
  temp->next = 0;
  if (lastNode) lastNode->next = temp;
  else firstNode = temp;
  lastNode = temp;
  ++siz;
}

template <typename V>
V& MyQueue<V>::front()
{
  return firstNode->value;
}

template <typename V>
V& MyQueue<V>::back()
{
  return lastNode->value;
}

template <typename V>
void MyQueue<V>::pop()
{
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
  if (!siz) lastNode = 0;
}

template <typename V>
void MyQueue<V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
  lastNode = 0;
}

template <typename V>
MyQueue<V>& MyQueue<V>::operator=(const MyQueue<V>& original)
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
    
    // build new queue
    lastNode = 0;
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
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

template <typename V>
MyQueue<V>::MyQueue(const MyQueue<V>& original)
{
  firstNode = 0;
  lastNode = 0;
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

#endif



