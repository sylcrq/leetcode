#include <string>

using namespace std;

// 计算结果可能会溢出
int titleToNumber(string s) {
    int num = 0;
    int ratio = 1;

    for(int i=s.size()-1; i>=0; i--) {
        //int tmp = s[i] - 'A' + 1;
        num += (s[i] - 'A' + 1) * ratio;
        ratio *= 26;
    }

    return num;
}
