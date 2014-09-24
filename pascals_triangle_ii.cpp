#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    // Check rowIndex
    vector<int> result(rowIndex + 1, 1);

#if 0
    // solution 1
    for(int i=2; i<rowIndex + 1; i++)
    {
        int prev = result[0];

        for(int j=1; j<i; j++)
        {
            int tmp = result[j] + prev;
            prev = result[j];

            result[j] = tmp;
        }
    }
#endif

    // solution 2: 从后往前加
    for(int i=1; i<rowIndex; i++)
    {
        for(int j=i; j>0; j--)
        {
            result[j] += result[j-1];
        }
    }

    return result;
}
