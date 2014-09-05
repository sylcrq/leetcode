#include <limits>
#include <vector>

using namespace std;

int maxProfit_ii(vector<int> &prices)
{
    int max = 0;
    int prev = numeric_limits<int>::max();

    for(size_t i=0; i<prices.size(); i++)
    {
        if(prices[i] > prev)
        {
            max += prices[i] - prev;
        }

        prev = prices[i];
    }

    return max;
}
