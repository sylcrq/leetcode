#include "gtest/gtest.h"
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices);

TEST(BestTimeToBuyAndSellStockTestCase, Normal)
{
    vector<int> prices;

    EXPECT_EQ(0, maxProfit(prices));

    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(1);

    EXPECT_EQ(0, maxProfit(prices));

    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(7);

    EXPECT_EQ(6, maxProfit(prices));
}
