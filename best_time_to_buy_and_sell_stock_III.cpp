#include <vector>
#include <limits.h>

using namespace std;

int maxProfit_iii(vector<int> &prices) 
{
    int size = prices.size();

    vector<int> left_max(size, 0);
    vector<int> right_max(size, 0);

    // 计算[0, i]天的最大利润
    int max_profit = 0;
    int min = INT_MAX;

    for(int i=0; i<size; i++)
    {
        if(prices[i] < min)
            min = prices[i];

        if(prices[i] - min > max_profit)
            max_profit = prices[i] - min;

        left_max[i] = max_profit;
    }

    // 计算[i, N]天的最大利润
    max_profit = 0;
    int max = 0;
    
    for(int i=size-1; i>=0; i--)
    {
        if(prices[i] > max)
            max = prices[i];
        
        if(max - prices[i] > max_profit)
            max_profit = max - prices[i];

        right_max[i] = max_profit;
    }
    
    max_profit = 0;
    for(int i=0; i<size; i++)
    {
        if(left_max[i] + right_max[i] > max_profit)
            max_profit = left_max[i] + right_max[i];
    }

    return max_profit;
}

