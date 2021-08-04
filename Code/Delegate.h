//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
template <typename Result, typename... Args> class CDelegate
{
   class VoidClass;
private:
   VoidClass *object;
   union
   {
      Result (VoidClass::*method)(Args...);
      Result (*function)(Args...);
   };

public:
   CDelegate()
   {
      object = nullptr;
      method = nullptr;
      function = nullptr;
   }

   CDelegate(Result (*Function)(Args...))
   {
      object = nullptr;
      method = nullptr;
      function = Function;
   }

   template <typename T> CDelegate(T *Object, Result (T::*Method)(Args...))
   {
      object = (VoidClass *)Object;
      method = (Result (VoidClass::*)(Args...))Method;
   }

   void Connect(Result (*Function)(Args...))
   {
      object = nullptr;
      method = nullptr;
      function = Function;
   }

   template <typename T> void Connect(T *Object, Result (T::*Method)(Args...))
   {
      object = (VoidClass *)Object;
      method = (Result (VoidClass::*)(Args...))Method;
   }

   Result operator()(Args... Params)
   {
      if (object != nullptr)
      {
         return (object->*method)(Params...);
      }
      else
      {
         return function(Params...);
      }
   }

   bool IsVoid() const
   {
      if (object != nullptr)
      {
         return method == nullptr;
      }
      else
      {
         return function == nullptr;
      }
   }
};
//---------------------------------------------------------------------------
