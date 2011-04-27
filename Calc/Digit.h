/// @file Digit.h
/// @brief CDigit declaration header
/// @author Nadzuga Vladyslav
/// @date Created on: 17-March-2011

#pragma once
#include <string>
#include <memory>
#include "Element.h"
#include "Error.h"

/// @class CDigit 
/// @brief Class contains Digits value
/// @respons !!!!!!!!!!!
/// @collab No collaboration is made
class CDigit : public CElement
{
public:
      
   /// @brief Default ctor
   /// @param CString & i_rsVal digital Value   
   CDigit(const std::string & i_rsVal);

   /// @brief Default ctor
   CDigit() {}

   /// @brief dtor
   virtual ~CDigit();
   
   /// @brief Virtual function for getting value of the statement
   /// @returns the digit
   virtual double Calc();

   /// @brief Virtual function for setting left node in a tree
   /// @param i_rElement - left pointer to be set on the left side of the node
   virtual void SetLeftElement(const std::shared_ptr<CElement> & i_pElement) 
   {
      throw CError(CError::EError::eE1);
   }

   /// @brief Virtual function for setting right node in a tree
   /// @param i_rElement - right pointer to be set on the left side of the node
   virtual void SetRightElement(const std::shared_ptr<CElement> & i_pElement) 
   {
      throw CError(CError::EError::eE1);
   }

   /// @brief Virtual function for getting symbol which represents element   
   virtual char GetId() 
   {
      throw CError(CError::EError::eE2);
   }
   
private:
   /// @brief digit value
   int m_val;
};
