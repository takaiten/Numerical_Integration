#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

#include "integrate.h"

using namespace Numerical_Integration;

int main()
{
    auto f = [](double x)
    { return sin(x); };
    
    auto F = [](double x)
    { return -cos(x); };
    
    double a = 0,
           b = 3 * M_PI / 2;
    int N = 10;
    
    std::cout << "a = " << a
              << "\tb = " << b << std::endl << std::endl;
    
    
    // test all integration rules on different h
    for (int i = 0; i <= Integration_Scheme::gauss5; i++)
    {
        std::cout << "type: " << i << std::endl;
        
        Integration_Scheme I((Integration_Scheme::Integration_Type) i);
        for (int j = 1; j < 5; j *= 2)
        {
            double I_calc = I.calculate(a, b, N * j, f);
            double I_true = F(b) - F(a);
            std::cout << std::endl << "H = " << fabs(b - a) / (N * j) << std::endl
                      << "calculated: " << I_calc << std::endl
                      << "true: " << I_true << std::endl
                      << "diff: " << fabs(I_calc - I_true) << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
    
    return 0;
}
