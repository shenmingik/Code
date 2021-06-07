//买卖股票的最好时机

/*
假设你有一个数组，其中第\ i i 个元素是股票在第\ i i 天的价格。
你有一次买入和卖出的机会。（只有买入了股票以后才能卖出）。请你设计一个算法来计算可以获得的最大收益。
*/
#include <vector>
using namespace std;
class Solution
{
public:
    /**
         * 
         * @param prices int整型vector 
         * @return int整型
         */
    int maxProfit(vector<int> &prices)
    {
        // write code here
        int size = prices.size();
        vector<int> dp(size + 1, 0);
        int buy = prices[0];
        dp[0] = 0;
        for (int i = 1; i < size; i++)
        {
            buy = buy < prices[i] ? buy : prices[i];
            dp[i] = max(dp[i - 1], prices[i] - buy);
        }
        return dp[size - 1];
    }
};