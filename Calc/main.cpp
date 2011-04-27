#include <string>
#include <iostream>
#include "ElementList.h"
#include "Error.h"
void main()
{
   std::string sState = "1***3";
   CElementList el(sState);
   try
   {
      el.CreateTree();
      double t = el.Calc();
      std::cout << t << std::endl;
   }
   catch (CError e)
   {
      std::cout << e.Info();   
   }
}