/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2017 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#include "UnitTest++.h"


#include "array_wrapper.h"

#include <algorithm>
#include <iterator>

#include "integral_limits.h"
#include "container.h"

namespace
{
  int data5[]  = { 0, 1, 2, 3, 4 };
  extern const int cdata5[] = { 5, 6, 7, 8, 9 };
  int data10[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  typedef etl::array_wrapper<int, ETL_ARRAY_SIZE(data5), data5>  Data5;
  typedef etl::array_wrapper<const int, ETL_ARRAY_SIZE(cdata5), cdata5>  CData5;
  typedef etl::array_wrapper<int, ETL_ARRAY_SIZE(data10), data10> Data10;
  typedef etl::array_temp Temp;

  int temp;

  void Save(int i)
  {
    temp = i;
  }

  void Restore(int& i)
  {
    i = temp;
  }

  SUITE(test_array_wrapper)
  {
    //*************************************************************************
    TEST(test_constructor)
    {
      Data5 aw5;

      CHECK_ARRAY_EQUAL(data5, aw5.data(), aw5.size());
    }

    //*************************************************************************
    TEST(test_at)
    {
      Data5 aw5;

      CHECK_EQUAL(data5[2], aw5.at(2));

      Save(data5[2]);
      aw5.at(2) = 100;
      CHECK_EQUAL(100, data5[2]);
      CHECK_EQUAL(100, aw5.at(2));
      Restore(data5[2]);
    }

    //*************************************************************************
    TEST(test_at_const)
    {
      const Data5 caw5a; // array_wrapper is const.
      CData5 caw5b;      // array wrapped by array_wrapper is const.

      CHECK_EQUAL(data5[2], caw5a.at(2));
      CHECK_EQUAL(data5[2], caw5b.at(2));

      // These lines should fail to compile.
      // caw5a.at(2) = 100;
      // caw5b.at(100) = 100;
    }

    //*************************************************************************
    TEST(test_index_operator)
    {
      Data5 aw5;

      CHECK_EQUAL(data5[2], aw5[2]);

      Save(data5[2]);
      aw5[2] = 100;
      CHECK_EQUAL(100, data5[2]);
      CHECK_EQUAL(100, aw5[2]);
      Restore(data5[2]);
    }

    //*************************************************************************
    TEST(test_index_operator_const)
    {
      const Data5 caw5a; // array_wrapper is const.
      CData5 caw5b;      // array wrapped by array_wrapper is const.

      CHECK_EQUAL(data5[2], caw5a[2]);
      CHECK_EQUAL(data5[2], caw5b[2]);

      // These lines should fail to compile.
      // caw5a[2] = 100;
      // caw5b[100] = 100;
    }

    //*************************************************************************
    TEST(test_front)
    {
      Data5 aw5;
      CHECK_EQUAL(0, Data5::FRONT);
      CHECK_EQUAL(data5[Data5::FRONT], aw5.front());
    }

    //*************************************************************************
    TEST(test_front_const)
    {
      const Data5 caw5 = Data5();
      CHECK_EQUAL(data5[Data5::FRONT], caw5.front());

      //CData5 caw5b;
      //CHECK_EQUAL(0, Data5::FRONT);
      //CHECK_EQUAL(data5[Data5::FRONT], caw5b.front());
    }

    //*************************************************************************
    TEST(test_back)
    {
      Data5 aw5;
      CHECK_EQUAL(Data5::SIZE - 1, Data5::BACK);
      CHECK_EQUAL(data5[Data5::BACK], aw5.back());
    }

    //*************************************************************************
    TEST(test_back_const)
    {
      const Data5 caw5 = Data5();
      CHECK_EQUAL(data5[Data5::BACK], caw5.back());
    }

    //*************************************************************************
    TEST(test_data)
    {
      Data5 aw5;

      CHECK_EQUAL(data5, aw5.data());
    }

    //*************************************************************************
    TEST(test_data_const)
    {
      const Data5 aw5;

      CHECK_EQUAL(data5, aw5.data());
    }

    //*************************************************************************
    TEST(test_begin)
    {
      Data5 aw5;

      CHECK_EQUAL(0, Data5::BEGIN);
      CHECK_EQUAL(data5, aw5.begin());
    }

    //*************************************************************************
    TEST(test_begin_const)
    {
      const Data5 aw5;

      CHECK_EQUAL(0, Data5::BEGIN);
      CHECK_EQUAL(data5, aw5.begin());
      CHECK_EQUAL(data5, aw5.cbegin());
    }

    //*************************************************************************
    TEST(test_end)
    {
      Data5 aw5;

      CHECK_EQUAL(5, Data5::END);
      CHECK_EQUAL(&data5[Data5::END], aw5.end());
    }

    //*************************************************************************
    TEST(test_end_const)
    {
      const Data5 aw5;

      CHECK_EQUAL(5, Data5::END);
      CHECK_EQUAL(&data5[Data5::END], aw5.end());
      CHECK_EQUAL(&data5[Data5::END], aw5.cend());
    }

    //*************************************************************************
    TEST(test_rbegin)
    {

    }

    //*************************************************************************
    TEST(test_rend)
    {

    }

    //*************************************************************************
    TEST(test_crbegin)
    {

    }

    //*************************************************************************
    TEST(test_crend)
    {

    }

    //*************************************************************************
    TEST(test_iterator)
    {

    }

    //*************************************************************************
    TEST(test_const_iterator)
    {

    }

    //*************************************************************************
    TEST(test_reverse_iterator)
    {

    }

    //*************************************************************************
    TEST(test_const_reverse_iterator)
    {

    }

    //*************************************************************************
    TEST(test_empty)
    {

    }

    //*************************************************************************
    TEST(test_size)
    {

    }

    //*************************************************************************
    TEST(test_max_size)
    {

    }


    //*************************************************************************
    TEST(test_fill)
    {

    }

    //*************************************************************************
    TEST(test_swap)
    {

    }

    //*************************************************************************
    TEST(test_get)
    {

    }

    //*************************************************************************
    TEST(test_assign)
    {

    }

    //*************************************************************************
    TEST(test_insert_value)
    {

    }

    //*************************************************************************
    TEST(test_insert_range)
    {

    }

    //*************************************************************************
    TEST(test_erase_single)
    {

    }

    //*************************************************************************
    TEST(test_erase_range)
    {

    }

    //*************************************************************************
    TEST(test_equal)
    {

    }

    //*************************************************************************
    TEST(test_not_equal)
    {

    }

    //*************************************************************************
    TEST(test_less_than)
    {

    }

    //*************************************************************************
    TEST(test_less_than_equal)
    {

    }

    //*************************************************************************
    TEST(test_greater_than)
    {

    }

    //*************************************************************************
    TEST(test_greater_than_equal)
    {

    }
  };
}
