#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> hashmap;

    for(vector<int>::iterator it=nums.begin(); it != nums.end(); it++) {
        if(hashmap.find(*it) == hashmap.end()) {
            hashmap.insert(std::make_pair(*it, *it));
        } else {
            return true;
        }
    }

    return false;
}

