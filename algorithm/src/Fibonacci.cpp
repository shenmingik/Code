#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// // 递归斐波那契
// int fibnacci(int n)
// {
//     if (n <= 1)
//         return n;
//     return fibnacci(n - 1) + fibnacci(n - 2);
// }
int fibnacci(int n, int first, int second)
{
    if (n <= 1)
        return second;
    else
        return fibnacci(n - 1, first + second, first);
}

// // 迭代斐波那契
// int fibnacci(int n)
// {
//     if (n == 0)
//         return 0;
//     int dis_first = 1, dis_second = 0;
//     for (int i = 1; i < n; i++)
//     {
//         int temp = dis_first;
//         dis_first = dis_first + dis_second;
//         dis_second = temp;
//     }
//     return dis_first;
// }

int pow(int input, int power)
{
    int r = 1;
    int value = input;
    while (power)
    {
        //如果是求奇数项次的平方
        if (power % 2 == 1)
        {
            r *= value;
            power -= 1;
        }
        value = value * value;
        power = power / 2;
    }
    return r;
}

vector<vector<int>> matrix_multiply(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2)
{
    int temp[4];
    temp[0] = matrix_1[0][0] * matrix_2[0][0] + matrix_1[0][1] * matrix_2[1][0];
    temp[1] = matrix_1[0][0] * matrix_2[0][1] + matrix_1[0][1] * matrix_2[1][1];
    temp[2] = matrix_1[1][0] * matrix_2[0][0] + matrix_1[1][1] * matrix_2[1][0];
    temp[3] = matrix_1[1][0] * matrix_2[0][1] + matrix_1[1][1] * matrix_2[1][1];
    matrix_1[0][0] = temp[0];
    matrix_1[0][1] = temp[1];
    matrix_1[1][0] = temp[2];
    matrix_1[1][1] = temp[3];
    return matrix_1;
}

vector<vector<int>> fibonacci_pow(vector<vector<int>> input, int power)
{
    vector<vector<int>> r = {{1, 0}, {0, 1}};
    vector<vector<int>> value = input;
    while (power)
    {
        //如果是求奇数项次的平方
        if (power % 2 == 1)
        {
            r = matrix_multiply(r, value);
            power -= 1;
        }
        value = matrix_multiply(value, value);
        power = power / 2;
    }
    return r;
}

//数学方法
//n = (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);

int main()
{
    int input;
    cin >> input;
    cout << fibnacci(input, 0, 1);
    // vector<vector<int>> a = {{0, 1}, {1, 1}};
    // vector<vector<int>> b = {{0, 1}, {0, 0}};
    // b = matrix_multiply(b, fibonacci_pow(a, 5));
    // for (int i = 0; i < b.size(); i++)
    // {
    //     for (int j = 0; j < b[0].size(); j++)
    //     {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
