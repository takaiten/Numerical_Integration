#ifndef INTEGRATE_H
#define INTEGRATE_H

#include <cmath>
#include <functional>

namespace Numerical_Integration
{
    class Integration_rules
    {
    public:
        double rectangle_rule(const std::vector<double> &x, double h, const std::function<double(double)>& func); // h in parameters to test speed
        double rectangle_rule(const std::vector<double> &x, const std::function<double(double)>& func);
        
        double trapezoid_rule(double a, double b, int n, const std::function<double(double)>& func);
        double trapezoid_rule(const std::vector<double> &x, const std::function<double(double)>& func);
        
        double simpson_rule(double a, double b, int n, const std::function<double(double)>& func);
        double simpson_rule(const std::vector<double> &x, const std::function<double(double)>& func);
    };
}

#endif //INTEGRATE_H
