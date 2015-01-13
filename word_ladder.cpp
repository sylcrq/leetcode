#include <deque>
#include <string>
#include <unordered_set>

using namespace std;

// 广度优先搜索 + 剪枝
int ladderLength(string start, string end, unordered_set<string> &dict) 
{
    if(start.empty() || end.empty() || start.size() != end.size())
        return 0;

    if(start.compare(end) == 0)
        return 2;

    int str_size = start.size();
    //int dict_size = dict.size();

    int depth = 0;
    int curr_nodes = 1;
    int next_nodes = 0;

    deque<string> my_queue;
    my_queue.push_back(start);

    unordered_set<string> visited;
    visited.insert(start);

    while(!my_queue.empty())
    {
        string str = my_queue.front();
        my_queue.pop_front();
        curr_nodes--;

        for(int i=0; i<str_size; i++)
        {
            string tmp = str;
            for(int j=0; j<26; j++)
            {
                tmp[i] = j + 'a';
                // find
                if(tmp.compare(end) == 0)
                    return (depth+2);

                // 剪枝
                if(visited.find(tmp) != visited.end())
                    continue;

                if(dict.find(tmp) != dict.end())
                {
                    my_queue.push_back(tmp);
                    visited.insert(tmp);
                    next_nodes++;
                }
            }
        }

        if(curr_nodes == 0)
        {
            curr_nodes = next_nodes;
            next_nodes = 0;

            depth++;
            // 剪枝
            //if(depth > (dict_size+2))
            //    break;
        }
    }

    // no such transformation sequence
    return 0;
}

