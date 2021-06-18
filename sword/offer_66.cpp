//机器人运动范围

/*
地上有一个rows行和cols列的方格。坐标从 [0,0] 到 [rows-1,cols-1]。
一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于threshold的格子。 
例如，当threshold为18时，机器人能够进入方格[35,37]，因为3+5+3+7 = 18。
但是，它不能进入方格[35,38]，因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

/*
思路：写一个函数compute处于这个坐标的时候是否小于threshold，并且还有个visit[rows][cols]来
标识是否访问过这个元素。

之后，采用递归的思想，也就是栈结构。判断往上往下往左往右各能走几步，相加便是最终答案
*/
#include <vector>

using namespace std;

class Solution
{
public:
    int compute_coordinate(int row, int col)
    {
        int count = 0;
        while (row >= 10)
        {
            count += row % 10;
            row /= 10;
        }
        count += row;

        while (col >= 10)
        {
            count += col % 10;
            col /= 10;
        }
        count += col;
        return count;
    }

    int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<vector<bool>> &visit)
    {
        int count = 0;
        if (row >= rows || col >= cols || row < 0 || col < 0)
            return count;
        if (compute_coordinate(row, col) <= threshold && visit[row][col] == false)
        {
            visit[row][col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visit) + movingCountCore(threshold, rows, cols, row - 1, col, visit) + movingCountCore(threshold, rows, cols, row, col + 1, visit) + movingCountCore(threshold, rows, cols, row, col - 1, visit);
        }
        return count;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));

        int row = 0;
        int col = 0;

        return movingCountCore(threshold, rows, cols, row, col, is_visited);
    }
};