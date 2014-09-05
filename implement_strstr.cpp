#include <string.h>
#include <stdio.h>

const char *strStr(const char *haystack, const char *needle)
{
    if(!haystack || !needle) return haystack;

    const char* ret = NULL;

    int len_h = strlen(haystack);
    int len_n = strlen(needle);

    if(0 == len_n) return haystack;
    if(len_h < len_n) return NULL;

    for(int i=0; i<=(len_h-len_n); i++)
    {
        if(0 == strncmp(haystack+i, needle, len_n))
        {
            ret = haystack+i;
            break;
        }
    }

    return ret;

//下面的代码在leetcode上不能通过
//    if(!haystack || !needle || strlen(haystack) < strlen(needle))
//        return NULL;

//    char* ret = NULL;

//    while(*haystack != '\0')
//    {
//        char* s1 = haystack;
//        char* s2 = needle;

//        while(*s1 != '\0' && *s2 != '\0')
//        {
//            if(*s1 != *s2) break;

//            s1++;
//            s2++;
//        }

//        if(*s2 == '\0')
//        {
//            ret = haystack;
//            break;
//        }

//        haystack++;
//    }

//    return ret;
}
