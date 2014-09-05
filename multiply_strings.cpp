#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//字符串(number)与单个字符(number)相乘
string multiply(string str, char c)
{
    if(c == '0') return string("0");

    int len = str.length();

    string result;
    int flag = 0;

    for(int i=len-1; i>=0; i--)
    {
        int tmp = (str[i] - '0') * (c - '0');
        //最低位与flag相加有可能要进1
        int carry = tmp % 10 + flag;

        result.append(1, (carry % 10) + '0');
        flag = tmp / 10 + carry / 10;
    }

    if(flag > 0)
        result.append(1, flag + '0');

    reverse(result.begin(), result.end());

    return result;
}

//字符串num2左移shift位与字符串num1相加
string add(string num1, string num2, int shift)
{
    string result;
    //字符串移位补0
    num2.append(shift, '0');

    int len1 = num1.length();
    int len2 = num2.length();

    int n = std::min(len1, len2);

    int flag = 0;

    for(int i=0; i<n; i++)
    {
        int tmp = (num1[len1-1-i] - '0') + (num2[len2-1-i] - '0') + flag;

        result.append(1, (tmp % 10) + '0');
        flag = tmp / 10;
    }

    for(int i=len1-n; i>0; i--)
    {
        int tmp = (num1[i-1] - '0') + flag;
        result.append(1, (tmp % 10) + '0');
        flag = tmp / 10;
    }

    for(int i=len2-n; i>0; i--)
    {
        int tmp = (num2[i-1] - '0') + flag;
        result.append(1, (tmp % 10) + '0');
        flag = tmp / 10;
    }

    if(flag)
        result.append(1, flag + '0');

    reverse(result.begin(), result.end());

    return result;
}

string multiply(string num1, string num2)
{
    if(num1.compare("0") == 0 || num2.compare("0") == 0)
        return string("0");

//参考林应老师的解法,优化代码逻辑
//    int len2 = num2.length();
//
//    string result = multiply(num1, num2[len2 - 1]);
//
//    for(int i=0; i<len2-1; i++)
//    {
//        string tmp = multiply(num1, num2[len2 - 2 - i]);
//
//        result = add(result, tmp, i+1);
//    }
//
//    return result;

    string result;
    int flag = 0;
    int shift = 0;

    for(int i=num1.length()-1; i>=0; i--)
    {
        int position = shift;
        
        for(int j=num2.length()-1; j>=0; j--)
        {
            int tmp = (num1[i] - '0') * (num2[j] - '0') + flag;

            if(position < result.length())
            {
                //当前result字符串为逆序
                tmp += result[position] - '0';
                result[position] = (tmp % 10) + '0';
            }
            else
            {
                result.append(1, (tmp % 10) + '0');
            }

            flag = tmp / 10;
            position++;
        }

        if(flag)
            result.append(1, flag + '0');

        shift++;
        flag = 0;
    }

    std::reverse(result.begin(), result.end());

    return result;
}


