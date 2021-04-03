/*
题目描述：
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
*/

/*
错误思路：
利用两个下表i，j指向text1和text2，如果相等，两个下标均后移
如果不相等，保持j不变，去扫i，如果text1[i] == text[j]，也就是找到了，这个时候i必定不等于text1.size，直接break
如果没找到，那么j++，然后i再去扫

最终发现对此案例不适用：
"oxcpqrsvwf"
"shmtulqrypy"
*/

//代码：
#if 0
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int count = 0;
        int max = 0;
        int i=0,j=0;
        for(;i<text1.size() && j<text2.size();)
        {
            if(text1[i]==text2[j])
            {
                i++;
                j++;
                count++;
                max = max>count?max:count;
                cout<<i<<" "<<j<<endl;
            }
            else
            {
                int temp = i;
                //去找有没有text2[j]这个元素
                while(i < text1.size())
                {
                    if(text1[i]==text2[j])
                    {
                        break;
                    }
                    else
                    {
                        i++;
                    }
                }
                //如果没有
                if(i == text1.size())
                {
                    //下一个text2[j]
                    i = temp;
                    j++;
                }
                else
                {

                }
            }
        }

        return max;
    }
};
#endif

#include <vector>
#include <string>
using namespace std;

//正确代码：
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
                int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

