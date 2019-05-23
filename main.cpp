#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

#include "integrate.h"

using namespace Numerical_Integration;

int main()
{
    auto f = [](double x) -> double
    { return x * sin(10'000 * x); };
    
    auto F = [](double x) -> double
    { return (sin(10'000 * x) - 10'000 * x * cos(10'000 * x)) / 100'000'000; };
    
    const double a = 0, b = 1;
    const int n = 1000;
    
    std::cout << "a = " << a
              << "\tb = " << b << std::endl << std::endl;
    
    std::cout.setf(std::ios::scientific);
    
    // test all integration rules on different h
    for (int i = 0; i <= Integration_Scheme::gauss5; i++)
    {
        std::cout << "type: " << i << std::endl;
        
        Integration_Scheme I(static_cast<Integration_Scheme::Integration_Type>(i));
        for (int j = 1; j < 5; j *= 2)
        {
            const double I_calc = I.calculate(a, b, n * j, f);
            const double I_true = F(b) - F(a);
            std::cout << std::endl << "H = " << fabs(b - a) / (n * j) << std::endl
                      << "calculated: " << I_calc << std::endl
                      << "true: " << I_true << std::endl
                      << "diff: " << fabs(I_calc - I_true) << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
    
    return 0;
}
