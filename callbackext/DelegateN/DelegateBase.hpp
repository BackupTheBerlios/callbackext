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
#ifndef GUARD_DELGATES_DELEGATE_BASE_HPP_INCLUDED
#define GUARD_DELGATES_DELEGATE_BASE_HPP_INCLUDED 1

#include <memory>

namespace DL 
  {
  class DelegateBase 
  { 
  public:  
        DelegateBase(){}
  virtual ~DelegateBase(){}
  virtual void operator()() = 0;
  virtual void Invoke() = 0;
  };
  
  typedef std::auto_ptr<DelegateBase> DelegateObj;
} //namespace DL

#endif // GUARD_DELGATES_DELEGATE0_HPP_INCLUDED
