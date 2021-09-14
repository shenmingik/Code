//524. 通过删除字母匹配到字典里最长单词

/*
 * 给你一个字符串 s 和一个字符串数组 dictionary 作为字典，
 * 找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
 * 如果答案不止一个，返回长度最长且字典序最小的字符串。
 * 如果答案不存在，则返回空字符串。
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    //判断dest是否是source的子数组
    bool IsPartOf(string &source, string &dest)
    {
        int source_size = source.size();
        int dest_size = dest.size();
        int source_index = 0;
        int dest_index = 0;
        while (source_index < source_size && dest_index < dest_size)
        {
            if (source[source_index] == dest[dest_index])
            {
                source_index++;
                dest_index++;
            }
            else
            {
                source_index++;
            }
        }

        if (dest_index == dest_size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string findLongestWord(string s, vector<string> &dictionary)
    {
        int size = dictionary.size();
        int max_index = -1;
        int max = 0;
        for (int i = 0; i < size; i++)
        {
            if (IsPartOf(s, dictionary[i]))
            {
                int temp_size = dictionary[i].size();
                if (temp_size >= max)
                {
                    //判断字典序
                    if (temp_size == max)
                    {
                        if (dictionary[max_index] > dictionary[i])
                        {
                            max_index = i;
                        }
                    }
                    else
                    {
                        max = temp_size;
                        max_index = i;
                    }
                }
            }
        }
        if (max_index != -1)
        {
            return dictionary[max_index];
        }
        else
        {
            return "";
        }
    }
};