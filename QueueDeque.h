#if !defined NULL
#define NULL 0
#endif

#if !defined (QUEUEDEQUE_H)
#define QUEUEDEQUE_H

#include "DequeArray.h"

template < class T >
class QueueDeque
{

   private:

      DequeArray<T>* deque;

   public:
      QueueDeque();
      ~QueueDeque();

      bool isEmpty();
      int size();
      void dequeueAll();

      T* peek();
      void enqueue(T* item);
      T* dequeue();

};

template < class T >
QueueDeque<T>::QueueDeque() 
{
   deque = new DequeArray<T>();
}  

template < class T >
QueueDeque<T>::~QueueDeque() 
{
   deque->~DequeArray();
} 

template < class T >
bool QueueDeque<T>::isEmpty() 
{
   return deque->isEmpty();
}  

template < class T >
int QueueDeque<T>::size()
{
   return deque->size();
}

template < class T >
T* QueueDeque<T>::peek()
{
   return deque->peek(); 
} 

template < class T >
void QueueDeque<T>::enqueue(T* item)
{
   deque->enqueue(item);
} 

template < class T >
T* QueueDeque<T>::dequeue() 
{
   return deque->dequeue();
}

template < class T >
void QueueDeque<T>::dequeueAll() 
{
   deque->dequeueAll();
} 

#endif