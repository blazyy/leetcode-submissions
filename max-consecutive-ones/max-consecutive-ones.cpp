class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, highest = 0;
        for(auto num : nums){
            if(num == 1)
                count++;
            else{
                highest = max(highest, count);
                count = 0;
            }
        }
        return max(highest, count);
    }
};
