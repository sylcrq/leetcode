#include <vector>

using namespace std;

// f(n) = f(n-1)*f(0) + f(n-2)*f(1) + ... + f(1)*f(n-2) + f(0)*f(n-1)
int numTrees(int n)
{
    vector<int> v(n+1, 0);

    v[0] = 1;
    v[1] = 1;

    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            v[i] += v[i-j-1] * v[j];
        }
    }

    return v[n];
}
