// Time Complexity  - O(n)
// Space Complexity - O(n)
​
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> shuffled;
        for(int i = 0; i < n, n < nums.size(); i++){
            shuffled.push_back(nums[i]);
            shuffled.push_back(nums[n++]);
        }
        return shuffled;
    }
};
