#ifndef INTEGRATE_H
#define INTEGRATE_H

#include <functional>
#include <vector>

namespace Numerical_Integration
{
    class Integration_Scheme
    {
    protected:
        std::vector<double> m_points,
                m_weights;
    public:
        enum Integration_Type
        {
            rectangle,
            simpson,
            gauss2,
            gauss5
        };
        
        explicit Integration_Scheme(Integration_Type type);
        
        double calculate(double from, double to, int segments, const std::function<double(double)>& func) const;
    };
}
#endif // INTEGRATE_H
