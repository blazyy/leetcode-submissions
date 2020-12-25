class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        if(haystack == "" || haystack.length() < needle.length())
            return -1;
        int nptr = 0;
        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[nptr]){
                if(haystack.length() - i < needle.length())
                    return -1;
                for(int j = i; j < i + needle.length(); j++){
                    if(haystack[j] != needle[nptr++]){
                        nptr = 0;
                        break;
                    }
                }
                if(nptr == needle.length()) return i;
            }
        }
        return -1;
    }
};
