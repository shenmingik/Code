/*
题目描述:
    给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
*/
/*
思路:
    不断进行取模运算将每一位加起来，然后对这个和进行判断，如何大于10（不是单位数）递归；
    如果是单位数，返回。
*/

class Solution {
public:
    int addDigits(int num) {
        int ret = 0;
        while(num>0)
        {
            ret += num%10;
            num/=10;
        }
        if(ret>=10)
        {
            return addDigits(ret);
        }else
        {
            return ret;
        }
    }
};