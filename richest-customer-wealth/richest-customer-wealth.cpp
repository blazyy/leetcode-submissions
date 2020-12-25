class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int highest = 0, current_sum = 0;
        for(auto account : accounts){
            for(auto money : account)
                current_sum += money;
            highest = max(highest, current_sum);
            current_sum = 0;
        }
        return highest;
    }
};
