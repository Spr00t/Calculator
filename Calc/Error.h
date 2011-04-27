/// @file Error.h
/// @brief CError declaration header
/// @author Nadzuga Vladyslav
/// @date Created on: 18-March-2011

#pragma once
#include <string>
/// @class CError
/// @brief Class contains abstract structure for errors
/// @respons 
/// @collab No collaboration is made
class CError
{
public:
   enum EError 
   {
      /// @brief "TRYING TO MAKE A TREE FROM DIGIT"
      eE1,

      /// @brief "TRYING TO MAKE A TREE FROM DIGIT"
      eE2
   };

   /// @brief Ctor
   /// @param i_err error type which we have   
   CError(const EError i_err):
      m_error(i_err)      
   {
      m_Errors[eE1] = "TRYING TO MAKE A TREE IN DIGIT";
      m_Errors[eE2] = "TRYING TO GET ID FROM DIGIT";      
   }
   
   /// @brief Some message about the error
   /// @returns string
   std::string & Info() const
   {
      return m_Errors[m_error];
   }

   /// @brief Set Error type
   /// @param i_Error is error kind
   void SetError(const EError i_Error)
   {
      m_error = i_Error;
   }

   /// @brief Get error type we have
   /// @retrun error type
   EError GetError() const
   {
      return m_error;   
   }
private:

   /// @brief logicaly constant strings
   static std::string m_Errors[8];

   /// @brief error type
   EError m_error;
};