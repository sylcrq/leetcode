#include <string>

using namespace std;

string intToRoman(int num)
{
    string result;

    while(num > 0)
    {
        if(num >= 1000)  // 千位
        {
            result.append(num/1000, 'M');
            num = num % 1000;
        }
        else if(num >= 100)  // 百位
        {
            if(num/100 == 9)
            {
                result.append("CM");
            }
            else if(num/100 == 4)
            {
                result.append("CD");
            }
            else if(num/100 < 5)
            {
                result.append(num/100, 'C');
            }
            else
            {
                result.append("D");
                if(num/100 > 5)
                {
                    result.append(num/100 - 5, 'C');
                }
            }

            num = num % 100;
        }
        else if(num >= 10)  // 十位
        {
            if(num/10 == 9)
            {
                result.append("XC");
            }
            else if(num/10 == 4)
            {
                result.append("XL");
            }
            else if(num/10 < 5)
            {
                result.append(num/10, 'X');
            }
            else
            {
                result.append("L");
                if(num/10 > 5)
                {
                    result.append(num/10 - 5, 'X');
                }
            }

            num = num % 10;
        }
        else if(num > 0)  // 个位
        {
            if(num == 9)
            {
                result.append("IX");
            }
            else if(num == 4)
            {
                result.append("IV");
            }
            else if(num < 5)
            {
                result.append(num, 'I');
            }
            else
            {
                result.append("V");
                if(num > 5)
                {
                    result.append(num - 5, 'I');
                }
            }

            num = 0;
        }
    }

    return result;
}
