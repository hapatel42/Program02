#if !defined NULL
#define NULL 0
#endif

#if !defined (INVENTORYMANAGER_H)
#define INVENTORYMANAGER_H

#include "Widget.h"
#include "StackDeque.h"
#include "QueueDeque.h"

/*
*This class is for use with the Widget class.
*It is an inventory manager that lets you choose how the inventory is managed
*you can have First in First out behavior (FIFO)
*or Last in First out behavior (LIFO)
*This class keeps track of total profit from sales, and allows you to buy or sell more widgets at different prices.
*/

class InventoryManager
{
private:
	bool LIFO; //Type of management.
	StackDeque<Widget>* stack; //for LIFO
	QueueDeque<Widget>* queue; //for FIFO
	double total_profit; //profit after all sales


public:

	/*
	*PRE:
	*  	inventory_choice is either a 1 for LIFO or a 2 for FIFO
	*POST:
	*	creates either a StackDeque or a QueueDeque depending on choice
	*/
	InventoryManager(int inventory_choice); //LIFO or FIFO
	/*
	*PRE:
	*	none
	*POST:
	*	only deletes the stack or queue, not the items within
	*/
	~InventoryManager();
	/*
	*PRE:
	*	cost is the amount paid for the widgets
	*	num_to_buy is the number of widgets bought at that price
	*POST:
	*	adds widgets (with cost stored) to either array
	*/
	void buyWidgets(double cost, int num_to_buy);
	/*
	*PRE:
	*	must have already constructed the InventoryManager
	*POST:
	*	returns the total profit from sales so far
	*/
	double getTotalProfit();
	/*
	*PRE:
	*	price is the amount you are selling the widgets for
	*	num_to_sell is the number of widgets sold at that price
	*POST:
	*	returns the profit from that transaction.
	*/
	double sellWidgets(double price, int num_to_sell);
};

#endif 