#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    // Check rowIndex

    vector<int> result(rowIndex + 1, 1);

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

    return result;
}
