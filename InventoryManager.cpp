#include "InventoryManager.h"


InventoryManager::InventoryManager(int inventory_choice)  //LIFO or FIFO
{
	if(inventory_choice == 1)
	{
		LIFO = true;
		stack = new StackDeque<Widget>;
		total_profit = 0;
		queue = NULL;
	}

	else 
	{
		LIFO = false;
		queue = new QueueDeque<Widget>;
		total_profit = 0;
		stack = NULL;
	}
} 

InventoryManager::~InventoryManager()
{
	if(LIFO)
	{
		delete stack;
	}
	else
	{
		delete queue;
	}
}

void InventoryManager::buyWidgets(double cost, int num_to_buy)
{
	Widget* wid; 
	for(int i = 0; i < num_to_buy; i++)
	{
		wid = new Widget(cost);

		if(LIFO)
		{
			stack->push(wid);
		}

		else
		{
			queue->enqueue(wid);
		}
	}
}

double InventoryManager::getTotalProfit()
{
	return total_profit;
}

double InventoryManager::sellWidgets(double price, int num_to_sell)
{
	double profit = 0;
	Widget* wid;
	double cost = 0;
	double total_cost = 0;

	for(int i = 0; i < num_to_sell; i++)
	{

		if(LIFO)
		{
			if(!stack->isEmpty())
			{
				wid = stack->pop();
				cost = wid->getCost();

				profit = profit + (price - cost);
			}
		}

		else
		{
			if(!queue->isEmpty())
			{
				wid = queue->dequeue();
				cost = wid->getCost();
			
				profit = profit + (price - cost);
			}
		}
	}

	total_profit = total_profit + profit;

	return profit;
}
