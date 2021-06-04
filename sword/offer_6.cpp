//旋转数组的最小数字

/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include <vector>

using namespace std;
//解法一：暴力法
class Solution {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            if(rotateArray.empty()) return 0;
            int min = rotateArray[0];
            for(int i=0;i<rotateArray.size();i++)
            {
                min = min<rotateArray[i]?min:rotateArray[i];
            }
            return min;
        }
    };


//解法二：二分
class Solution {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            int index_pre = 0;
            int index_end = rotateArray.size()-1;
            
            while(index_pre < index_end)
            {
                int index_middle = (index_end-index_pre)/2+index_pre;
                if(rotateArray[index_middle] == rotateArray[index_end])
                {
                    index_end=index_end-1;
                }
                else if(rotateArray[index_middle] > rotateArray[index_end])
                {
                    index_pre = index_middle+1;
                }
                else
                {
                    index_end=index_middle;
                }
            }
            return rotateArray[index_pre];
        }
    };