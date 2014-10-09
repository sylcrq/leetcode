// 时间复杂度: O(N)
int lengthOfLastWord(const char *s) 
{
    if(!s)
        return 0;

    int len = 0;

    while(*s != '\0')
    {
        if(*s != ' ')
            len++;
        else if(*(s+1) != ' ' && *(s+1) != '\0')
            len = 0;

        s++;
    }

    return len;
}

// 时间复杂度: O(N)
// 双指针
int lengthOfLastWord_ii(const char *s)
{
    if(!s)
        return 0;

    int len = 0;

    const char* prev = s;

    while(*s != '\0')
    {
        if(*s == ' ')
        {
            len = s - prev;  // update len

            while(*s == ' ')
                s++;

            prev = s;
        }
        else
        {
            s++;
        }
    }

    if(prev != s)
    {
        len = s - prev;
    }

    return len;
}

