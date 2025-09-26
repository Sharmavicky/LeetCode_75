#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
    * Class Solution solves the "Find the Difference of Two Arrays" problem (LeetCode 2215).
    *
    * Problem:
    * Given two integer arrays nums1 and nums2, return a list of two vectors:
    *   - The first contains all distinct integers present in nums1 but not in nums2.
    *   - The second contains all distinct integers present in nums2 but not in nums1.
    *
    * Approach (Using Hash Sets):
    * - Store unique elements of nums1 and nums2 in unordered_set for O(1) lookup.
    * - Iterate over n1_seen and add elements not found in n2_seen to the first result list.
    * - Iterate over n2_seen and add elements not found in n1_seen to the second result list.
    * - Return both result lists inside a 2D vector.
    *
    * Time Complexity: O(n + m), where n and m are the lengths of nums1 and nums2.
    * Space Complexity: O(n + m), for storing the sets.
*/

class Solution {
    public:
    vector<vector<int>> setApproach(vector<int>& n1, vector<int>& n2) {
        vector<vector<int>> res;
        
        /* 
            first store elements of n1 not present in n2
            second store elements of n2 not present in n1
        */
        vector<int> first, second;

        unordered_set<int> n1_seen(n1.begin(), n1.end());
        unordered_set<int> n2_seen(n2.begin(), n2.end());

        // iterate over n1_seen & chk if elements present in n2_seen or not;
        for (auto n: n1_seen) {
            if (n2_seen.find(n) == n2_seen.end()) first.push_back(n);
        }

        // iterate over n2_seen & chk if elements present in n1_seen or not;
        for (auto n: n2_seen) {
            if (n1_seen.find(n) == n1_seen.end()) second.push_back(n);
        }

        // add first & second in our res
        res.push_back(first);
        res.push_back(second);

        // return res
        return res;
    }
};

//main function
int main() {
    vector<int> n1 = {1, 2, 3};
    vector<int> n2 = {2, 4, 6};

    vector<vector<int>> res = Solution().setApproach(n1, n2);

    for (int i=0; i<res.size(); i++) {
        for (int n: res[i]) {
            cout << n << " ";
        }
        cout << "\n";
    }

    return 0;
}