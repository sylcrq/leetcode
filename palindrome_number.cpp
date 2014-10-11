
bool isPalindrome(int x)
{
    if(x < 0) return false;

    // if x = 4321 : n = 1000
    int n = 1;

    while(x/n >= 10)
    {
        n = n * 10;
    }

    while(x != 0)
    {
        if((x % 10) != (x / n))
            return false;

        x = x % n;
        x = x / 10;
        n = n / 100;
    }

    return true;
}

