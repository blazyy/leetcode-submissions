class Solution {
public:
    vector <string> letterCombinations(string digits) {
        vector <string> result;
        if(digits.size() == 0)
            return result;
        vector <string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsRecursive(result, mappings, digits, "", 0);
        return result;
    }
    
    void letterCombinationsRecursive(vector <string> &result, vector <string> &mappings, string digits, string current, int index) {
        if(index == digits.size()) { // When all digits have been processed, add current string to result, and return.
            result.push_back(current);
            return; 
        }
        string letters = mappings[digits[index] - '0' - 2];
        for(auto letter : letters) // Recursively call function on each letter, increasing index by 1 and adding the current letter to current
            letterCombinationsRecursive(result, mappings, digits, current + letter, index + 1);
    }
};
