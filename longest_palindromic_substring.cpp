#include <string>
#include <vector>

using namespace std;

// 动态规划
string longestPalindrome_ii(string s)
{
    string result;

    if(s.empty())
        return result;

    int size = s.size();
    int max = 1;
    int start = 0;

    vector<int> flag(size, 0);

    // P[i,j] = 1, j == i
    //        = 1, j == i+1 && s[i] == s[j]
    //        = 1, j > i+1 && s[i] == s[j] && P[i+1, j-1] == 1
    for(int i=size-1; i>=0; i--)
    {
        for(int j=size-1; j>=0; j--)
        {
            if((i == j) || ((i+1) == j && s[i] == s[j]) || ((i+1) < j && s[i] == s[j] && flag[j-1] == 1))
            {
                flag[j] = 1;

                if(j-i+1 > max)
                {
                    max = j-i+1;
                    start = i;
                }
            }
            else
            {
                flag[j] = 0;
            }
        }
    }

    result = s.substr(start, max);

    return result;
}

string longestPalindrome(string s) 
{
    string result;

    if(s.empty())
        return result;

    int size = s.size();

    int max = 1;
    int max_start = 0;
    int max_end = 0;

    // 长度为奇数的palindrome: "aba"
    for(int i=0; i<size; i++)
    {
        int start = i;
        int end = i;

        while( (start-1) >= 0 && (end+1) < size && s[start-1] == s[end+1])
        {
            start--;
            end++;
        }

        if((end-start+1) > max)
        {
            max = end-start+1;
            max_start = start;
            max_end = end;
        }
    }

    // 长度为偶数的palindrome: "abba"
    for(int i=0; i<size; i++)
    {
        int start = i;
        int end = i+1;
        
        while(start >= 0 && end < size && s[start] == s[end])
        {
            start--;
            end++;
        }

        if((end-start-1) > max)
        {
            max = end-start-1;
            max_start = start+1;
            max_end = end-1;
        }
    }

    result = s.substr(max_start, max_end-max_start+1);

    return result;
}

