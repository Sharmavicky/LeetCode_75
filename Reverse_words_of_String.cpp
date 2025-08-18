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
                // skip leading spaces
                continue;
            } else if (c == ' ') {
                // push the word to result
                result.push_back(word);
                word = "";
            } else {
                // build the word
                word += c;
            }
        }

        // handle the last word
        if (!word.empty()) {
            result.push_back(word);
        }

        // reverse the order of words
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