#include "co.hpp"
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

static bool flag = true;

CO_BEGIN(co1)
    while(1){
        static int a = 1;
        cout << "co1 begin" << endl;
        WaitWhile(flag);
        flag = true;
        cout << "a="<<a++ << endl;
    }
CO_END(co1)

CO_BEGIN(co2)
    while(1)
    {
        cout << "co2 begin" << endl;
        flag = false;
        sleep(1);
        Yield();
        cout << "co2 rebegin" << endl;
        flag = true;
        Yield();
    }
CO_END(co2)

int maina()
{
    ADD_CO(co1, co2);
    Schdule();

}