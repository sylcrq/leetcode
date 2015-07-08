// 这个问题可以转换成n!中有多少对2*5
// 因为2出现的次数必然大于5，所以只要统计n!中5出现了多少次
int trailingZeroes(int n) {
    int result = 0;
    long long i = 5;  // overflow

    while(n >= i) {
        result += n/i;
        i *= 5;
    }

    return result;
}

