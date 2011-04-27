/// @file Digit.cpp
/// @brief CDigit implementation
/// @author Nadzuga Vladyslav
/// @date Created on: 17-March-2011
#include <string>
#include "Digit.h"

CDigit::CDigit(const std::string & i_rsVal)
{   
   //char * sTemp = new char [i_rsVal.size() + 1];
   sscanf(i_rsVal.c_str(), "%d", &m_val);
}

CDigit::~CDigit()
{
}
double CDigit::Calc()
{
   return m_val;
}