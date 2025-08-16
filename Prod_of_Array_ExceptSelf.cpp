#include <iostream>
#include <vector>
using namespace std;

/*
    Problem here is to find the product of all elements in an array except the element at the current index.

    Time Complexity: {
        Brute Force Approach: O(n^2)
        Better Approach: O(n)
    }
    
    Space Complexity: {
        Brute Force Approach: O(n)
        Better Approach: O(1) // if we don't consider the output array
    }
*/

class Solution {
    public:
    vector<int> BruteForce(vector<int>& nums) {
        vector<int> result = {};
        for(int i=0; i < nums.size(); i++) {
            int prod =  1;
            for(int j=0; j < nums.size(); j++) {
                if (i != j) prod  *= nums[j];
            }
            result.push_back(prod);
        };
        return result;
    };

    vector<int> BetterApproach(vector<int>& nums) {
        vector<int> result = {};
        int prod = 1, zeroCount = 0;

        // calculate the product of all elements
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;
                continue;
            }
            prod *= nums[i];
        }

        if (zeroCount > 1) {
            // if there are more than one zero, all products will be zero
            return vector<int>(nums.size(), 0);
        } else if (zeroCount == 1) {
            // if there is one zero, only one product will be non-zero
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] == 0) result.push_back(prod);
                else result.push_back(0);
            }
        } else {
            // if there are no zeros, calculate product for each element
            for (int i=0; i<nums.size(); i++) {
                result.push_back(prod / nums[i]);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> result =  Solution().BetterApproach(nums);
    for(int i: result) {
        cout << i << " ";
    }
    return 0;
}
