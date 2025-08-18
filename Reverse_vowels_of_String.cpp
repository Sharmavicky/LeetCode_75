#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Problem: Reverse the vowels of a string.
    
    Time Complexity: O(n), where n is the length of the string.
    Space Complexity: O(1), since we are modifying the string in place.
*/

class Solution {
    private:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }

    public:
    string BruteForce(string& s) {
        int i=0, j=s.size()-1;

        // if string is empty or has only one character
        if (s.empty() || s.size() ==  1) return s;

        while (i <= j) {
            // if both pointers are vowels, swap them
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (isVowel(s[i])) {// if only 'i' is a vowel, move 'j'.
                j--;
            } else if (isVowel(s[j])) {// if only 'j' is a vowel, move 'i'.
                i++;
            } else {// if both are not vowels, move both pointers
                i++;
                j--;
            }
        }

        return s;
    }
};

int main() {
    string s = "IceCreAm";
    string result = Solution().BruteForce(s);
    cout << s; // Output the modified string
    return 0;
}