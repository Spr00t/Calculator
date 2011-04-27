#include <string>
#include "ElementList.h"
#include "Digit.h"
#include "Sign.h"
#include "Element.h"
using namespace std;

CElementList::CElementList(const std::string & i_sStr)
{
   int i = 0;
   std::string sTemp;
   while (i_sStr.size() > i)
   {
      /// @brief variable contains digit
      sTemp = "";
      while(i_sStr[i] >= '0' && i_sStr[i] <= '9')
      {
         sTemp += i_sStr[i];
         ++i;
      }
      std::shared_ptr<CElement> digit(new CDigit(sTemp));      
      this->m_Els.push_back(digit);

      std::shared_ptr<CElement> sgn(new CSign(i_sStr[i]));            
      m_Els.push_back(sgn);   
      i++;
   }
}
CElementList::~CElementList()
{

}

std::shared_ptr<CElement>  CElementList::CreateTree()
{
   this->m_head = CreateTree3(m_Els.begin(), m_Els.end());
   return m_head;
}

std::shared_ptr<CElement> CreateTree3(
   std::vector<std::shared_ptr<CElement>>::iterator & i_rit, 
   const std::vector<std::shared_ptr<CElement>>::iterator & i_ritEnd)
{
   if (i_rit == i_ritEnd)
   {      
      return std::shared_ptr<CElement>(0);
   }
   
   std::shared_ptr<CElement> left = (*(i_rit++)), temp;
   CreateTree2(i_rit, left, i_ritEnd);
   

   if (i_rit == i_ritEnd)
   {        
      return left;
   }

   if ((*i_rit)->GetId() == '+' || (*i_rit)->GetId() == '-')
   {  
      std::shared_ptr<CElement> &ret = *i_rit;
      i_rit++;
      ret->SetLeftElement(left);
      ret->SetRightElement(CreateTree3(i_rit, i_ritEnd));  
      return ret;
   }
   else
   {
      //throws exception when it is digit
      (*i_rit)->GetId(); 
      return left;   
   }
   
}

void CreateTree2(
   std::vector<std::shared_ptr<CElement>>::iterator & i_rit, 
   std::shared_ptr<CElement> & el,
   const std::vector<std::shared_ptr<CElement>>::iterator & i_ritEnd)
{   
   if (i_rit == i_ritEnd)
   {
      return ;
   }
   
   std::shared_ptr<CElement> & left = el;   

   if (i_rit == i_ritEnd)
   {        
      return ;
   }

   if ((*i_rit)->GetId() == '*' || (*i_rit)->GetId() == '/')
   {      
      std::shared_ptr<CElement> & ret = (*i_rit);
      ret->SetLeftElement(left);
      ret->SetRightElement(CreateTree1(++i_rit, i_ritEnd));      
      CreateTree2(i_rit, ret, i_ritEnd);
      el = ret;
   }
   else
   {
      //throws exception when it is digit
      (*i_rit)->GetId(); 
   }
   
}

std::shared_ptr<CElement> CreateTree1(
   std::vector<std::shared_ptr<CElement>>::iterator & i_rit, 
   const std::vector<std::shared_ptr<CElement>>::iterator & i_ritEnd)
{
   std::shared_ptr<CElement> ret(*i_rit);   
   ++i_rit;
   return ret;
}