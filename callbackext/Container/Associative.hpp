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
#ifndef GUARD_DELEGATES_ASSOCIATIVE_HPP_INCLUDED
#define GUARD_DELEGATES_ASSOCIATIVE_HPP_INCLUDED 1

#include "../DelegateN/DelegateBase.hpp"
#include "AlgorithmExt.hpp"
#include <functional>
#include <map>

namespace DL
{
  template < class MapType >
    struct Deleter 
    {
      void operator()(typename MapType::value_type iter)
      { 
        delete (iter.second); 
      }
    };
  template< class KeyType , class Compare = std::less<KeyType> >
    class Associative
    {
    public:
      typedef Compare     compare_type;
      typedef KeyType     key_type;
      typedef typename std::map< key_type, DelegateBase* , compare_type > map_type;
    public:
    Associative(){}
    virtual ~Associative()
    {
      stdext::foreach(m_data,Deleter<map_type>());
    }
    void insert( key_type key , DelegateObj Callback )
    {
      m_data.insert(map_type::value_type(key,Callback.release()));
    }
    void emit(key_type key)
    {
      typename map_type::iterator iter;
      if((iter = m_data.find(key)) != m_data.end())
          iter->second->Invoke();
    }
  private:
  std::map< key_type , DelegateBase* , compare_type > m_data;
  };
} // namespace DL
#endif // GUARD_DELEGATES_ASSOCIATIVE_HPP_INCLUDED
