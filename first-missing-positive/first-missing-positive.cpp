// Naive Solution. Sort and check one by one.
// Time Complexity  - O(n * logn)
// Space Complexity - O(n)
​
class Solution {
public:
    int firstMissingPositive(vector <int> &nums) {
        
        // If list is empty, smallest positive number is 1
        if(nums.size() == 0) return 1;
        
        // Sorting
        sort(nums.begin(), nums.end());
        
        // Finding the smallest positive number in the sorted list
        int sm_pos = -1, sm_pos_idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                sm_pos = nums[i];
                sm_pos_idx = i;
                break;
            }
        }
        
        // If a positive number wasn't found or if the smallest positive number isn't 1, return 1;
        if(sm_pos == -1 || sm_pos > 1)
            return 1;
        
        // Looking for any missing numbers in the sorted list
        for(int i = sm_pos_idx; i < nums.size() - 1; i++)
            if((nums[i + 1] - nums[i]) > 1)
                return nums[i] + 1;
        
        // If no missing number was found, the missing number is the last number in the sorted list + 1
        return nums[nums.size() - 1] + 1;
    }
};
