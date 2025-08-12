#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    string BruteForce(string& s) { // Tc: O(n), Sc: O(n)
        vector<string> result = {};
        string word = "";
        string reverse = "";

        for (char c: s) {
            if (c == ' ' && word.empty()) {
                continue; // skip leading spaces
            } else if (c == ' ') {
                result.push_back(word); // push the word to result
                word = "";
            } else {
                word += c; // build the word
            }
        }

        if (!word.empty()) {
            result.push_back(word); // push the last word
        }

        for (int i=result.size()-1; i>=0; i--) {
            reverse += result[i];
            if (i != 0) {
                reverse += " "; // add space between words
            }
        }

        return reverse;
    }
};


// main function
int main() {
    Solution sol;
    string input = "this is a test string";
    string output = sol.BruteForce(input);
    cout << "Reversed words: '" << output << "'" << endl;
    return 0;
}