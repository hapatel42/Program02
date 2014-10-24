#if !defined NULL
#define NULL 0
#endif

#if !defined (STACKDEQUE_H)
#define STACKDEQUE_H

#include "DequeArray.h"


template < class T >
class StackDeque
{

   private:
      DequeArray<T>* deque;

   public:
      StackDeque();
      ~StackDeque();

      bool isEmpty();
      int size();
      void popAll();

      T* peek();
      void push(T* item);
      T* pop();

};

template < class T >
StackDeque<T>::StackDeque()
{
   deque = new DequeArray<T>();
}

template < class T >
StackDeque<T>::~StackDeque()
{
   deque->~DequeArray();
}

template < class T >
bool StackDeque<T>::isEmpty() 
{
   return deque->isEmpty();
}  

template < class T >
int StackDeque<T>::size()
{
   return deque->size();
}

template < class T >
T* StackDeque<T>::peek()
{
   return deque->peekDeque();
}  

template < class T >
void StackDeque<T>::push(T* item)
{
   deque->enqueue(item);
}  

template < class T >
T* StackDeque<T>::pop()
{

   return deque->dequeueDeque();
} 



template < class T >
void StackDeque<T>::popAll()
{
   deque->dequeueAll();
}  

#endif