// Find two largest numbers in array and do some magic
// Time Complexity  - O(n)
// Space Complexity - O(1)
​
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        
        for(auto num : nums) {
            if(num > max1) {
                max2 = max1;
                max1 = num;
            }
            else if(num > max2)
                max2 = num;
        }
        
        return (max1 - 1) * (max2 - 1);
    }
};
