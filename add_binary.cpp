#include <algorithm>
#include <string>

using namespace std;

//bool add(char a, char b, bool carry, char* result)
//{
//    bool ret = false;
//
//    if(a == '0' && b == '0')
//    {
//        if(carry)
//            *result = '1';
//        else
//            *result = '0';
//
//        ret = false;
//    }
//    else if(a == '1' && b == '1')
//    {
//        if(carry)
//            *result = '1';
//        else
//            *result = '0';
//
//        ret = true;
//    }
//    else
//    {
//        if(carry)
//        {
//            *result = '0';
//            ret = true;
//        }
//        else
//        {
//            *result = '1';
//            ret = false;
//        }
//    }
//
//    return ret;
//}

//优化字符相加的代码逻辑
string addBinary(string a, string b)
{
    int len_a = a.length();
    int len_b = b.length();

    //进位
    //bool carry = false;
    int carry = 0;

    int min = std::min(len_a, len_b);
    int max = std::max(len_a, len_b);

    string result(max, '0');

    int index_a = len_a - 1;
    int index_b = len_b - 1;
    int index_r = max - 1;

    for(int i=0; i<min; i++)
    {
        //carry = add(a[index_a], b[index_b], carry, &result[index_r]);
        int tmp = (a[index_a] - '0') + (b[index_b] - '0') + carry;
        result[index_r] = (tmp % 2) + '0';
        carry = tmp / 2;

        index_a--;
        index_b--;
        index_r--;
    }

    while(index_r >= 0)
    {
        if(index_a >= 0)
        {
            //carry = add(a[index_a], '0', carry, &result[index_r]);
            int tmp = (a[index_a] - '0') + carry;
            result[index_r] = (tmp % 2) + '0';
            carry = tmp / 2;

            index_a--;
        }
        else
        {
            //carry = add(b[index_b], '0', carry, &result[index_r]);
            int tmp = (b[index_b] - '0') + carry;
            result[index_r] = (tmp % 2) + '0';
            carry = tmp / 2;

            index_b--;
        }

        index_r--;
    }

    if(carry)
        result = '1' + result;

    return result;
}
