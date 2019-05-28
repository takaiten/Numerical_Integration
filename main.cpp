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
    
    const double a = 0, b = M_PI;
    const int n = 5'000;
    
    std::cout << "a = " << a
              << "\tb = " << b << std::endl << std::endl;
    
    std::cout.setf(std::ios::scientific);
    
    std::vector<double> I_calculated;
    const double I_true = F(b) - F(a);
    
    // test all integration rules on different h
    
    for (int i = 0; i <= Integration_Scheme::gauss5; i++)
    {
        std::cout << "type: " << i << std::endl;
    
        Integration_Scheme I(static_cast<Integration_Scheme::Integration_Type>(i));
        
        I_calculated.clear();
        for (int j = 1; j < 5; j *= 2)
        {
            double I_c = I.calculate(a, b, n * j, f);
            I_calculated.push_back(I_c);
            
            std::cout << std::endl << "H = " << fabs(b - a) / (n * j) << std::endl
                      << "calculated: " << I_c << std::endl
                      << "true: " << I_true << std::endl
                      << "diff: " << fabs(I_c - I_true) << std::endl << std::endl;
        }
        for (int k = 0; k < 2; k++)
        {
            std::cout << "I = " << k + 1 << std::endl;
            std::cout << "I* - I(h) / I* - I(h/2) = "
                      << (I_true - I_calculated[k]) / (I_true - I_calculated[k + 1]) << std::endl;
            double m = log2(fabs(I_calculated[k+1] - I_calculated[k]) / fabs(I_true - I_calculated[k+1]) + 1.0);
            std::cout << "m = "
                      << m << std::endl;
            
            std::cout << "I(h/2) - I(h) / 2^m - 1 = "
                      << (I_calculated[k+1] - I_calculated[k]) / (pow(2, m) - 1) << std::endl;
            
            double Ir = (pow(2, m) * I_calculated[k+1] - I_calculated[k]) / (pow(2, m) - 1);
            std::cout << "Ir = "
                      << Ir << std::endl;
            
            std::cout << "I* - Ir = "
                      << I_true - Ir << std::endl << std::endl;
        }
        
        std::cout << std::endl << std::endl;
    }
    
    return 0;
}
