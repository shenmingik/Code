#include <chrono>
#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

int main()
{
    // 打印毫秒精度：1/1000s
    cout<<"millisecond:"<<endl;
    cout << chrono::milliseconds::period::num << "/"
         << chrono::milliseconds::period::den << "s" << endl;

    //表示一个时间段，单位为ms
    std::chrono::milliseconds ms_cond(1000);    //1s
    cout << ms_cond.count() << " milliseconds" << endl;

    //创建一个timepoint对象，距离Gen时间1970.1.1 8:00有多长时间
    std::chrono::time_point<std::chrono::system_clock, chrono::seconds>
        time_point(std::chrono::seconds(2));

    cout <<"to epoch "<< time_point.time_since_epoch().count()<<" s" << endl;
    time_t tt = std::chrono::system_clock::to_time_t(time_point);
    cout << tt << endl;
}