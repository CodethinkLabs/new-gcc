// { dg-do run { target c++11 } }
// { dg-options "-D__STDCPP_WANT_MATH_SPEC_FUNCS__" }
//
// Copyright (C) 2016-2019 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

//  laguerre
//  Compare against values generated by the GNU Scientific Library.
//  The GSL can be found on the web: http://www.gnu.org/software/gsl/
#include <limits>
#include <cmath>
#if defined(__TEST_DEBUG)
#  include <iostream>
#  define VERIFY(A) \
  if (!(A)) \
    { \
      std::cout << "line " << __LINE__ \
	<< "  max_abs_frac = " << max_abs_frac \
	<< std::endl; \
    }
#else
#  include <testsuite_hooks.h>
#endif
#include <specfun_testcase.h>

// Test data for n=0.
// max(|f - f_GSL|): 0.0000000000000000 at index 0
// max(|f - f_GSL| / |f_GSL|): 0.0000000000000000
// mean(f - f_GSL): 0.0000000000000000
// variance(f - f_GSL): 0.0000000000000000
// stddev(f - f_GSL): 0.0000000000000000
const testcase_laguerre<double>
data001[21] =
{
  { 1.0000000000000000, 0, 0.0000000000000000, 0.0 },
  { 1.0000000000000000, 0, 5.0000000000000000, 0.0 },
  { 1.0000000000000000, 0, 10.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 15.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 20.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 25.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 30.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 35.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 40.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 45.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 50.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 55.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 60.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 65.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 70.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 75.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 80.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 85.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 90.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 95.000000000000000, 0.0 },
  { 1.0000000000000000, 0, 100.00000000000000, 0.0 },
};
const double toler001 = 2.5000000000000020e-13;

// Test data for n=1.
// max(|f - f_GSL|): 0.0000000000000000 at index 0
// max(|f - f_GSL| / |f_GSL|): 0.0000000000000000
// mean(f - f_GSL): 0.0000000000000000
// variance(f - f_GSL): 0.0000000000000000
// stddev(f - f_GSL): 0.0000000000000000
const testcase_laguerre<double>
data002[21] =
{
  { 1.0000000000000000, 1, 0.0000000000000000, 0.0 },
  { -4.0000000000000000, 1, 5.0000000000000000, 0.0 },
  { -9.0000000000000000, 1, 10.000000000000000, 0.0 },
  { -14.000000000000000, 1, 15.000000000000000, 0.0 },
  { -19.000000000000000, 1, 20.000000000000000, 0.0 },
  { -24.000000000000000, 1, 25.000000000000000, 0.0 },
  { -29.000000000000000, 1, 30.000000000000000, 0.0 },
  { -34.000000000000000, 1, 35.000000000000000, 0.0 },
  { -39.000000000000000, 1, 40.000000000000000, 0.0 },
  { -44.000000000000000, 1, 45.000000000000000, 0.0 },
  { -49.000000000000000, 1, 50.000000000000000, 0.0 },
  { -54.000000000000000, 1, 55.000000000000000, 0.0 },
  { -59.000000000000000, 1, 60.000000000000000, 0.0 },
  { -64.000000000000000, 1, 65.000000000000000, 0.0 },
  { -69.000000000000000, 1, 70.000000000000000, 0.0 },
  { -74.000000000000000, 1, 75.000000000000000, 0.0 },
  { -79.000000000000000, 1, 80.000000000000000, 0.0 },
  { -84.000000000000000, 1, 85.000000000000000, 0.0 },
  { -89.000000000000000, 1, 90.000000000000000, 0.0 },
  { -94.000000000000000, 1, 95.000000000000000, 0.0 },
  { -99.000000000000000, 1, 100.00000000000000, 0.0 },
};
const double toler002 = 2.5000000000000020e-13;

