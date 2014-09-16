#include <algorithm>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int start = 0;
    int end = height.size() - 1;

    int max_area = 0;

    while(start < end)
    {
        int area = min(height[start], height[end]) * (end - start);

        max_area = max(max_area, area);

        if(height[start] <= height[end])
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    return max_area;
}
