#include <iostream>
#include <string>
using namespace std;

/*
    * Function: isSubsequence
    * -----------------------
    * Checks whether string s is a subsequence of string t.
    *
    * Approach:
    *  - Use two pointers:
    *      - i → scans through string t
    *      - j → scans through string s
    *  - Whenever characters match (t[i] == s[j]), move both pointers.
    *  - Otherwise, move only i (try to find the next match for s[j]).
    *  - At the end, if j has reached the end of s, it means all characters
    *    of s appeared in order inside t → return true.
    *  - Otherwise, return false.
    *
    * Example:
    *   Input: s = "abc", t = "ahbgdc"
    *   Steps: a→found, b→found, c→found → return true
    *
    *   Input: s = "axc", t = "ahbgdc"
    *   Steps: a→found, x→not found → return false
    *
    * Time Complexity: O(n)   (scan whole string in worst case)
    * Space Complexity: O(1)    (only two integer pointers used)
*/


class Solution {
    public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;

        if (s == "") return true;

        while (i < t.size() && j < s.size()) {
            if (t[i] == s[j]) { // if both character are same then increment j & look for next character
                j++;
            }
            i++; // increment after every check
        }

        // if j is equal to s.size() then s is subsequence of t and return true else return false
        return j == s.size();
    }
};

// main function 
int main() {
    string s = "abc";
    string t = "ahbgdc";

    bool result = Solution().isSubsequence(s, t);

    cout << result;
    return 0;
}