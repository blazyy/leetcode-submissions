class Solution {
public:
    string interpret(string command) {
        int i = 0;
        string str = "";
        while(i < command.length()) {
            if(command[i] == 'G'){
                str += 'G';
                i++;
            }
            else if(command[i] == '(') {
                if(command[i + 1] == ')'){
                    str += 'o';
                    i += 2;                    
                }
                else {
                    str += "al";
                    i += 4;
                }
            }
        }
        return str;
    }
};
