#include <ctype.h>
#include <iostream>
#include <string>

using namespace std;

//bool is_alphanumeric(char c)
//{
//    if( (c >= 'a' && c <= 'z') || 
//        (c >= 'A' && c <= 'Z') ||
//        (c >= '0' && c <= '9') )
//    {
//        return true;
//    }
//
//    return false;
//}

bool isPalindrome(string s) 
{
    if(s.empty())
        return true;

    int start = 0;
    int end = s.size() - 1;
    //int size = s.size();
    
    while(start <= end)
    {
        //while( (start < size) && !isalnum(s[start]) )
        while((start <= end) && !isalnum(s[start]))
            start++;

        //while( (end >= 0) && !isalnum(s[end]) )
        while((start <= end) && !isalnum(s[end]))
            end--;

        if(start <= end)
        {
            if( tolower(s[start]) == tolower(s[end]) )
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

