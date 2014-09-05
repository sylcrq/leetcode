
int reverse(int x)
{
//    int i = 10;
//
//    while(x/i != 0)
//        i *= 10;
//
//    i = i / 10;
//
//    int ret = 0;
//    int j = 1;
//
//    while(i >= 1)
//    {
//        ret += (x / i) * j;
//        x = x % i;
//        j = j * 10;
//        i = i / 10;
//    }
//
//    return ret;

    //优化代码逻辑
    int result = 0;

    while(x != 0)
    {
        result = (result * 10) + (x % 10);
        x = x / 10;
    }

    return result;
}
