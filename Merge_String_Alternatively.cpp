#include <iostream>
#include <string>
using namespace std;

/*
    Time Complexity: O(n+m) where n is the length of word1 and m is the length of word2.
    Space Complexity: O(1)
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
