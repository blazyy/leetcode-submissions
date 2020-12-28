class Solution {
public:
    vector <int> sortedSquares(vector <int> &nums) {
        
        vector <int> squares;
        int smallest = INT_MAX, mid, l = 0, r, n = nums.size();
        
        // Finding the midpoint of the array, i.e. the smallest absolute number
        while(l < n) {
            if(abs(nums[l]) < smallest) {
                smallest = abs(nums[l]);
                mid = l;
            }
            l++;
        }
        
        l = mid;
        r = mid + 1;
        
        // Two pointers starting at middle, which diverge
        while(l >= 0 and r < n) {
            if(abs(nums[l]) < abs(nums[r]))
                squares.push_back(pow(nums[l--], 2));
            else
                squares.push_back(pow(nums[r++], 2));
        }
        while(l >= 0) squares.push_back(pow(nums[l--], 2));
        while(r < n) squares.push_back(pow(nums[r++], 2));
​
        return squares;
    }
};
