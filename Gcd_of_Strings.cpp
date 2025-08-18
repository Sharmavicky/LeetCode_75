#include <iostream>
#include <string>
#include <numeric>
using namespace std;

/*
    * The GCD of two strings is the largest string that can divide both strings without leaving a remainder.

    * If the concatenation of s1 and s2 is not equal to the concatenation of s2 and s1, then there is no common divisor.

    * If they are equal, the GCD of the two strings is the substring of either string from the start to the GCD of their lengths.

    * Time Complexity: O(n + m), where n and m are the lengths of the two strings.
    
    * Space Complexity: O(1), as we are not using any extra space that grows
*/

class Solution {
    public:
    string OptimisedApproach(string s1, string s2) {
        if (s1 + s2 != s2 + s1) return "";
        return s1.substr(0, gcd(s1.size(), s2.size()));
    }
};

int main() {
    string s1 = "ABCABC";
    string s2 = "ABC";
    string result = Solution().OptimisedApproach(s1, s2);
    cout << result;

    return 0;
}