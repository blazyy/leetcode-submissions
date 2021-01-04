// Recursive DFS. Pretty self explanatory
// Time Complexity  - O(4 ^ n) where n is the number of digits, and 4 is the maximum possible number of branches
// Space Complexity - O(n) where n is the number of digits i.e. depth of the recurisve tree
​
class Solution {
public:
    vector <string> letterCombinations(string digits) {
        vector <string> result;
        if(digits.length() == 0)
            return result;
        vector <string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsRecursive(result, mappings, digits, "", 0);
        return result;
    }
    
    void letterCombinationsRecursive(vector <string> &result, vector <string> &mappings, string digits, string current, int index) {
        if(index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = mappings[digits[index] - '0' - 2];
        for(auto letter : letters)
            letterCombinationsRecursive(result, mappings, digits, current + letter, index + 1);
    }
};
