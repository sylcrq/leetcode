#include <iostream>
#include <vector>
#include <map>

using namespace std;

void permuteUnique_helper(vector<int>& num, 
                          vector<int>& visited, 
                          size_t visited_num,
                          vector<int>& solution, 
                          vector<vector<int> >& result);

vector<vector<int> > permuteUnique(vector<int> &num) 
{
    vector<int> visited(num.size(), 0);
    vector<int> solution;
    vector<vector<int> > result;

    permuteUnique_helper(num, visited, 0, solution, result);

    return result;
}

void permuteUnique_helper(vector<int>& num, 
                          vector<int>& visited, 
                          size_t visited_num,
                          vector<int>& solution, 
                          vector<vector<int> >& result)
{
    if(num.size() == visited_num)
    {
        result.push_back(solution);
        return;
    }

    map<int, int> hash_map;

    for(size_t i=0; i<num.size(); i++)
    {
        if(visited[i] == 0 && hash_map.find(num[i]) == hash_map.end())
        {
            visited[i] = 1;
            hash_map.insert(std::pair<int, int>(num[i], num[i]));
            solution.push_back(num[i]);

            permuteUnique_helper(num, visited, visited_num + 1, solution, result);

            solution.pop_back();
            visited[i] = 0;
        }
    }
}

