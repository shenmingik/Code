#include <iostream>
#include <functional>
#include <string>

using namespace std;

struct Str
{
    string first_name;
    string second_name;
};

int maina()
{
    string str1 = "hello";
    string str2 = "world";
    cout<<hash<string>{}(str1)<<endl;   //2762169579135187400

    hash<string> temp_hash;
    cout << temp_hash(str2) << endl;    //8751027807033337960
}
