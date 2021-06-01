//二维数组中的查找

/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
  [1,2,8,9],
  [2,4,9,12],
  [4,7,10,13],
  [6,8,11,15]
]
给定 target = 7，返回 true。

给定 target = 3，返回 false。
*/
#include <vector>
using namespace std;
class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        int rows = array.size();
        int lines = array[0].size();

        int row = 0;
        int line = lines - 1;
        while (row < rows && line >= 0)
        {
            if (target < array[row][line])
            {
                line--;
            }
            else if (target == array[row][line])
            {
                return true;
            }
            else
            {
                row++;
            }
        }

        return false;
    }
};