// Test data for n=2.
// max(|f - f_GSL|): 0.0000000000000000 at index 0
// max(|f - f_GSL| / |f_GSL|): 0.0000000000000000
// mean(f - f_GSL): 0.0000000000000000
// variance(f - f_GSL): 0.0000000000000000
// stddev(f - f_GSL): 0.0000000000000000
const testcase_laguerre<double>
data003[21] =
{
  { 1.0000000000000000, 2, 0.0000000000000000, 0.0 },
  { 3.5000000000000000, 2, 5.0000000000000000, 0.0 },
  { 31.000000000000000, 2, 10.000000000000000, 0.0 },
  { 83.500000000000000, 2, 15.000000000000000, 0.0 },
  { 161.00000000000000, 2, 20.000000000000000, 0.0 },
  { 263.50000000000000, 2, 25.000000000000000, 0.0 },
  { 391.00000000000000, 2, 30.000000000000000, 0.0 },
  { 543.50000000000000, 2, 35.000000000000000, 0.0 },
  { 721.00000000000000, 2, 40.000000000000000, 0.0 },
  { 923.50000000000000, 2, 45.000000000000000, 0.0 },
  { 1151.0000000000000, 2, 50.000000000000000, 0.0 },
  { 1403.5000000000000, 2, 55.000000000000000, 0.0 },
  { 1681.0000000000000, 2, 60.000000000000000, 0.0 },
  { 1983.5000000000000, 2, 65.000000000000000, 0.0 },
  { 2311.0000000000000, 2, 70.000000000000000, 0.0 },
  { 2663.5000000000000, 2, 75.000000000000000, 0.0 },
  { 3041.0000000000000, 2, 80.000000000000000, 0.0 },
  { 3443.5000000000000, 2, 85.000000000000000, 0.0 },
  { 3871.0000000000000, 2, 90.000000000000000, 0.0 },
  { 4323.5000000000000, 2, 95.000000000000000, 0.0 },
  { 4801.0000000000000, 2, 100.00000000000000, 0.0 },
};
const double toler003 = 2.5000000000000020e-13;

// Test data for n=5.
// max(|f - f_GSL|): 7.4505805969238281e-09 at index 20
// max(|f - f_GSL| / |f_GSL|): 1.9501553136894460e-16
// mean(f - f_GSL): -9.1645146498075565e-11
// variance(f - f_GSL): 2.8430813755854757e-18
// stddev(f - f_GSL): 1.6861439367934980e-09
const testcase_laguerre<double>
data004[21] =
{
  { 1.0000000000000000, 5, 0.0000000000000000, 0.0 },
  { -3.1666666666666665, 5, 5.0000000000000000, 0.0 },
  { 34.333333333333329, 5, 10.000000000000000, 0.0 },
  { -355.25000000000000, 5, 15.000000000000000, 0.0 },
  { -4765.6666666666670, 5, 20.000000000000000, 0.0 },
  { -23040.666666666664, 5, 25.000000000000000, 0.0 },
  { -74399.000000000000, 5, 30.000000000000000, 0.0 },
  { -190559.41666666663, 5, 35.000000000000000, 0.0 },
  { -418865.66666666663, 5, 40.000000000000000, 0.0 },
  { -825411.50000000000, 5, 45.000000000000000, 0.0 },
  { -1498165.6666666665, 5, 50.000000000000000, 0.0 },
  { -2550096.9166666670, 5, 55.000000000000000, 0.0 },
  { -4122299.0000000000, 5, 60.000000000000000, 0.0 },
  { -6387115.6666666670, 5, 65.000000000000000, 0.0 },
  { -9551265.6666666679, 5, 70.000000000000000, 0.0 },
  { -13858967.750000000, 5, 75.000000000000000, 0.0 },
  { -19595065.666666664, 5, 80.000000000000000, 0.0 },
  { -27088153.166666668, 5, 85.000000000000000, 0.0 },
  { -36713699.000000000, 5, 90.000000000000000, 0.0 },
  { -48897171.916666657, 5, 95.000000000000000, 0.0 },
  { -64117165.666666664, 5, 100.00000000000000, 0.0 },
};
const double toler004 = 2.5000000000000020e-13;

