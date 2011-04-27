#include "Sign.h"
#include "Digit.h"

CSign::CSign(const char cSign)
{
   this->m_sign = cSign;
}

CSign::~CSign()
{

}


double CSign::Calc()
{
   switch (this->m_sign)
   {
      case '+':
         return m_right->Calc() + m_left->Calc();
      case '-':
         return m_left->Calc() - m_right->Calc();
      case '/':
         return m_left->Calc() / m_right->Calc();
      case '*':
         return m_left->Calc() * m_right->Calc();
   }

}