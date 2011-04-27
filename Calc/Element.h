/// @file Element.h
/// @brief CElement declaration header
/// @author Nadzuga Vladyslav
/// @date Created on: 17-March-2011

#pragma once
#include <vector>

/// @class CElement
/// @brief Class contains abstract structure for Digits or Signs
/// @respons !!!!!!!!!!!
/// @collab No collaboration is made
class CElement
{
public:
   /// @brief Default ctor
   CElement();

   /// @brief virtual dtor
   virtual ~CElement();

   /// @brief Virtual function for getting value of the statement
   virtual double Calc() = 0;

   
   /// @brief Virtual function for setting left node in a tree
   /// @param i_rElement - left pointer to be set on the left side of the node   
   virtual void SetLeftElement(const std::shared_ptr<CElement> & element) = 0;

   /// @brief Virtual function for setting right node in a tree
   /// @param i_rElement - right pointer to be set on the left side of the node
   virtual void SetRightElement(const std::shared_ptr<CElement> & element) = 0;

   /// @brief Virtual function for getting symbol which represents operation + - / *
   virtual char GetId() = 0;   

private:
};
