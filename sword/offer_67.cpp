//剪绳子

/*
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m<=n），
每段绳子的长度记为k[1],...,k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

/*
思路:当绳子长度大于等于5时，把大于五的长度剪成一个一个三个的小段
小于5时，剩下长度4时最大2*2=4
3时，最大3=3
2时，最大2=2
*/

class Solution
{
public:
    int cutRope(int number)
    {
        int result = 1;

        while (number >= 5)
        {
            result *= 3;
            number -= 3;
        }
        return result * number;
    }
};