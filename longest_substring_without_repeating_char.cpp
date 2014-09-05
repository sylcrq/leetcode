#include <string>
#include <string.h>
#include <iostream>


using namespace std;

int lengthOfLongestSubstring(string s)
{
    int len = 0;
    int max = 0;

    char map_char[256] = {0};

    for(size_t i=0; i<s.length(); i++)
    {
        len = 0;
        memset(map_char, 0, 256);

        for(size_t j=i; j<s.length(); j++)
        {
            if(map_char[s[j]] == 0)
            {
                map_char[s[j]] = 1;
                len++;

                //最后一个字符，更新max
                if(j == (s.length() - 1))
                    max = (len > max) ? len : max;
            }
            else
            {
                max = (len > max) ? len : max;
                break;
            }
        }

        //cout << max << ",";
    }

    //cout << endl;

    return max;
}
