class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Majority Vote Algorithm
        int candidate = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == candidate) count++;
            else{
                count--;
                if(count == 0){
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() / 2];
//     }
// };

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int to_return;
//         unordered_map <int, int> counts;
//         for(auto num : nums){
//             if(counts.find(num) != counts.end()) counts[num]++;
//             else counts[num] = 1;
//         }
//         for(auto count : counts){
//             if(count.second > nums.size() / 2){
//                 to_return = count.first;
//                 break;                
//             }
//         }
//         return to_return;
//     }
// };
