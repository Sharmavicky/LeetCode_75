#include <iostream>
#include <vector>
using namespace std;

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
    public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandies = 0;
        // Find the maximum number of candies
        for (int candy: candies) {
            if (candy > maxCandies) maxCandies = candy;
        }

        // chk if each kid can have the greatest number of candies
        for (int candy: candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};

// Main Function
int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = Solution().kidsWithCandies(candies, extraCandies);
    for (bool canHave : result) {
        cout << (canHave ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}