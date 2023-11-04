#pragma once

#include "auxiliary.hpp"

LD FixedPointIteration(const std::function<LD(const LD&)>& func, const LD& lambda, const LD& start, std::pair<const LD&, std::ofstream&> residual) {
    LD x = start;
    size_t i = 0;

    auto&[answer, fin] = residual;
    fin << "Number of iterations;Difference from the answer\n";
    fin << i << ";" << std::abs(x - answer) << "\n";

    while (true) {
        x = x - lambda*func(x);
        fin << ++i << ";" << std::abs(x - answer) << "\n";
        if (std::abs(func(x)) < EPSILON) {break;}
    }

    return x;
}

vector FixedPointIteration(const std::function<vector (const vector&)>& func, const vector& start, const vector& answer, std::ofstream& fin) {
    vector x = start;
    size_t i = 0;

    fin << "Number of iterations;Difference from the answer\n";
    fin << i << ";" << norm_1(x - answer) << "\n";

    while (true) {
        vector old_x = x;
        x = func(x);
        fin << ++i << ";" << norm_1(x - answer) << "\n";
        if (norm_1(x - old_x) < EPSILON) {break;}
    }

    return x;
}