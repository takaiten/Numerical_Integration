#include "integrate.h"

namespace Numerical_Integration
{
    double Integration_rules::rectangle_rule(const std::vector<double>& x, double h, const std::function<double(double)>& func)
    {
        double result = 0.0f;
        for (int i = 0; i < x.size() - 1; i++)
            result += func((x[i] + x[i + 1]) / 2);
        return result * h;
    }
    
    double Integration_rules::rectangle_rule(const std::vector<double>& x, const std::function<double(double)>& func)
    {
        double result = 0.0f;
        for (int i = 0; i < x.size() - 1; i++)
            result += func((x[i] + x[i + 1]) / 2);
        return result * (x[1] - x[0]);
    }
    
    double Integration_rules::trapezoid_rule(double a, double b, int n, const std::function<double(double)>& func)
    {
        double step = fabs(b - a) / (double) n,
                result = 0.5 * (func(a) + func(b));
        for (int i = 0; i < n; i++)
            result += func(a + i * step);
        result *= step;
        return result;
    }
    
    double Integration_rules::trapezoid_rule(const std::vector<double>& x, const std::function<double(double)>& func)
    {
        double result = 0.0f;
        int size = x.size();
        
        result += (func(x[0]) + func(x[size])) / 2;
        for (int i = 1; i < size - 1; i++)
            result += func(x[i]);
        
        return result * (x[1] - x[0]);
    }
    
    double Integration_rules::simpson_rule(double a, double b, int n, const std::function<double(double)>& func)
    {
        if (n % 2) n++;
        double step = fabs(b - a) / (double) n,
                result = func(a) + 4 * func(a + step) + func(b);
        for (int i = 0; i < n / 2; i++)
            result += 2 * func(a + (2 * i) * step) + 4 * func(a + (2 * i + 1) * step);
        result *= step / 3;
        return result;
    }
    
    double Integration_rules::simpson_rule(const std::vector<double>& x, const std::function<double(double)>& func)
    {
        double result = 0.0f;
        
        for (int i = 1; i < x.size() - 1; i += 2)
            result += func(x[i - 1]) + 4 * func(x[i]) + func(x[i + 1]);
        
        return result * (x[1] - x[0]) / 3;
    }
}