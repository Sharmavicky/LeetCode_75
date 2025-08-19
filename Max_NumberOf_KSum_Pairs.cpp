#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
    * Problem: Given an array of integers nums and an integer k, return the maximum number of pairs (i, j) such that i < j and nums[i] + nums[j] == k.

    * Approach:
    * 1. Brute Force: Check all pairs using nested loops.
    * 2. Better Approach: Sort the array and use two pointers to find pairs.
    * 3. Optimal Approach: Use a frequency map to count pairs efficiently.
    
    * Time Complexity:
    * - Brute Force: O(n^2)
    * - Better Approach: O(n log n) for sorting, O(n) for finding pairs, total O(n log n).
    * - Optimal Approach: O(n) for counting frequencies and finding pairs.
    
    * Space Complexity:
    * - Brute Force: O(1) (ignoring input storage)
    * - Better Approach: O(1) (ignoring input storage)
    * - Optimal Approach: O(n) for the frequency map.
*/

class Solution {
    public:
    int BruteForce(vector<int>& nums, int k) {
        int count = 0, length = nums.size();

        // iterate through the array.
        for (int i=0; i<length; i++) {
            // Skip already counted pairs.
            if (nums[i] == -1) continue;
            for (int j=i+1; j<length; j++) {
                // Skip already counted pairs.
                if (nums[j] == -1) continue;
                // if the sum of the two numbers is equal to k, increment count.
                if (nums[i] + nums[j] == k) {
                    count++;
                    // Mark the numbers as counted by setting them to -1.
                    nums[i] = -1;
                    nums[j] = -1;
                    break; // Break to avoid counting the same number again.
                }
            }
        }

        // return the count of pairs.
        return count;
    }

    int BetterApproach(vector<int>& nums, int k) {
        int count = 0, length = nums.size(), i = 0, j = length -1;

        // sort the array.
        sort(nums.begin(), nums.end());

        while (i < j) {
            // If the sum of the two numbers is equal to k, increment count and move both pointers.
            if (nums[i] + nums[j] == k) {
                count++;
                i++;
                j--;
            } else if (nums[i] + nums[j] < k) {
                // if the sum if less than k, increment the left pointer.
                i++;
            } else {
                // if the sum is greater than k, decrement the right pointer.
                j--;
            }
        }

        // return the count of pairs.
        return count;
    }

    int OptimalApproach(vector<int>& nums, int k) {
        int count = 0;
        map<int, int> frequencyCount;

        // Count the frequency of each number in the array.
        for (int num : nums) {
            frequencyCount[num]++;
        }

        // Iterate through the nums array.
        for (int num: nums) {
            int comp = k - num;
            // if the complement exists in the frequency map.
            if (frequencyCount.find(comp) != frequencyCount.end()) {
                // If the complement is the same as the number, we can form pairs only if there are at least two occurrences.
                if (comp == num) {
                    count += frequencyCount[num] / 2;
                } else {
                    // If the complement is different, we can form pairs with the minimum frequency of both numbers.
                    count += min(frequencyCount[num], frequencyCount[comp]);
                }
                // Mark the number and its complement as counted by setting their frequencies to 0.
                frequencyCount[num] = 0;
            }
        }

        return count;
    }
};

// main function
int main() {
    vector<int> nums = {3, 1, 3, 4, 3};
    int k = 6;

    Solution solution;
    int result = solution.OptimalApproach(nums, k);

    cout << result;
    return 0;
}