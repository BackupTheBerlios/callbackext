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
#include <string>
#include <iostream>
#include "../DelegateN/Delegate1.hpp"
#include "../Container/DelegateList.hpp"
using namespace DL;
//##########################################################################
class Test
{
 public:
   void Print(std::string Bla){ std::cout << " TestClass : " << Bla << std::endl; }
};
//##########################################################################
class Blah
{
  public:
  int TestAFunc( int value ) { std::cout << " BlahClass : " << value << std::endl; return value;} 
};
//##########################################################################
 
int main()
{
  Test tst;
  Test *tst_obj = new Test;
 
  Blah blh;
  Blah *blh_obj = new Blah; 
 
  std::string test_value("Hello World!");
  int blah_value = 87654321;
 
  DelegateList del_list;
 
  del_list.add(create_delegate(tst,&Test::Print,test_value));
  del_list.add(create_delegate(blh,&Blah::TestAFunc,blah_value));
 
  blah_value = 12345678;
  test_value = "Foobar!!";
  
  del_list.add(create_delegate(tst_obj,&Test::Print,test_value));
  del_list.add(create_delegate(blh_obj,&Blah::TestAFunc,blah_value));
  
  // Calling all data 
  std::cout << "Calling as Functor" << std::endl;
  del_list();
  std::cout << std::endl << "Calling via .call()" << std::endl;
  del_list.call();
  std::cout << std::endl;

  
  
    
  delete tst_obj;
  delete blh_obj;
}

