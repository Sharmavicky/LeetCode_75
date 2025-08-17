#include <iostream>
#include <vector>
using namespace std;

/*
    * Given a flowerbed (represented as an array) and a number n, determine if n new flowers can be planted in the flowerbed or not

    * A flower can only be planted in an empty plot (0) if both adjacent plots are also empty (0).

    * Time Complexity: O(n), where n is the number of plots in the flowerbed.
    
    * Space Complexity: O(1), since we are using a constant amount of space.
*/

class Solution {
    public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, size = flowerbed.size();

        // If the length of flowerbed is 1, we can only place a flower if it's empty
        if (size == 1 && flowerbed[0] == 0) {
            count++;
        } else { // For larger flowerbeds, we check each plot
            int i=0;
            while (i < size) {
                if (flowerbed[i] == 1) {
                    i += 2; // skip the next plot
                } else {
                    if (i == 0 && flowerbed[i+1] == 0) {
                        count++;
                        flowerbed[i] = 1; // place a flower
                        i += 2; // skip the next plot
                    } else if (i == size - 1 && flowerbed[i-1] == 0) {
                        count++;
                        flowerbed[i] = 1;// place a flower
                        break; // no need to check further
                    } else if (i > 0 && i < size - 1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                        count++;
                        flowerbed[i] = 1; // place a flower
                        i += 2; // skip the next plot
                    } else {
                        i++; // move to the next plot
                    }
                }
            }
        }

        // Check if we planted enough flowers
        return count >= n;
    }
};

// main function
int main() {
    Solution solution;
    vector<int> flowerbed = {0};
    int n = 1;

    bool result = solution.canPlaceFlowers(flowerbed, n);

    cout << result;

    return 0;
}