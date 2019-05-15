#define _USE_MATH_DEFINES

#include <iostream>
#include "integrate.h"
#include "split.h"

using namespace Numerical_Integration;

int main()
{
    auto function = [](double x)
    { return 7 * pow(x, 3) - 8 * pow(x, 2) - 3*x + 3; }; // on [-1, 1] = 2/3
    
    Integration_rules I;
    
    double a = -1.0f, b = 1.0f;
    int n = 10;
    std::vector<double> split = regular(a, b, n);
    
    std::cout << "A = " << a
              << "\tB = " << b
              << "\tN = " << n << std::endl << std::endl;
    
    double result = I.rectangle_rule(split, function);
    std::cout << "Rectangle rule: " << result << std::endl << std::endl;
    
    result = I.trapezoid_rule(split, function);
    std::cout << "Trapezoid rule: " << result << std::endl << std::endl;
    
    result = I.simpson_rule(regular(a, b, n * 2), function);
    std::cout << "Simpson rule: " << result << std::endl << std::endl;
    
    return 0;
}