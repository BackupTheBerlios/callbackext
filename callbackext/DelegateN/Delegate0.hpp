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
#ifndef GUARD_DELGATES_DELEGATE0_HPP_INCLUDED
#define GUARD_DELGATES_DELEGATE0_HPP_INCLUDED 1

#include "DelegateBase.hpp"

namespace DL 
  {
  template <class ReturnType, class ClassType>
    class Delegate0 : public DelegateBase 
    {
    //Param1 m_val1;
    ClassType* m_class_obj;
    ReturnType (ClassType::*m_method)();
    Delegate0(){}
    public:
    Delegate0(ClassType* class_obj,
      ReturnType (ClassType::*method)()):
      m_class_obj(class_obj), m_method(method)
      {}
    virtual ~Delegate0(){}
    void operator()(){ return this->Invoke();}
    void Invoke()
    {
      (*m_class_obj.*m_method)();
    }
    };
//######################################################################################################
  template < class ReturnType , class ClassType>
    DelegateObj create_delegate( ClassType & obj , ReturnType(ClassType::*Meth)())
    {
      return DelegateObj(new Delegate0<ReturnType,ClassType>(&obj,Meth));
    }

  template < class ReturnType , class ClassType>
    DelegateObj create_delegate( ClassType * obj , ReturnType(ClassType::*Meth)())
    {
      return DelegateObj(new Delegate0<ReturnType,ClassType>(obj,Meth));
    }
} // namespace DL
#endif // GUARD_DELGATES_DELEGATE0_HPP_INCLUDED
