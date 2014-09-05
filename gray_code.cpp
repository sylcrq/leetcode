#include <vector>

using namespace std;

vector<int> grayCode(int n)
{
    vector<int> result;

    int max = 1 << n;

    // 二进制数转换格雷码: G = (B / 2) ^ B
    for(int i=0; i<max; i++)
    {
        result.push_back( (i >> 1) ^ i );
    }

    return result;
}
