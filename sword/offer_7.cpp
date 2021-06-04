//斐波那契数列

/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项
（从0开始，第0项为0，第1项是1）。
*/

class Solution {
    public:
        int Fibonacci(int n) {
            int fibfirst = 0;
            int fibsecond = 1;
            int temp = 0;
            for(int i=0;i<n;i++)
            {
                temp = fibfirst;
                fibfirst = fibsecond;
                fibsecond = temp+fibsecond;
            }
            return fibfirst;
        }
    };