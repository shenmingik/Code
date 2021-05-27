#include <iostream>

using namespace std;

// 递归斐波那契
int fibnacci(int n)
{
    if (n <= 1)
        return n;
    return fibnacci(n - 1) + fibnacci(n - 2);
}

int main()
{
    int input;
    cin >> input;
    cout << fibnacci(input) << endl;
}
