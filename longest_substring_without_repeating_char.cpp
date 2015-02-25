#include <string>
#include <string.h>
//#include <iostream>

using namespace std;

// 时间复杂度: O(N)
// 一种更好的解法: http://blog.csdn.net/linhuanmars/article/details/19949159
// Leetcode Run Time: 20ms, 2015-02-25
int lengthOfLongestSubstring_ii(string s)
{
    int size = s.size();
    int max = 0;
    char map_char[256] = {0};  // hash map

    int left = 0;
    int right = 0;

    while(right < size)
    {
        int index = s[right];

        if(map_char[index] == 0)
        {
            map_char[index] = 1;
            right++;
        }
        else
        {
            max = (right-left > max) ? (right-left) : max;

            while(map_char[index] != 0)
            {
                int tmp = s[left];

                map_char[tmp] = 0;
                left++;
            }
        }
    }

    max = (right-left > max) ? (right-left) : max;

    return max;
}

// 最差时间复杂度: O(N^2)
// 代码调整后Leetcode Run Time:50ms+, 2015-02-25
int lengthOfLongestSubstring(string s)
{
    int max = 0;
    char map_char[256] = {0};  // hash map

    for(size_t i=0; i<s.length(); i++)
    {
        int len = 0;
        memset(map_char, 0, 256);

        for(size_t j=i; j<s.length(); j++)
        {
            int index = s[j];

            if(map_char[index] == 0)
            {
                map_char[index] = 1;
                len++;
            }
            else
            {
                break;
            }
        }

        max = (len > max) ? len : max;
    }

    return max;
}
