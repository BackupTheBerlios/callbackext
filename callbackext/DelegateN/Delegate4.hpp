/*
 * Copyright 2005 Vinzenz Feenstra - evilissimo@users.sourceforge.net
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef GUARD_DELGATES_DELEGATE4_HPP_INCLUDED
#define GUARD_DELGATES_DELEGATE4_HPP_INCLUDED 1

#include "DelegateBase.hpp"

namespace DL 
  {
  /** Delegate for 4 Param
  *
  */
  template < class ReturnType , 
    class ClassType  , 
    class Param1     ,
    class Param2     ,
    class Param3     ,
    class Param4     
    >
  class Delegate4 : public DelegateBase 
  {
  ClassType* m_class_obj;
  ReturnType (ClassType::*m_method)(Param1,Param2,Param3,Param4);
  Param1 m_val1;
  Param2 m_val2;
  Param3 m_val3;
  Param4 m_val4;
  Delegate4(){}
  public:
  Delegate4(ClassType* class_obj,
    ReturnType (ClassType::*method)(Param1,Param2,Param3,Param4),
    Param1 val1 = Param1(),
    Param2 val2 = Param2(),
    Param3 val3 = Param3(),
    Param4 val4 = Param4()):
    m_class_obj(class_obj), m_method(method),
    m_val1(val1),m_val2(val2),m_val3(val3),
    m_val4(val4)
    {}
  virtual ~Delegate4(){}
  void operator()()
  {
  (*m_class_obj.*m_method)(m_val1,m_val2,m_val3,m_val4);
  }
  ReturnType operator()(Param1 val1,Param2 val2,Param3 val3,Param4 val4)
  {
    return (*m_class_obj.*m_method)(val1,val2,val3,val4);
  }
  void Invoke()
  {
  (*m_class_obj.*m_method)(m_val1,m_val2,m_val3,m_val4);
  }
  ReturnType Invoke(Param1 val1,Param2 val2,Param3 val3,Param4 val4)
  {
    return (*m_class_obj.*m_method)(val1,val2,val3,val4);
  }
  };
  
  //######################################################################################################
  template < class ReturnType , class ClassType , class Param1  , 
             class Param2     , class Param3    , class Param4  
     >
  DelegateObj create_delegate( ClassType & obj , ReturnType(ClassType::*Meth)(Param1,Param2,Param3,Param4), Param1 & param1 , Param2 & param2 , Param3 & param3, Param4 & param4)
  {
  return DelegateObj(new Delegate4<ReturnType,ClassType,Param1,Param2,Param3,Param4>(&obj,Meth,param1,param2,param3,param4));
  }
  
  template < class ReturnType , class ClassType , class Param1  , 
             class Param2     , class Param3    , class Param4  
     >
  DelegateObj create_delegate( ClassType * obj , ReturnType(ClassType::*Meth)(Param1,Param2,Param3,Param4), Param1 & param1 , Param2 & param2 , Param3 & param3, Param4 & param4)
  {
  return DelegateObj(new Delegate4<ReturnType,ClassType,Param1,Param2,Param3,Param4>(obj,Meth,param1,param2,param3,param4));
  }
  
} // namespace DL
#endif // GUARD_DELGATES_DELEGATE4_HPP_INCLUDED
