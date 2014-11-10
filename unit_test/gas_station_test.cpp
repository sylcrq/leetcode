#include "gtest/gtest.h"
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost);


TEST(GasStationTestCase, Normal)
{
    int gas[4] = {4, 3, 2, 1};
    int cost[4] = {5, 1, 1, 2};

    vector<int> gas_(gas, gas+4);
    vector<int> cost_(cost, cost+4);

    EXPECT_EQ(1, canCompleteCircuit(gas_, cost_));
}
