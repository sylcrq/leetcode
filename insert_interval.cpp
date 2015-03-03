#include <vector>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
    int size = intervals.size();

    int pos_1 = 0;
    int pos_2 = size-1;
    while(pos_1 < size && newInterval.start > intervals[pos_1].end)
        pos_1++;

    while(pos_2 >= 0 && newInterval.end < intervals[pos_2].start)
        pos_2--;
    
    if(pos_1 >= size)
    {
        // new interval大于当前intervals
        intervals.push_back(newInterval);
    }
    else if(pos_2 < 0)
    {
        // new interval小于当前intervals
        intervals.insert(intervals.begin(), newInterval);
    }
    else if(pos_1 > pos_2)
    {
        // new interval没有与intervals中任何重叠
        intervals.insert(intervals.begin()+pos_1, newInterval);
    }
    else
    {
        int len = pos_2-pos_1;

        if(newInterval.start < intervals[pos_1].start)
            intervals[pos_1].start = newInterval.start;

        intervals[pos_1].end = (newInterval.end > intervals[pos_2].end) ? newInterval.end : intervals[pos_2].end;

        if(len > 0)
            intervals.erase(intervals.begin()+pos_1+1, intervals.begin()+pos_2+1);
    }
    
    return intervals;
}

