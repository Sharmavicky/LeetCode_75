#include <iostream>
#include <vector>
using namespace std;

/*
    * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    
    * Time Complexity: O(n), where n is the length of the nums array.
    
    * Space Complexity: O(1), since we are modifying the array in place.
*/

class Solution {
    public:
    void BruteForce(vector<int>& nums) {
        int i = 0, j = i+1;

        while (i < nums.size()-1) {
            if (nums[i] == 0) {
                while (j < nums.size() && nums[j] == 0) {
                    j++;
                }

                if (j < nums.size()) {
                    swap(nums[i], nums[j]);
                }
            }
            i++;
            j = i + 1; // Reset j to the next position after i
        }
    }

    void Optimized(vector<int>& nums) {
        int snowBallSize = 0;

        for(int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                snowBallSize++;
            } else if (snowBallSize > 0) {
                swap(nums[i], nums[i - snowBallSize]);
            }
        }
    }
};


// main function
int main() {
    vector<int> nums = {0, 1, 3, 12, 0};
    Solution().Optimized(nums);
    
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}