#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// 要求时间复杂度O(N)
int longestConsecutive(vector<int> &num) 
{
    int result = 0;

    map<int, int> my_map;

    // create hash map <value, index>
    for(size_t i=0; i<num.size(); i++)
    {
        my_map[num[i]] = i;
    }
    
    for(size_t i=0; i<num.size(); i++)
    {
        int len = 1;
        int lesser = num[i] - 1;
        int greater = num[i] + 1;

        map<int, int>::iterator it;

        while((it = my_map.find(lesser)) != my_map.end())
        {
            my_map.erase(it);
            lesser--;
            len++;
        }

        while((it = my_map.find(greater)) != my_map.end())
        {
            my_map.erase(it);
            greater++;
            len++;
        }

        result = std::max(result, len);
    }

    return result;
}