// Test data for n=10.
// max(|f - f_GSL|): 0.0029296875000000000 at index 19
// max(|f - f_GSL| / |f_GSL|): 6.1315986390500118e-15
// mean(f - f_GSL): -0.00011841882388131082
// variance(f - f_GSL): 7.3638903636883773e-10
// stddev(f - f_GSL): 2.7136489020668051e-05
const testcase_laguerre<double>
data005[21] =
{
  { 1.0000000000000000, 10, 0.0000000000000000, 0.0 },
  { 1.7562761794532631, 10, 5.0000000000000000, 0.0 },
  { 27.984126984126977, 10, 10.000000000000000, 0.0 },
  { -237.51841517857147, 10, 15.000000000000000, 0.0 },
  { 3227.8077601410932, 10, 20.000000000000000, 0.0 },
  { -45786.199797453693, 10, 25.000000000000000, 0.0 },
  { 15129.571428571455, 10, 30.000000000000000, 0.0 },
  { 7764800.8179494590, 10, 35.000000000000000, 0.0 },
  { 79724066.608465582, 10, 40.000000000000000, 0.0 },
  { 469865425.65122765, 10, 45.000000000000000, 0.0 },
  { 2037190065.3738980, 10, 50.000000000000000, 0.0 },
  { 7187828002.9825764, 10, 55.000000000000000, 0.0 },
  { 21804200401.000000, 10, 60.000000000000000, 0.0 },
  { 58854343015.616211, 10, 65.000000000000000, 0.0 },
  { 144688291819.51855, 10, 70.000000000000000, 0.0 },
  { 329425241736.70038, 10, 75.000000000000000, 0.0 },
  { 703324772760.08276, 10, 80.000000000000000, 0.0 },
  { 1421627560118.6157, 10, 85.000000000000000, 0.0 },
  { 2741055412243.8569, 10, 90.000000000000000, 0.0 },
  { 5071986977681.8652, 10, 95.000000000000000, 0.0 },
  { 9051283795429.5723, 10, 100.00000000000000, 0.0 },
};
const double toler005 = 5.0000000000000039e-13;

// Test data for n=20.
// max(|f - f_GSL|): 2048.0000000000000 at index 19
// max(|f - f_GSL| / |f_GSL|): 7.1189246999774008e-15
// mean(f - f_GSL): -96.983562564903480
// variance(f - f_GSL): 8.4641159685539344e+21
// stddev(f - f_GSL): 92000630261.721222
const testcase_laguerre<double>
data006[21] =
{
  { 1.0000000000000000, 20, 0.0000000000000000, 0.0 },
  { 2.0202257444769134, 20, 5.0000000000000000, 0.0 },
  { -11.961333867812119, 20, 10.000000000000000, 0.0 },
  { -50.151037960139455, 20, 15.000000000000000, 0.0 },
  { 2829.4728613531743, 20, 20.000000000000000, 0.0 },
  { -11583.947899113540, 20, 25.000000000000000, 0.0 },
  { -18439.424502520938, 20, 30.000000000000000, 0.0 },
  { -38838.223606979285, 20, 35.000000000000000, 0.0 },
  { 24799805.877530713, 20, 40.000000000000000, 0.0 },
  { -673953823.59913278, 20, 45.000000000000000, 0.0 },
  { 7551960453.7672548, 20, 50.000000000000000, 0.0 },
  { 31286508510.614746, 20, 55.000000000000000, 0.0 },
  { -1379223608444.9155, 20, 60.000000000000000, 0.0 },
  { -6692517968212.9717, 20, 65.000000000000000, 0.0 },
  { 165423821874449.94, 20, 70.000000000000000, 0.0 },
  { 3082390018008546.5, 20, 75.000000000000000, 0.0 },
  { 29500368536981676., 20, 80.000000000000000, 0.0 },
  { 2.0353526354974186e+17, 20, 85.000000000000000, 0.0 },
  { 1.1292309514432901e+18, 20, 90.000000000000000, 0.0 },
  { 5.3239262855563100e+18, 20, 95.000000000000000, 0.0 },
  { 2.2061882785931735e+19, 20, 100.00000000000000, 0.0 },
};
const double toler006 = 5.0000000000000039e-13;

