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
#ifndef GUARD_DELGATES_FUNCTOR0_HPP_INCLUDED
#define GUARD_DELGATES_FUNCTOR0_HPP_INCLUDED 1

#include "../DelegateN/DelegateBase.hpp"

namespace DL 
  {
  /** Functor without Params
  *
  */
  
  class Functor0 : public DelegateBase 
  {
  void (*m_function)(void);
  Functor0(){}
  public:
  Functor0(void (*function)(void)):
    m_function(function)
    {}
  virtual ~Functor0(){}
  void operator()()
  {
    this->Invoke();
  }
  void Invoke()
  {
   (*m_function)();
  }
  };
  
  //######################################################################################################
  
  DelegateObj create_delegate(void(*Meth)(void))
  {
    return DelegateObj(new Functor0(Meth));
  }
} // namespace DL
#endif // GUARD_DELGATES_FUNCTOR0_HPP_INCLUDED
