#include <vector>
#include <cmath>

namespace Numerical_Integration
{
    std::vector<double> regular(double a, double b, int n)
    {
        std::vector<double> result;
        double x = 0.0,
               h = fabs(b - a) / (double) n;
        
        for (int i = 0; i <= n; i++)
        {
            x = a + i * h;
            result.push_back(x);
        }
        return result;
    }
}
