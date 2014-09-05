#include <map>
#include <string>

using namespace std;


// 一种非常简单高效的方法
// 要求输入的罗马数字的规则必须是正确的
int romanToInt(string s)
{
    map<char, int> mymap;

    mymap['I'] = 1;
    mymap['V'] = 5;
    mymap['X'] = 10;
    mymap['L'] = 50;
    mymap['C'] = 100;
    mymap['D'] = 500;
    mymap['M'] = 1000;

    int result = 0;
    int prev = 0;

    for(size_t i=0; i < s.length(); i++)
    {
        int current = mymap[ s[i] ];

        if(prev < current)
        {
            result -= (2 * prev);
        }

        result += current;

        prev = current;
    }

    return result;
}
