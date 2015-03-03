#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);

TEST(InsertIntervalTestCase, Normal)
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(6, 9));

    Interval newInterval(2, 5);

    vector<Interval> result = insert(intervals, newInterval);

    for(auto it=result.begin(); it!=result.end(); it++)
        std::cout << (*it).start << "," << (*it).end << std::endl;
}

TEST(InsertIntervalTestCase, Overlap)
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(6, 7));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(12, 16));

    Interval newInterval(4, 9);
    
    vector<Interval> result = insert(intervals, newInterval);

    for(auto it=result.begin(); it!=result.end(); it++)
        std::cout << (*it).start << "," << (*it).end << std::endl;
}

TEST(InsertIntervalTestCase, NoOverlap)
{
    vector<Interval> intervals;
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(12, 15));

    Interval newInterval(6, 6);

    vector<Interval> result = insert(intervals, newInterval);

    for(auto it=result.begin(); it!=result.end(); it++)
        std::cout << (*it).start << "," << (*it).end << std::endl;
}
