//数值的整数次方

#include<cmath>

class Solution {
public:
    //计算x的y次方
    double Pow(double base,int exponent)
    {
        double result = 1.0;
        while(exponent>0)
        {
            if(exponent%2 == 0)
            {
                base*=base;
                exponent/=2;
            }
            else
            {
                result*=base;
                exponent--;
            }
        }
        return result;
    }
    
    double Power(double base, int exponent) {
        //如果base为0
        if(abs(base)<1e-6)
        {
            return 0.0;
        }
        //判断次方数是否小于0
        if(exponent<0)
        {
            return 1.0/Pow(base,abs(exponent));
        }
        return pow(base,exponent);
    }
};
