/*
 * Copyright 2005 Vinzenz Feenstra - evilissimo@users.sourceforge.net
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef GUARD_DELGATES_DELEGATE1_HPP_INCLUDED
#define GUARD_DELGATES_DELEGATE1_HPP_INCLUDED 1

#include "DelegateBase.hpp"

namespace DL 
{
/** \brief Delegate for 1 Param
  */
  template 
    < 
      class ReturnType , 
      class ClassType  , 
      class Param1     
    >
    class Delegate1 : public DelegateBase 
    {
    ClassType* m_class_obj;
    ReturnType (ClassType::*m_method)(Param1);
    Param1 m_val1;
    Delegate1(){}
    public:
    Delegate1(ClassType* class_obj,
      ReturnType (ClassType::*method)(Param1),
      Param1 val1 = Param1()):
      m_class_obj(class_obj), m_method(method),m_val1(val1)
      {}
    virtual ~Delegate1(){}
    ReturnType operator()(Param1 val1)
    { 
      return this->Invoke(val1); 
    }
    void operator()()
    { 
      this->Invoke(); 
    }
    void Invoke()
    {
      (*m_class_obj.*m_method)(m_val1);
    }
    ReturnType Invoke(Param1 val1)
    {
      return (*m_class_obj.*m_method)(val1);
    }    
    };
//######################################################################################################
    template < class ReturnType , class ClassType , class Param1 >
        DelegateObj create_delegate( ClassType & obj , ReturnType(ClassType::*Meth)(Param1), Param1 & param1)
        {
            return DelegateObj(new Delegate1<ReturnType,ClassType,Param1>(&obj,Meth,param1));
        }

    template < class ReturnType , class ClassType , class Param1 >
        DelegateObj create_delegate( ClassType * obj , ReturnType(ClassType::*Meth)(Param1), Param1 & param1)
        {   
            return DelegateObj(new Delegate1<ReturnType,ClassType,Param1>(obj,Meth,param1));
        }
} // namespace DL
#endif // GUARD_DELGATES_DELEGATE1_HPP_INCLUDED
