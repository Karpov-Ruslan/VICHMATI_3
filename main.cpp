#include "fixed_point_iteration.hpp"
#include "newton_iteration.hpp"

////////////////////////////////////////
LD func(const LD& x) {
    return (x*std::pow(2L, x) - 1.0L);
}

constexpr LD eq_answer = 0.6411857445049859845L;

LD proizv(const LD& x) {
    return (std::log(2)*x*std::pow(2L, x) + std::pow(2L, x));
}

//////////////////////////////////////////

//x=f(x)
vector vector_f(const vector& x) {
    vector ret(2);
    ret[0] = std::cos(x[1]) + 0.85L;
    ret[1] = std::sin(x[0]) - 1.32L;
    return ret;
}

//F(x)=0
vector vector_F(const vector& x) {
    vector ret(2);
    ret[0] = -x[0] + std::cos(x[1]) + 0.85L;
    ret[1] = -x[1] + std::sin(x[0]) - 1.32L;
    return ret;
}

matrix matrixJ(const vector& x) {
    matrix ret(2, 2);
    ret(0, 0) = -1;
    ret(0, 1) = std::sin(x[1]);
    ret(1, 0) = -std::cos(x[0]);
    ret(1, 1) = -1;
    ret /= (1 + std::sin(x[1])*std::cos(x[0]));
    return ret;
}


const vector sys_answer(2);

////////////////////////////////

int main() {
    {
        vector &just = const_cast<vector&>(sys_answer);
        just[0] = 1.791338609964243133L;
        just[1] = -0.3442210364010110309L;
    }

    std::ofstream fin;

    fin << std::setprecision(max_precision);
    std::cout << std::setprecision(max_precision);

    //equation part
    fin.open("dataEQFixedPoint.csv");
    std::cout << FixedPointIteration(func, 0.5L, 0.0L, std::make_pair(eq_answer, std::ref(fin))) << std::endl;
    fin.close();

    fin.open("dataEQNewton.csv");
    std::cout << NewtonMethod(func, proizv, 0.0L, std::make_pair(eq_answer, std::ref(fin))) << std::endl;
    fin.close();

    //system of equations part
    fin.open("dataSYSFixedPoint.csv");
    std::cout << FixedPointIteration(vector_f, zero_vector(2), sys_answer, std::ref(fin)) << std::endl;
    fin.close();

    fin.open("dataSYSNewton.csv");
    std::cout << NewtonMethod(vector_F, matrixJ, zero_vector(2), sys_answer, std::ref(fin)) << std::endl;
    fin.close();


}
