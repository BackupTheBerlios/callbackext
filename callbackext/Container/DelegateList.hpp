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
#ifndef GUARD_DELEGATE_LIST_HPP_INCLUDED
#define GUARD_DELEGATE_LIST_HPP_INCLUDED 1

#include <deque>
#include "AlgorithmExt.hpp"
#include "../DelegateN/DelegateBase.hpp"

/** DelegateList is a Method Pointer Container
  */ 
namespace DL
{
  class DelegateList
  {
    public:
    virtual ~DelegateList()
    {
      stdext::foreach( m_obj_list , std::ptr_fun(operator delete) );
    }
    void add(DelegateObj  m_obj)
    { 
       m_obj_list.push_back(m_obj.release()); 
    }
    void reverse_call()
    {
      stdext::foreach_reverse(m_obj_list, std::mem_fun(&DelegateBase::Invoke));
    }
    void call()
    {
       stdext::foreach(m_obj_list ,std::mem_fun(&DelegateBase::Invoke));  
    }
    /** DelegateList::operator()() is used to emits all stored Delegates<>
     */
    void operator()()
    {  
      stdext::foreach( m_obj_list , std::mem_fun(&DelegateBase::Invoke));
    }  
    private:
    std::deque<DelegateBase*> m_obj_list;
  };
} // namespace DL

#endif // GUARD_DELEGATE_LIST_HPP_INCLUDED
