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
#ifndef GUARD_ALGORITHM_EXT_HPP_INCLUDED
#define GUARD_ALGORITHM_EXT_HPP_INCLUDED 1


#include <algorithm>

namespace stdext
{
  template < typename ContainerType , typename Functor>
    void foreach( ContainerType & cont , Functor func )
    {
      std::for_each(cont.begin(),cont.end(),func);
    }
 
  template < typename ContainerType , typename Functor>
    void foreach_reverse( ContainerType & cont , Functor func )
    {
      std::for_each(cont.rbegin(),cont.rend(),func);
    }
  
} // stdext  
  
#endif // GUARD_ALGORITHM_EXT_HPP_INCLUDED
