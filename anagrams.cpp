#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

unsigned int hash_code(string& str);

vector<string> anagrams(vector<string> &strs) 
{
    vector<string> result;
    map<unsigned int, vector<string> > hash_map;

    if(strs.empty())
        return result;

    for(size_t i=0; i<strs.size(); i++)
    {
        string tmp = strs[i];
        std::sort(tmp.begin(), tmp.end());

        unsigned int val = hash_code(tmp);

        hash_map[val].push_back(strs[i]);
        //if(hash_map.find(val) == hash_map.end())
        //{
        //    hash_map.insert( std::pair<unsigned int, vector<string> >(val, vector<string>(1, strs[i])) );
        //}
        //else
        //{
        //    hash_map[val].push_back(strs[i]);
        //}
    }

    for(map<unsigned int, vector<string> >::iterator it=hash_map.begin(); it != hash_map.end(); it++)
    {
        if((it->second).size() > 1)
        {
            result.insert(result.end(), (it->second).begin(), (it->second).end());
            //for(vector<string>::iterator it2=(it->second).begin(); it2 != (it->second).end(); it2++)
            //{
            //    result.push_back(*it2);
            //}
        }
    }

    return result;
}

// BKDR Hash Function
unsigned int hash_code(string& str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    for(size_t i=0; i<str.size(); i++)
    {
        hash = hash*seed + str[i];
    }

    return (hash & 0x7FFFFFFF);
}

