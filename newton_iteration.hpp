#pragma once

#include "auxiliary.hpp"

LD NewtonMethod(const std::function<LD(const LD&)>& func, const std::function<LD(const LD&)>& proizv, const LD& start, std::pair<const LD&, std::ofstream&> residual) {
    LD x = start;
    size_t i = 0;

    auto&[answer, fin] = residual;
    fin << "Number of iterations;Difference from the answer\n";
    fin << i << ";" << std::abs(x - answer) << "\n";

    while (true) {
        x = x - func(x)/proizv(x);
        fin << ++i << ";" << std::abs(x - answer) << "\n";
        if (std::abs(func(x)) < EPSILON) {break;}
    }
    return x;
}

vector NewtonMethod(const std::function<vector(const vector&)>& func, const std::function<matrix(const vector&)>& matrixJ, const vector& start, const vector& answer, std::ofstream& fin) {
    vector x = start;
    size_t i = 0;

    fin << "Number of iterations;Difference from the answer\n";
    fin << i << ";" << norm_1(x - answer) << "\n";

    while (true) {
        x = x - prod(matrixJ(x), func(x));
        fin << ++i << ";" << norm_1(x - answer) << "\n";
        if (norm_1(func(x)) < EPSILON) {break;}
    }
    return x;
}