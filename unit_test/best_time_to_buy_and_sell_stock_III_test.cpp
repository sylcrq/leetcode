#include "gtest/gtest.h"
#include <vector>

using namespace std;

int maxProfit_iii(vector<int> &prices);

TEST(BestTimeToBuyAndSellStockTestCaseIII, Normal)
{
    int prices_[5] = {2, 1, 2, 0, 1};
    vector<int> prices(prices_, prices_+5);

    EXPECT_EQ(2, maxProfit_iii(prices));
}
