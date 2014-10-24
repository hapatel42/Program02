#include "InventoryManager.h"
#include "Text.h"
using CSC2110::String;
#include "Keyboard.h"
using CSC2110::Keyboard;

#include <iostream>
#include <iomanip>
using namespace std;

int inventoryChoice()
{
   Keyboard* kb = Keyboard::getKeyboard();
   int inv_choice = kb->getValidatedInt("Are you using (1) LIFO or (2) FIFO inventory management? ", 1, 2);
   return inv_choice;
}

//DO THIS
//buy Widgets (check invalid input and reprompt if necessary)
void buyWidgets(InventoryManager* im)
{
   Keyboard* kb = Keyboard::getKeyboard();
   int num_to_buy = -1;
   double cost = -1;

   while(num_to_buy < 0)
   {
      num_to_buy = kb->readInt("How many widgets would you like to buy? ");
   }

   while(cost < 0)
   {
      cost = kb->readDouble("What is the cost for each widget? ");
   }

   im->buyWidgets(cost, num_to_buy);
}

//DO THIS
//sell Widgets and return the profit (check invalid input and reprompt if necessary)
double sellWidgets(InventoryManager* im)
{

   Keyboard* kb = Keyboard::getKeyboard();
   int num_to_sell = -1;
   double price = -1;

   while(num_to_sell < 0)
   {
      num_to_sell = kb->readInt("How many widgets would you like to sell? ");
   }

   while(price < 0)
   {
      price = kb->readDouble("What is the selling price for each widget? ");
   }

   double profit = im->sellWidgets(price, num_to_sell);

   cout << endl << endl << "Your profit on this transaction is $" << profit << endl << endl;

   return profit;
}

bool mainMenu(InventoryManager* im)
{
   Keyboard* kb = Keyboard::getKeyboard();
   int menu_choice = kb->getValidatedInt("1. Buy Widgets \r\n2. Sell Widgets\r\n3. Quit\r\nWhat would you like to do? ", 1, 3);

   double profit = 0;

   if (menu_choice == 1)
   {
      buyWidgets(im);
      return 1;
   }
   else if(menu_choice == 2)
   {
      sellWidgets(im);
      return 1;
   }
   else 
   {
      return 0;
   }
}

int main()
{
   cout << setprecision(2) << fixed;

   int inv_choice = inventoryChoice();
   InventoryManager* im = new InventoryManager(inv_choice);

   bool ask = 1;
   while (ask)
   {
      ask = mainMenu(im);
   }

   double running_total = im->getTotalProfit();
   cout << "Your total profit for all transactions is $" << running_total << endl;

   delete im;
}
