#include <ctype.h>
#include <limits.h>

int my_atoi(const char *str) 
{
    if(!str) return 0;

    // checks for white-space characters
    while( isspace(*str) )
        str++;

    bool negative = false;
    int num = 0;

    // 检查符号位
    if(*str == '+')
    {
        negative = false;
        str++;
    }
    else if(*str == '-')
    {
        negative = true;
        str++;
    }

    int overflow_check_num = INT_MAX / 10;
    int overflow_last_bit = INT_MAX % 10;

    while(*str != '\0')
    {
        // checks for a digit (0 through 9)
        if( isdigit(*str) )
        {
            // 检查是否溢出
            if( num > overflow_check_num || (num == overflow_check_num && *str-'0' > overflow_last_bit) )
            {
                return (negative ? INT_MIN : INT_MAX);
            }

            num = num*10 + *str-'0';
        }
        else
        {
            break;
        }

        str++;
    }

    if(negative)
        num *= -1;

    return num;
}

