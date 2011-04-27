/// @file ElementList.h
/// @brief CElementList declaration header
/// @author Nadzuga Vladyslav
/// @date Created on: 17-March-2011

#pragma once
#include <vector>
#include <string>
#include "Element.h"

/// @class CElementList
/// @brief Class contains array of Elements
/// @respons !!!!!!!!!!!
/// @collab No collaboration is made
class CElementList
{
public:
   /// @brief Default ctor
	/// @param i_numVertex total vertex Number in Graph
   CElementList(const std::string & i_sStr);
   
   /// @brief dtor
   virtual ~CElementList();

   /// @brief Create element tree
   /// @return pointer to the head of a tree
   std::shared_ptr<CElement>  CreateTree();

   /// @brief Calculates the statement
   /// @returns result of the equations
   double Calc() 
   { 
      return m_head->Calc();
   }

   
private:
   /// @brief memder contains Elements
   std::vector<std::shared_ptr<CElement>> m_Els;

   /// @brief memder contains the head of the calculated tree
   std::shared_ptr<CElement> m_head;

};

std::shared_ptr<CElement> CreateTree1(
   std::vector<std::shared_ptr<CElement>>::iterator & i_rit, 
   const std::vector<std::shared_ptr<CElement>>::iterator & i_ritEnd);

void CreateTree2(
   std::vector<std::shared_ptr<CElement>>::iterator & i_rit, 
   std::shared_ptr<CElement> & el,
   const std::vector<std::shared_ptr<CElement>>::iterator & i_ritEnd);

std::shared_ptr<CElement> CreateTree3(
   std::vector<std::shared_ptr<CElement>>::iterator & i_rit, 
   const std::vector<std::shared_ptr<CElement>>::iterator & i_ritEnd);