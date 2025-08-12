#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    private:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }

    public:
    string BruteForce(string& s) { // Tc: O(n), Sc: O(1)
        int i=0, j=s.size()-1;

        if (s.empty() || s.size() ==  1) return s; // if string is empty or has only one character

        while (i <= j) {
            if (isVowel(s[i]) && isVowel(s[j])) {//if both are vowels, swap them
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