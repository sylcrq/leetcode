#include <string>

using namespace std;

string countAndSay(int n) 
{
    string result;

    if(n <= 0) return result;

    result.push_back('1');

    while(n > 1)
    {
        string prev = result;
        result.clear();  // clear

        char num = prev[0];
        int count = 1;

        // 字符串结尾字符'\0'
        for(size_t i=1; i<=prev.size(); i++)
        {
            if(prev[i] == num)
            {
                count++;
            }
            else
            {
                result.push_back('0'+count);
                result.push_back(num);

                num = prev[i];
                count = 1;
            }
        }

        n--;
    }

    return result;
}

