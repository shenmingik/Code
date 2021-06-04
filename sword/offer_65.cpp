//矩阵中的路径

/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param matrix char字符型vector<vector<>> 
         * @param word string字符串 
         * @return bool布尔型
         */
    bool hasPathCore(vector<vector<char>> &matrix, int row, int line, int rows, int lines, string word, int &string_index, vector<vector<bool>> &visit)
    {
        //终止条件
        if (word[string_index] == '\0')
            return true;

        bool has_path = false;
        if (row >= 0 && row < rows && line >= 0 && line < lines &&
            matrix[row][line] == word[string_index] && visit[row][line] != true)
        {
            visit[row][line] = true;
            string_index++;

            has_path = hasPathCore(matrix, row + 1, line, rows, lines, word, string_index, visit) ||
                       hasPathCore(matrix, row - 1, line, rows, lines, word, string_index, visit) ||
                       hasPathCore(matrix, row, line + 1, rows, lines, word, string_index, visit) ||
                       hasPathCore(matrix, row, line - 1, rows, lines, word, string_index, visit);
            if (!has_path)
            {
                string_index--;
                visit[row][line] = false;
            }
        }
        return has_path;
    }

    bool hasPath(vector<vector<char>> &matrix, string word)
    {
        // write code here
        int rows = matrix.size();
        int lines = matrix[0].size();
        //全部初始化为0
        vector<vector<bool>> visit(rows, vector<bool>(lines, false));
        int string_index = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < lines; j++)
            {
                if (hasPathCore(matrix, i, j, rows, lines, word, string_index, visit))
                {
                    return true;
                }
            }
        }
        return false;
    }
};