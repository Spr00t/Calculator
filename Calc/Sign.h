/// @file Sign.h
/// @brief CElement declaration header
/// @author Nadzuga Vladyslav
/// @date Created on: 17-March-2011

/// @class CElement
/// @brief Class contains abstract structure for Digits or Signs
/// @respons !!!!!!!!!!!
/// @collab No collaboration is made
#pragma once
#include <vector>
#include "Element.h"
#include "Error.h"
class CSign : public CElement
{
public:
   /// @brief ctor
   /// @param cSign is textual presentation of sign
   CSign(const char i_cSign);

   /// @brief Default ctor
   CSign():
      m_left(0), 
      m_right(0)
      {}

   /// @brief virtual dtor
   virtual ~CSign();

   /// @brief We set the sign
   /// @param i_cSign - sign to be set
   void SetSign(const char i_cSign) {m_sign = i_cSign; }   
      
   /// @brief Virtual function for getting value of the statement
   virtual double Calc();

   virtual void SetLeftElement(const std::shared_ptr<CElement> & element) 
   {
      m_left = element;
   }

   virtual void SetRightElement(const std::shared_ptr<CElement> & element) 
   {
      m_right = element;
   }

   virtual char GetId() 
   {
      return m_sign;
   }
private:
   char m_sign;
   std::shared_ptr<CElement> m_left;
   std::shared_ptr<CElement> m_right;
};   