// Test data for n=50.
// max(|f - f_GSL|): 196608.00000000000 at index 20
// max(|f - f_GSL| / |f_GSL|): 4.2910775919271532e-15
// mean(f - f_GSL): -8840.7163987470722
// variance(f - f_GSL): 9.4918743844066836e+19
// stddev(f - f_GSL): 9742625100.2523346
const testcase_laguerre<double>
data007[21] =
{
  { 1.0000000000000000, 50, 0.0000000000000000, 0.0 },
  { 1.4735258819430543, 50, 5.0000000000000000, 0.0 },
  { 17.534183446338233, 50, 10.000000000000000, 0.0 },
  { -195.62436619077380, 50, 15.000000000000000, 0.0 },
  { 980.26961889791028, 50, 20.000000000000000, 0.0 },
  { 24812.277673870878, 50, 25.000000000000000, 0.0 },
  { 293000.50735962362, 50, 30.000000000000000, 0.0 },
  { 2316195.5013375278, 50, 35.000000000000000, 0.0 },
  { -14896937.968694873, 50, 40.000000000000000, 0.0 },
  { -502066598.00813466, 50, 45.000000000000000, 0.0 },
  { 2513677852.6916871, 50, 50.000000000000000, 0.0 },
  { 45129675503.538910, 50, 55.000000000000000, 0.0 },
  { -883876565337.99219, 50, 60.000000000000000, 0.0 },
  { 9361319947203.8418, 50, 65.000000000000000, 0.0 },
  { -80967880733583.234, 50, 70.000000000000000, 0.0 },
  { 717391079438942.62, 50, 75.000000000000000, 0.0 },
  { -8217471769564841.0, 50, 80.000000000000000, 0.0 },
  { 1.2595276229009978e+17, 50, 85.000000000000000, 0.0 },
  { -2.1140031308048891e+18, 50, 90.000000000000000, 0.0 },
  { 3.2438187475835134e+19, 50, 95.000000000000000, 0.0 },
  { -3.9710103487094692e+20, 50, 100.00000000000000, 0.0 },
};
const double toler007 = 2.5000000000000020e-13;

// Test data for n=100.
// max(|f - f_GSL|): 98304.000000000000 at index 20
// max(|f - f_GSL| / |f_GSL|): 3.8776197831393928e-15
// mean(f - f_GSL): -3668.6107413234895
// variance(f - f_GSL): 2.7407314162194493e+19
// stddev(f - f_GSL): 5235199534.1337748
const testcase_laguerre<double>
data008[21] =
{
  { 1.0000000000000000, 100, 0.0000000000000000, 0.0 },
  { 1.4555271625328801, 100, 5.0000000000000000, 0.0 },
  { 13.277662844303450, 100, 10.000000000000000, 0.0 },
  { 91.737038454342454, 100, 15.000000000000000, 0.0 },
  { 1854.0367283243388, 100, 20.000000000000000, 0.0 },
  { -11281.698886837261, 100, 25.000000000000000, 0.0 },
  { 170141.86987046551, 100, 30.000000000000000, 0.0 },
  { -2950092.7025822806, 100, 35.000000000000000, 0.0 },
  { -7272442.3156006960, 100, 40.000000000000000, 0.0 },
  { 295697471.90876162, 100, 45.000000000000000, 0.0 },
  { 4847420871.2690506, 100, 50.000000000000000, 0.0 },
  { 59406998102.392288, 100, 55.000000000000000, 0.0 },
  { 693492765740.29688, 100, 60.000000000000000, 0.0 },
  { 6606192010150.3154, 100, 65.000000000000000, 0.0 },
  { 17125518672239.770, 100, 70.000000000000000, 0.0 },
  { -870493767065150.12, 100, 75.000000000000000, 0.0 },
  { -13763178176383768., 100, 80.000000000000000, 0.0 },
  { 30667078414479584., 100, 85.000000000000000, 0.0 },
  { 2.1307220490380173e+18, 100, 90.000000000000000, 0.0 },
  { -7.2706523009007821e+18, 100, 95.000000000000000, 0.0 },
  { -2.6292260693068916e+20, 100, 100.00000000000000, 0.0 },
};
const double toler008 = 2.5000000000000020e-13;

template<typename Ret, unsigned int Num>
  void
  test(const testcase_laguerre<Ret> (&data)[Num], Ret toler)
  {
    bool test __attribute__((unused)) = true;
    const Ret eps = std::numeric_limits<Ret>::epsilon();
    Ret max_abs_diff = -Ret(1);
    Ret max_abs_frac = -Ret(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Ret f = std::laguerre(data[i].n, data[i].x);
	const Ret f0 = data[i].f0;
	const Ret diff = f - f0;
	if (std::abs(diff) > max_abs_diff)
	  max_abs_diff = std::abs(diff);
	if (std::abs(f0) > Ret(10) * eps
	 && std::abs(f) > Ret(10) * eps)
	  {
	    const Ret frac = diff / f0;
	    if (std::abs(frac) > max_abs_frac)
	      max_abs_frac = std::abs(frac);
	  }
      }
    VERIFY(max_abs_frac < toler);
  }

int
main()
{
  test(data001, toler001);
  test(data002, toler002);
  test(data003, toler003);
  test(data004, toler004);
  test(data005, toler005);
  test(data006, toler006);
  test(data007, toler007);
  test(data008, toler008);
  return 0;
}
