#include <algorithm>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    vector<int> result;
    //vector<int> tmp;

    int carry = 1;  // 进位

    for(int i = digits.size()-1; i>=0; i--)
    {
        int num = digits[i] + carry;

        //if(num > 9)
        //{
        //    num = 0;
        //    carry = 1;
        //}
        //else
        //{
        //    carry = 0;
        //}

        result.push_back(num % 10);  // 优化 - 1
        carry = num / 10;
    }

    if(carry)
        result.push_back(1);

    reverse(result.begin(), result.end());  // 优化 - 2
    //for(int i = tmp.size()-1; i>=0; i--)
    //{
    //    result.push_back(tmp[i]);
    //}

    return result;
}

