// Concatenate string onto itself. Remove first and last char. If original string exists in new string, the string is a repeated substring pattern.
// Time Complexity  - O(n)
// Space Complexity - O(1)
​
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != string::npos;
    }
};
