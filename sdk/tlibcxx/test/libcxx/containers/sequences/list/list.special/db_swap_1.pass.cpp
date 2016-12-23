//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <list>

// template <class T, class Alloc>
//   void swap(list<T,Alloc>& x, list<T,Alloc>& y);

#define _LIBCPP_DEBUG 1
#define _LIBCPP_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <list>
#include <cstdlib>
#include <cassert>

int main()
{
    int a1[] = {1, 3, 7, 9, 10};
    int a2[] = {0, 2, 4, 5, 6, 8, 11};
    std::list<int> c1(a1, a1+sizeof(a1)/sizeof(a1[0]));
    std::list<int> c2(a2, a2+sizeof(a2)/sizeof(a2[0]));
    std::list<int>::iterator i1 = c1.begin();
    std::list<int>::iterator i2 = c2.begin();
    swap(c1, c2);
    c1.erase(i2);
    c2.erase(i1);
    std::list<int>::iterator j = i1;
    c1.erase(i1); // called with iterator not refering to list.
    assert(false);
}