class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map <int, int> idx_counts;
        for(int i = 0; i < nums.size(); i++){
            idx_counts[i] = 0;
            for(int j = 0; j < nums.size(); j++)
                if(nums[j] < nums[i])
                    idx_counts[i]++;
        }
        vector <int> counts;
        for(int i = 0; i < nums.size(); i++)
            counts.push_back(idx_counts[i]);
        return counts;
    }
};
