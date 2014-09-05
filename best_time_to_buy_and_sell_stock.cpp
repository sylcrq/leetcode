#include <limits>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int max = 0;  // 当前最大利润
    int min = numeric_limits<int>::max();  // 当前最低价格

    for(size_t i=0; i<prices.size(); i++)
    {
        if(prices[i] < min)
            min = prices[i];

        if(prices[i] - min > max)
            max = prices[i] - min;
    }

    return max;
}
