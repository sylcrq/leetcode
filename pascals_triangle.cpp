#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows)
{
    vector<vector<int> > result(numRows, vector<int>(1, 1));

    for(int i=1; i<numRows; i++)
    {
        for(int j=1; j<i; j++)
        {
            int val = result[i-1][j-1] + result[i-1][j];
            result[i].push_back(val);
        }

        result[i].push_back(1);
    }

    return result;
}

