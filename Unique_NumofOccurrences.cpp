#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
    * hashMapAndSet:
    *    - Uses an unordered_map to store element frequencies.
    *    - Uses an unordered_set to verify frequency uniqueness.
    *    - Time: O(n), Space: O(k).
    *
    * Both methods return true if all frequencies are unique, otherwise false.
*/

class Solution {
public:
    bool hashMapAndSet(vector<int> &nums) {
        unordered_map<int, int> freq;
        unordered_set<int> seen;

        // map frequency of all elements in freq
        for (int n : nums) freq[n]++;

        for (auto &it : freq) {
            // if frequency is not present in set than add it.
            if (seen.find(it.second) == seen.end()) seen.insert(it.second);

            // if frequency is present than return false.
            else return false;
        }

        // return true, if all frequencies are unique
        return true;
    }
};

// main function
int main(){
    vector<int> nums = {1, 1, 2, 2, 1, 3};
    bool res = Solution().hashMapAndSet(nums);
    cout << res;
    return 0;
}