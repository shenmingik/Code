// likely

#if __GNUC__
#define likely(expr) __builtin_expect(!!(expr),1)
#define unlikely(expr) __builtin_expect(!!(expr),0)
#else
#define likely(expr) (expr)
#define unlikely(expr) (expr)
#endif

#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x;
    if (likely(x > 0))  //等价于if(x > 0),只是人为的告诉x>0的概率会大一些
                        //编译器会去预读y=x这个指令
    {
        y = x;
    }else
    {
        y = -x;
    }
    cout << y << endl;
}