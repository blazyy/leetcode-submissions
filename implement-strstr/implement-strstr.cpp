class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if(n == 0) 
            return 0;
        vector <int> lps = computeLPS(needle);
        int i = 0, j = 0;
        while(i < m) {
            if(haystack[i] == needle[j]) {
                i++, j++;
            }
            if(j == n) 
                return i - j;
            if(i < m && haystack[i] != needle[j]) {
                if(j == 0) 
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return -1;
    }
    vector <int> computeLPS(string needle) {
        int n = needle.length();
        vector <int> lps (n);
        int i = 1, j = 0;
        while(i < n) {
            if(needle[i] == needle[j])
                lps[i++] = ++j;
            else if(j != 0)
                    j = lps[j - 1];
                else 
                    lps[i++] = 0;
        }
        return lps;
    }
};
​
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle == "")
//             return 0;
//         if(haystack == "" || haystack.length() < needle.length())
//             return -1;
//         int nptr = 0;
//         for(int i = 0; i < haystack.length(); i++){
//             if(haystack[i] == needle[nptr]){
//                 if(haystack.length() - i < needle.length())
//                     return -1;
