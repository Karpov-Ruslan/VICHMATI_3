#pragma once

#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using LD = long double;
using matrix = typename boost::numeric::ublas::matrix<LD>;
using vector = typename boost::numeric::ublas::vector<LD>;
using zero_vector = typename boost::numeric::ublas::zero_vector<LD>;
using boost::numeric::ublas::prod;
using boost::numeric::ublas::norm_1;
constexpr LD EPSILON = 1e-10;
constexpr auto max_precision{std::numeric_limits<LD>::digits10 + 1};