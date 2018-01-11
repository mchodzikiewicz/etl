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

#include "multi_array.h"

#include <algorithm>
#include <iterator>

#include "integral_limits.h"

namespace
{
  typedef etl::multi_array<int, 2> Data1;
  typedef etl::multi_array<int, 2, 3> Data2;
  typedef etl::multi_array<int, 2, 3, 4> Data3;
  typedef etl::multi_array<int, 2, 3, 4, 5> Data4;
  
  SUITE(test_array)
  {
    //*************************************************************************
    TEST(test_constructor)
    {
      Data4 data;

      CHECK_EQUAL(2, data.size());
      CHECK_EQUAL(4, data.dimensions());

      CHECK_EQUAL(2, data.SIZE0);
      CHECK_EQUAL(3, data.SIZE1);
      CHECK_EQUAL(4, data.SIZE2);
      CHECK_EQUAL(5, data.SIZE3);
      CHECK_EQUAL(4, data.DIMENSIONS);

      CHECK_EQUAL(2, data.size(0));
      CHECK_EQUAL(4, data.dimensions(0));

      CHECK_EQUAL(3, data.size(1));
      CHECK_EQUAL(3, data.dimensions(1));

      CHECK_EQUAL(4, data.size(2));
      CHECK_EQUAL(2, data.dimensions(2));

      CHECK_EQUAL(5, data.size(3));
      CHECK_EQUAL(1, data.dimensions(3));
    }

    //*************************************************************************
    TEST(test_multi_array_view)
    {
      Data1 data1;
      Data2 data2;
      Data3 data3;
      Data4 data4;

      etl::multi_array_view<Data1::value_type> mav1(data1);
      etl::multi_array_view<Data2::value_type> mav2(data2);
      etl::multi_array_view<Data3::value_type> mav3(data3);
      etl::multi_array_view<Data4::value_type> mav4(data4);

      CHECK_EQUAL(1, mav1.dimensions());
      CHECK_EQUAL(2, mav2.dimensions());
      CHECK_EQUAL(3, mav3.dimensions());
      CHECK_EQUAL(4, mav4.dimensions());
    }
         
    //*************************************************************************
    TEST(test_loop)
    {
      Data4 data4;


    }

    //*************************************************************************
    TEST(test_at_const)
    {
    }

    //*************************************************************************
    TEST(test_index_operator)
    {
    }

    //*************************************************************************
    TEST(test_index_operator_const)
    {
    }

    //*************************************************************************
    TEST(test_front)
    {
    }

    //*************************************************************************
    TEST(test_front_const)
    {
    }

    //*************************************************************************
    TEST(test_back)
    {
    }

    //*************************************************************************
    TEST(test_back_const)
    {

    }

    //*************************************************************************
    TEST(test_data)
    {

    }

    //*************************************************************************
    TEST(test_data_const)
    {

    }

    //*************************************************************************
    TEST(test_begin)
    {

    }

    //*************************************************************************
    TEST(test_end)
    {

    }

    //*************************************************************************
    TEST(test_cbegin)
    {

    }

    //*************************************************************************
    TEST(test_cend)
    {

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
