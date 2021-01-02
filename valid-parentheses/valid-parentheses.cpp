// If opening parentheses, push to stack. Else, check if current closing parentheses matches opening parentheses at stack top. If so, pop. If not, return false. At the end of the string, if there are still items in the stack, return false, because these are opening parentheses that wouldn't be closed.
// Time Complexity  - O(n)
// Space Complexity - O(n)
​
class Solution {
public:
    bool isValid(string str) {
        
        stack <char> s;
        string openers = "({[";
        string closers = ")}]";
        
        for(auto ch : str) {
            if(openers.find(ch) != string::npos)
                s.push(ch);
            else {
                if(s.empty()) return false;
                if(openers.find(s.top()) == closers.find(ch))
                    s.pop();
                else return false;
            }
        }
        
        return s.empty();
    }
};
