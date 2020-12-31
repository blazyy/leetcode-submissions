// Using KMP, compute LPS array.
// Value at last element of LPS array gives length of substring.
// Check if the substring length is divisible by the length of the entire string.
// If so, string is a repeated substring pattern.
// Time Complexity  - O(n)
// Space Complexity - O(n)
​
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector <int> lps = computeLPS(s);
        int n = lps.size() - 1;
        return lps[n] and lps[n] % (n + 1 - lps[n]) == 0; 
    }
    vector <int> computeLPS(string str) {
        vector <int> lps (str.length(), 0);
        lps[0] = 0;
        int i = 1, j = 0;
        while(i < str.length()) {
            if(str[i] == str[j]) 
                lps[i++] = ++j;
            else {
                if(j != 0) j = lps[j - 1];
                else lps[i++] = 0;
            }
        }
        return lps;
    }
};
