#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

#include "integrate.h"

using namespace Numerical_Integration;

int main()
{
    
    auto f = [](double x)
    { return pow(x, 5) + 4 * pow(x, 3); };
    
    auto F = [](double x)
    { return pow(x, 6) / 6 + pow(x, 4); };
    
    /* auto f = [](double x)
     { return 3 * pow(x, 8) + 2 * x; };
  
     auto F = [](double x)
     { return pow(x, 9) / 3 + pow(x, 2); };*/
    
    //auto f = [](double x)
    //{ return 5 * pow(x, 9) + 6 * pow(x, 5); };
    
    //auto F = [](double x)
    //{ return pow(x, 10) / 2 + pow(x, 6); };
    
    //auto f = [](double x)
    //{ return 11 * pow(x, 10) + 6 * pow(x, 2); };
    
    //auto F = [](double x)
    //{ return pow(x, 11) + 2 * pow(x, 3); };
    
    double a = 0,
            b = 3;
    int N = 10;
    
    std::cout << "a = " << a
              << "\tb = " << b << std::endl << std::endl;
    
    std::cout.setf(std::ios::scientific);
    
    // test all integration rules on different h
    
    for (int i = 0; i <= Integration_Scheme::gauss5; i++)
    {
        std::cout << "type: " << i << std::endl;
        
        
        double PreviousIh = 0.0;
        double PreviousItrue = 0.0;
        
        Integration_Scheme I((Integration_Scheme::Integration_Type) i);
        for (int j = 1; j < 5; j *= 2)
        {
            double I_calc = I.calculate(a, b, N * j, f);
            double I_true = F(b) - F(a);
            std::cout << std::endl << "H = " << fabs(b - a) / (N * j) << std::endl
                      << "calculated: " << I_calc << std::endl
                      << "true: " << I_true << std::endl
                      << "diff: " << fabs(I_calc - I_true) << std::endl;
            if (j != 1)
                std::cout << "Ih" << j / 2 << " - Ih" << j << " = "
                          << I_calc - PreviousIh << std::endl;
            if (j != 1)
                std::cout << "I*" << " - Ih/2" << " = "
                          << PreviousItrue - I_calc << std::endl;
            if (j != 1)
                std::cout << "m = "
                          << log2((I_calc - PreviousIh) / (PreviousItrue - I_calc) + 1.0) << std::endl;
            PreviousIh = I_calc;
            PreviousItrue = I_true;
            
            
        }
        std::cout << std::endl << std::endl;
    }
    
    return 0;
}