
#include "DequeArray.h"

using namespace std;
#include <iostream>


int main()
{

	DequeArray<int>* deque = new DequeArray<int>;

	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int num4 = 4;
	int num5 = 5;
	int num6 = 6;
	int num7 = 7;
	int num8 = 8;
	int num9 = 9;
	int num10 = 10;

	deque->enqueue(&num1);
	deque->enqueue(&num2);
	deque->enqueue(&num3);
	deque->enqueue(&num4);						//1,2,3,4
	int* f_pop = deque->dequeueDeque(); 		//1,2,3
	int* s_pop = deque->dequeueDeque();			//1,2
	cout << *f_pop << endl; 
	cout << *s_pop << endl;
	int* f_peek = deque->peek();
	cout << *f_peek << endl;
	deque->enqueue(&num5);						//1,2,5
	deque->enqueue(&num6);						//1,2,5,6

	deque->enqueueDeque(&num7);					//7,1,2,5,6
	deque->enqueueDeque(&num8);					//8,7,1,2,5,6
	deque->enqueueDeque(&num9);					//9,8,7,1,2,5,6
	int* f_deq = deque->dequeue();				//8,7,1,2,5,6 (return 9)
	int* s_deq = deque->dequeue();				//7,1,2,5,6 (return 8)
	cout << *f_deq << endl;
	cout << *s_deq << endl;
	deque->enqueueDeque(&num10);				//10,7,1,2,5,6

	int sze = deque->size();
	for(int i = 0; i <= (sze/2); i++)
	{
		int* pop = deque->dequeueDeque();
		if(pop != NULL)
		{
		cout << "pop: " << *pop << endl;
		}
	}

		int sze = deque->size();
	for(int i = 1; i <= sze; i++)
	{
		int* pop = deque->dequeue();
		if(pop != NULL)
		{
		cout << "pop: " << *pop << endl;
		}
	}
	cout<< "finish";


	return 0;
}