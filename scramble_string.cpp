#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 递归 + 剪枝
bool isScramble(string s1, string s2) 
{
    if(s1.size() != s2.size())
        return false;

    int size = s1.size();

    if(size == 1)
    {
        if(s1[0] == s2[0])
            return true;
        else
            return false;
    }

    // 剪枝
    vector<int> count(26, 0);
    for(int i=0; i<size; i++)
    {
        count[s1[i]-'a']++;
    }

    for(int i=0; i<size; i++)
    {
        count[s2[i]-'a']--;
    }

    for(int i=0; i<26; i++)
    {
        if(count[i] != 0)
            return false;
    }

    for(int i=1; i<size; i++)
    {
        bool result = isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                      isScramble(s1.substr(i), s2.substr(i));

        // 优化(if result == true)
        result = result || ( isScramble(s1.substr(0, i), s2.substr(size-i, i)) && 
                             isScramble(s1.substr(i), s2.substr(0, size-i)) );

        // Note!
        if(result)
            return true;
    }

    return false;
}


