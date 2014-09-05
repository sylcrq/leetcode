#include <vector>

#include "gtest/gtest.h"

using namespace std;

int maxProfit_ii(vector<int> &prices);

TEST(BestTimeToBuyAndSellStockIITestCase, Normal)
{
    vector<int> prices;
    EXPECT_EQ(0, maxProfit_ii(prices));

    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(5);
    EXPECT_EQ(4, maxProfit_ii(prices));

    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(7);
    EXPECT_EQ(10, maxProfit_ii(prices));
}
