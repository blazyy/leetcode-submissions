class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return false;
        unordered_set <int> num_set;
        for(auto num : nums){
            if(num_set.find(num) != num_set.end())
                return true;
            num_set.insert(num);
        }
        return false;
    }
};
