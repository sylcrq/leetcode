#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> restoreIpAddresses(string s);

TEST(RestoreIPAddressesTestCase, Normal)
{
    vector<string> result = restoreIpAddresses("25525511135");

    for(vector<string>::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

TEST(RestoreIPAddressesTestCase, InValidIPAddress)
{
    vector<string> result = restoreIpAddresses("0279245587303");

    for(vector<string>::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

TEST(RestoreIPAddressesTestCase, Zero)
{
    vector<string> result = restoreIpAddresses("010010");

    for(vector<string>::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
