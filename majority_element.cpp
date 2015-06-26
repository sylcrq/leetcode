#include <unordered_map>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, int> hashmap;

    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        if(hashmap.find(*it) != hashmap.end()) {
            hashmap[*it] += 1;
        } else {
            hashmap[*it] = 1;
        }
    }

    int result = 0;
    for(unordered_map<int, int>::iterator it=hashmap.begin(); it != hashmap.end(); it++) {
        if(it->second > (size/2)) {
            result = it->first;
            break;
        }
    }

    return result;
}

// 任意两个不相同的数字相互抵消, 剩下的就是majority element
int majorityElement_ii(vector<int>& nums) {
    int size = nums.size();
    int result = nums[0];
    int count = 1;

    for(int i=1; i<size; i++) {
        if(count == 0) {
            result = nums[i];
            count = 1;
        } else if(nums[i] == result) {
            count++;
        } else {
            count--;
        }
    }

    return result;
}
