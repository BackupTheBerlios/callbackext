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
#ifndef GUARD_DELGATES_FUNCTOR1_HPP_INCLUDED
#define GUARD_DELGATES_FUNCTOR1_HPP_INCLUDED 1

#include "../DelegateN/DelegateBase.hpp"

namespace DL 
  {
  /** Functor for 1 Param
  *
  */
  template < class ReturnType , 
       class Param1     
     >
  class Functor1 : public DelegateBase 
  {
  ReturnType (*m_function)(Param1);
  Param1 m_val1;
  Functor1(){}
  public:
  Functor1(ReturnType (*function)(Param1),
    Param1 val1 = Param1()):
    m_function(function),m_val1(val1)
    {}
  virtual ~Functor1(){}
  void operator()()
  {
    (*m_function)(m_val1);
  }
  ReturnType operator()(Param1 val1)
  {
   return (*m_function)(val1);
  }
  void Invoke()
  {
    (*m_function)(m_val1);
  }
  ReturnType Invoke(Param1 val1)
  {
   return (*m_function)(val1);
  }
  };
  
  //######################################################################################################
  template < class ReturnType , class Param1  >
  DelegateObj create_delegate( ReturnType(*Meth)(Param1), Param1 & param1 )
  {
    return DelegateObj(new Functor1<ReturnType,Param1>(Meth,param1));
  }
} // namespace DL
#endif // GUARD_DELGATES_FUNCTOR1_HPP_INCLUDED
