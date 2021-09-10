// C++ 17新特性，需要在setting中搜索 cpp standard进行配置

#include <optional>
#include <string>
#include <iostream>

using namespace std;

struct Out
{
    string out1;
    string out2;
};

optional<Out> func1(string input)
{
    Out output;

    if (input == "result")
    {
        output.out1 = "hello";
        output.out2 = "world";
    }
    return output;
}

int main()
{
    auto ret = func1("result");

    //hello
    //world
    if (ret.has_value())
    {
        cout << ret->out1 << endl;
        cout << ret->out2 << endl;
    }
    return 0;
}
