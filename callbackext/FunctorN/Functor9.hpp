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
#ifndef GUARD_DELGATES_FUNCTOR9_HPP_INCLUDED
#define GUARD_DELGATES_FUNCTOR9_HPP_INCLUDED 1

#include "../DelegateN/DelegateBase.hpp"

namespace DL 
  {
  /** Functor for 9 Param
  *
  */
  template < class ReturnType , 
    class Param1     ,
    class Param2     ,
    class Param3     ,
    class Param4     ,
    class Param5     ,
    class Param6     ,
    class Param7     ,
    class Param8     ,
    class Param9     
    >
  class Functor9 : public DelegateBase 
  {
  ReturnType (*m_function)(Param1,Param2,Param3,Param4,Param5,Param6,Param7,Param8,Param9);
  Param1 m_val1;
  Param2 m_val2;
  Param3 m_val3;
  Param4 m_val4;
  Param5 m_val5;
  Param6 m_val6;
  Param7 m_val7;
  Param8 m_val8;
  Param9 m_val9;
  Functor9(){}
  public:
  Functor9(ReturnType (*function)(Param1,Param2,Param3,Param4,Param5,Param6,Param7,Param8,Param9),
    Param1 val1 = Param1(),
    Param2 val2 = Param2(),
    Param3 val3 = Param3(),
    Param4 val4 = Param4(),
    Param5 val5 = Param5(),
    Param6 val6 = Param6(),
    Param7 val7 = Param7(),
    Param8 val8 = Param8(),
    Param9 val9 = Param9()):
    m_function(function),
    m_val1(val1),m_val2(val2),m_val3(val3),
    m_val4(val4),m_val5(val5),m_val6(val6),
    m_val7(val7),m_val8(val8),m_val9(val9)
    {}
  virtual ~Functor9(){}
  ReturnType operator()(Param1 val1,Param2 val2,Param3 val3,Param4 val4,Param5 val5,Param6 val6,Param7 val7,Param8 val8,Param9 val9)
  {
    return this->Invoke(val1,val2,val3,val4,val5,val6,val7,val8,val9);
  }
  void operator()()
  {
    this->Invoke();
  }
  void Invoke()
  {
    (*m_function)(m_val1,m_val2,m_val3,m_val4,m_val5,m_val6,m_val7,m_val8,m_val9);
  }
  ReturnType Invoke(Param1 val1,Param2 val2,Param3 val3,Param4 val4,Param5 val5,Param6 val6,Param7 val7,Param8 val8,Param9 val9)
  {
   return (*m_function)(val1,val2,val3,val4,val5,val6,val7,val8,val9);
  }
  };
  
  //######################################################################################################
  template < class ReturnType , class Param1    , 
             class Param2     , class Param3    , class Param4  , 
       class Param5     , class Param6    , class Param7  , 
       class Param8     , class Param9    
     >
  DelegateObj create_delegate( ReturnType(*Meth)(Param1,Param2,Param3,Param4,Param5,Param6,Param7,Param8,Param9), 
                Param1 & param1 , Param2 & param2 , Param3 & param3 ,
                Param4 & param4 , Param5 & param5 , Param6 & param6 , 
                Param7 & param7 , Param8 & param8 , Param9 & param9 )
  {
  return DelegateObj(new Functor9<ReturnType,Param1,Param2,Param3,Param4,Param5,Param6,Param7,Param8,Param9>
    (Meth,param1,param2,param3,param4,param5,param6,param7,param8,param9));
  }
} // namespace DL
#endif // GUARD_DELGATES_FUNCTOR9_HPP_INCLUDED
