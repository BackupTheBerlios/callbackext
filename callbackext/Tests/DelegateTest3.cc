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
#include <iostream>
#include "../DelegateN/DelegateN.hpp"
#include "../Container/Associative.hpp"
using namespace DL;

struct Foobar
{
void test0()
{ std::cout << " callback 0 " << std::endl;}
void test1(int i1)
{ std::cout << " callback 1 " << i1 << std::endl;}
void test2(int i1, int i2)
{ std::cout << " callback 2 " << i1 << " " <<i2 << std::endl;}
void test3(int i1, int i2, int i3)
{ std::cout << " callback 3 " << i1 << " " <<i2 << " " <<i3 << std::endl;}
void test4(int i1, int i2, int i3, int i4)
{ std::cout << " callback 4 " << i1 << " " <<i2 << " " <<i3 << " " <<i4 << std::endl;}
void test5(int i1, int i2, int i3, int i4,int i5)
{ std::cout << " callback 5 " << i1 << " " <<i2 << " " <<i3 << " " <<i4 << " " <<i5 << std::endl;}
void test6(int i1, int i2, int i3, int i4,int i5, int i6)
{ std::cout << " callback 6 " << i1 << " " <<i2 << " " <<i3 << " " <<i4 << " " <<i5 << " " <<i6<< std::endl;}
void test7(int i1, int i2, int i3, int i4,int i5, int i6, int i7)
{ std::cout << " callback 7 " << i1 << " " <<i2 << " " <<i3 << " " <<i4 << " " <<i5 << " " <<i6 << " " <<i7 << std::endl;}
void test8(int i1, int i2, int i3, int i4,int i5, int i6, int i7, int i8)
{ std::cout << " callback 8 " << i1 << " " <<i2 << " " <<i3 << " " <<i4 << " " <<i5 << " " <<i6 << " " <<i7 << " " <<i8  << std::endl;}
void test9(int i1, int i2, int i3, int i4,int i5, int i6, int i7, int i8, int i9)
{ std::cout << " callback 9 " << i1 << " " <<i2 << " " <<i3 << " " <<i4 << " " <<i5 << " " <<i6 << " " <<i7 << " " <<i8 << " " <<i9 << std::endl;}
void test10(int i1, int i2, int i3, int i4,int i5, int i6, int i7, int i8, int i9,int i10)
{ std::cout << " callback 10 " << i1 << " " <<i2 << " " <<i3 << " " <<i4 << " " <<i5 << " " <<i6 << " " <<i7 << " " <<i8 << " " <<i9 << " " <<i10 << std::endl;}
};

int main()
{
  int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5, val6 = 6, val7 = 7, val8 = 8, val9 = 9, val10 = 10;
  Foobar foobar_obj;  
  
  Associative<int> assoc;
  
  assoc.insert(0,create_delegate(&foobar_obj, &Foobar::test8,val1,val2,val3,val4,val5,val6,val7,val8));
  assoc.insert(2,create_delegate(&foobar_obj, &Foobar::test2,val1,val2));
  assoc.insert(4,create_delegate(&foobar_obj, &Foobar::test4,val1,val2,val3,val4));
    
  assoc.emit(2);
  assoc.emit(4);
  assoc.emit(0);
  std::cout << "All Emited" << std::endl;

}
