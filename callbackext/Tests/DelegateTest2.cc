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
  
  #include "../Container/DelegateList.hpp"
  #include "../DelegateN/DelegateN.hpp"
  #include "../FunctorN/FunctorN.hpp"
  
  //######################################################################################################
  using namespace DL;

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
  DelegateList list;
  Foobar test;
  int var1 = 1, var2 = 2, var3 = 3, var4 = 4 , var5 = 5 , var6 = 6, var7 = 7, var8 = 8, var9 =9, var10 = 10;
  list.add(create_delegate(  test ,&Foobar::test0));
  list.add(create_delegate( &test ,&Foobar::test0));
  list.add(create_delegate(  test ,&Foobar::test1,var1));
  list.add(create_delegate( &test ,&Foobar::test1,var1));
  list.add(create_delegate(  test ,&Foobar::test2,var1,var2));
  list.add(create_delegate( &test ,&Foobar::test2,var1,var2));
  list.add(create_delegate(  test ,&Foobar::test3,var1,var2,var3));
  list.add(create_delegate( &test ,&Foobar::test3,var1,var2,var3));
  list.add(create_delegate(  test ,&Foobar::test4,var1,var2,var3,var4));
  list.add(create_delegate( &test ,&Foobar::test4,var1,var2,var3,var4));
  list.add(create_delegate(  test ,&Foobar::test5,var1,var2,var3,var4,var5));
  list.add(create_delegate( &test ,&Foobar::test5,var1,var2,var3,var4,var5));
  list.add(create_delegate(  test ,&Foobar::test6,var1,var2,var3,var4,var5,var6));
  list.add(create_delegate( &test ,&Foobar::test6,var1,var2,var3,var4,var5,var6));
  list.add(create_delegate(  test ,&Foobar::test7,var1,var2,var3,var4,var5,var6,var7));
  list.add(create_delegate( &test ,&Foobar::test7,var1,var2,var3,var4,var5,var6,var7));
  list.add(create_delegate(  test ,&Foobar::test8,var1,var2,var3,var4,var5,var6,var7,var8));
  list.add(create_delegate( &test ,&Foobar::test8,var1,var2,var3,var4,var5,var6,var7,var8));
  list.add(create_delegate(  test ,&Foobar::test9,var1,var2,var3,var4,var5,var6,var7,var8,var9));
  list.add(create_delegate( &test ,&Foobar::test9,var1,var2,var3,var4,var5,var6,var7,var8,var9));
  list.add(create_delegate(  test ,&Foobar::test10,var1,var2,var3,var4,var5,var6,var7,var8,var9,var10));
  list.add(create_delegate( &test ,&Foobar::test10,var1,var2,var3,var4,var5,var6,var7,var8,var9,var10));
  
  list.add(create_delegate( &test0));
  list.add(create_delegate( &test1,var1));
  list.add(create_delegate( &test2,var1,var2));
  list.add(create_delegate( &test3,var1,var2,var3));
  list.add(create_delegate( &test4,var1,var2,var3,var4));
  list.add(create_delegate( &test5,var1,var2,var3,var4,var5));
  list.add(create_delegate( &test6,var1,var2,var3,var4,var5,var6));
  list.add(create_delegate( &test7,var1,var2,var3,var4,var5,var6,var7));
  list.add(create_delegate( &test8,var1,var2,var3,var4,var5,var6,var7,var8));
  list.add(create_delegate( &test9,var1,var2,var3,var4,var5,var6,var7,var8,var9));
  list.add(create_delegate( &test10,var1,var2,var3,var4,var5,var6,var7,var8,var9,var10));
  
  list();
  
  }

