#include "integrate.h"
#include <cmath>

namespace Numerical_Integration
{
    Integration_Scheme::Integration_Scheme(Integration_Type type)
    {
        switch (type)
        {
            case rectangle:
                m_points = {0.0f};
                m_weights = {2.0f};
                break;
            case trapezoid:
                m_points = {-1.0f, 1.0f};
                m_weights = {1.0f, 1.0f};
                break;
            case simpson:
                m_points = {-1.0f, 0.0f, 1.0f};
                m_weights = {1.0f/3, 4.0f/3, 1.0f/3};
                break;
            case gauss2:
                // insert weights and points here
                break;
            case gauss5:
                m_points = {-0.90618, -0.538469, 0, 0.538469, 0.90618};
                m_weights = {0.236927, 0.478629, 0.568889, 0.478629, 0.236927};
                break;
        }
    }
    
    double Integration_Scheme::calculate(double from, double to, int segments, const std::function<double(double)>& func) const
    {
        double result = 0.0f,
                x0;
        double h = fabs(from - to) / static_cast<double>(segments);
    
        for (int i = 0; i < segments; i++)
        {
            x0 = from + i * h;
            for (int j = 0; j < m_points.size(); j++)
            {
                double p = x0 + (1 + m_points[j]) * h / 2;
                result += m_weights[j] * func(p);
            }
        }
        return result * h / 2.0f;
    }
}
