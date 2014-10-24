#if !defined NULL
#define NULL 0
#endif

#if !defined (WIDGET_H)
#define WIDGET_H

#include "DequeArray.h"

class Widget
{

   private:

      double cost;

   public:
      Widget(double price);
      ~Widget();

      double getCost();
};


#endif