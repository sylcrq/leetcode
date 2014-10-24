#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) 
{
    string prefix;

    if(strs.empty())
        return prefix;

    int min_size = strs[0].size();

    // 最短string的长度
    for(vector<string>::iterator it=strs.begin(); it != strs.end(); it++)
    {
        int size = (*it).size();
        min_size = std::min(size, min_size);
    }

    for(int i=0; i<min_size; i++)
    {
        char c = strs[0][i];

        size_t j = 0;
        for(j=0; j<strs.size(); j++)
        {
            if(c != strs[j][i])
                break;
        }

        if(j != strs.size())
            break;

        prefix.push_back(c);
    }

    return prefix;
}

