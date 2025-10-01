#include <iostream>
#include <vector>
using namespace std;

/*
    * @class Solution
    * @brief Provides methods to check if an array contains an increasing triplet subsequence.
    *
    * Methods:
    *
    * 1. BruteForce(vector<int> ar):
    *    - Checks all possible triplets (i, j, k) with i < j < k.
    *    - Returns true if ar[i] < ar[j] < ar[k] for any triplet.
    *    - Time Complexity: O(n^3)
    *    - Space Complexity: O(1)
    *
    * 2. Optimal(vector<int>& nums):
    *    - Uses two variables to track the smallest and second smallest numbers.
    *    - If a number greater than both is found, returns true.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(1)
    *
    * @param nums A vector of integers.
    * @return true if an increasing triplet exists, false otherwise.
*/

class Solution {
    public:
    bool BruteForce(vector<int> ar) {
        for(int i=0; i<ar.size(); i++) {
            for (int j=i+1; j<ar.size(); j++) {
                if (ar[i] < ar[j]) {
                    for (int k=j+1; k<ar.size(); k++) {
                        if (ar[j] < ar[k]) return true;
                    }
                }
            }
        }
        return false;
    }

    bool Optimal(vector<int>& nums) {
        int first = INT32_MAX, second = INT32_MAX;

        for (int n: nums) {
            if (n <= first) first = n;
            else if (n <= second) second = n;
            else return true;
        }

        return false;
    }
};


// main function
int main() {
    vector<int> arr = {1, 3, 2, 4, 5};
    bool result = Solution().BruteForce(arr);
    cout << result;
    return 0;
}