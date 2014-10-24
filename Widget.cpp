#include "Widget.h"


      Widget::Widget(double price)
      {
		    cost = price;
      }

      Widget::~Widget()
      {
      }

     double Widget::getCost()
     {
     	return cost;
     }