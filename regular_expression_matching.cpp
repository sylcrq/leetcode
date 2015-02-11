#include <assert.h>
#include <iostream>

// 递归
bool isMatch(const char *s, const char *p) 
{
    assert(s != NULL);
    assert(p != NULL);

    if(*s == '\0' && *p == '\0')
    {
        return true;
    }
    else if(*s == '\0' && *p != '\0')
    {
        const char* tmp = p;
        while(*tmp != '\0' && *(tmp+1) == '*')
            tmp += 2;

        if(*tmp == '\0')
            return true;
        else
            return false;
    }
    else if(*s != '\0' && *p == '\0')
    {
        return false;
    }

    // s and p is not empty
    if(*(p+1) != '*')
    {
        if(*p != '.' && *s != *p)
            return false;
    
        return isMatch(s+1, p+1);
    }
    else
    {
        if(isMatch(s, p+2))
            return true;

        const char* tmp = s+1;
        while(1)
        {
            if(*p != '.' && *(tmp-1) != *p)
                return false;

            if(isMatch(tmp, p+2))
                return true;

            if(*tmp == '\0')
                break;

            tmp++;
        }
    }

    return false;
}

