#include <iostream>
#include <string>
using namespace std;

/*
    * Given two strings word1 and word2, merge them alternatively to form a new string.
    
    * If the lengths of the strings are not equal, append the remaining characters of the longer string at the end.
    
    * Time Complexity: O(n + m), where n and m are the lengths of word1 and word2 respectively.
    
    * Space Complexity: O(n + m), since we are creating a new string to store the result.
*/
class Solution {
    public:
    string BruteForce(string word1, string word2) {
        string result = "";
        int i=0, n = word1.length(), m = word2.length();

        while (i < n || i < m) {
            if (i<n) result += word1[i];
            if (i<m) result += word2[i];
            i++;
        };

        return result;
    }
};

// Main Function
int main() {
    string s1 = "abc";
    string s2 = "pqrstvg";
    string result = Solution().BruteForce(s1, s2);
    
    for (char c : result) {
        cout << c << "";
    }
};
