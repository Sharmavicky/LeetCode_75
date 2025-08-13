#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void BruteForce(vector<int>& nums) {// Tc O(n^2), Sc O(1)
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

    void Optimized(vector<int>& nums) { // Tc O(n), Sc O(1)
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