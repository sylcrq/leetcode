#include <unordered_map>

using namespace std;

bool isHappy(int n) {
    if(n <= 0) return false;

    unordered_map<int, int> hashmap;

    while(true) {
        if(hashmap.find(n) != hashmap.end() || n == 1)
            break;

        int sum = 0;
        hashmap[n] = 1;

        while(n > 0) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n = n / 10;
        }

        n = sum;
    }

    if(n == 1) return true;

    return false;
}

