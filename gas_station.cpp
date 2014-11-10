#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
{
    if(gas.empty() || cost.empty())
        return -1;

    vector<int> diff;
    for(size_t i=0; i<gas.size(); i++)
    {
        diff.push_back(gas[i] - cost[i]);
    }

    int gas_left = 0;
    int sum = 0;
    int start = 0;
    for(size_t i=0; i<gas.size(); i++)
    {
        gas_left += diff[i];

        // 如果区间diff[i, j]的和小于0, 那么起点必然不会在[i, j]内
        sum += diff[i];
        if(sum < 0)
        {
            sum = 0;
            start = i + 1;
        }
    }

    // can NOT complete circuit
    if(gas_left < 0)
        return -1;

    return start;
}

