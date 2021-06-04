//跳台阶

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution
{
public:
    int jumpFloor(int number)
    {
        if (number == 0)
            return 0;
        int dis_first = 1, dis_second = 0;
        for (int i = 1; i < number + 1; i++)
        {
            int temp = dis_first;
            dis_first = dis_first + dis_second;
            dis_second = temp;
        }
        return dis_first;
    }
};