#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L) 
{
    vector<int> result;

    if(S.empty() || L.empty() || L[0].empty())
        return result;

    int size = S.size();
    int list_size = L.size();
    int word_size = L[0].size();

    unordered_map<string, int> hashmap;
    unordered_map<string, int> checkmap;
    for(int i=0; i<list_size; i++)
    {
        hashmap[L[i]]++;
        //if(hashmap.find(L[i]) == hashmap.end())
        //    hashmap[L[i]] = 0;
        //else
        //    hashmap[L[i]] += 1;
    }

    int len = size-(list_size*word_size);
    for(int i=0; i<=len; i++)
    {
        int count = 0;
        checkmap.clear();

        for(int j=i; j<=(size-word_size); j+=word_size)
        {
            string key = S.substr(j, word_size);

            if(hashmap.find(key) == hashmap.end())
                break;

            checkmap[key]++;
            //if(checkmap.find(key) == checkmap.end())
            //    checkmap[key] = 0;
            //else
            //    checkmap[key] += 1;

            if(checkmap[key] > hashmap[key])
                break;

            count++;
        }

        if(count == list_size)
        {
            result.push_back(i);
        }
    }

    return result;
}

