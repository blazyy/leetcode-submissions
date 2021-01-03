// Sorting and counting. Number of pairs = summation of 1 to n - 1 where n is the number of repeated numbers.
// Time Complexity  - O(n log n)
// Space Complexity - O(1)
​
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
​
        int i = 0, count = 0;
        sort(nums.begin(), nums.end());
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == nums[i])
                count += j - i;
            else i = j;
        }
        
        return count;
    }
};
​
// Using a hashmap. The number of pairs is equal to the summation of 1 to n - 1 where n is the number of repeated numbers
// So if there are 3 repeated numbers, the number of pairs are 1 + 2 = 3. If there are 4, num pairs = 1 + 2 + 3 = 6.
// Time Complexity  - O(n)
// Space Complexity - O(n)
​
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
        
//         int num_pairs = 0;
//         unordered_map <int, int> num_seen;
        
//         for(auto num : nums) {
//             num_pairs += num_seen[num]; // Why is this above the line below? Because all we care about is the summation upto n - 1. The number of pairs can be updated afterwards.
//             num_seen[num]++;
//         }
        
//         return num_pairs;
//     }
// };
​
​
​
// Old Solution
// Double for loop. Because of the constrait i < j we can start the inner for loop from i + 1.
// Time Complexity  - O(n^2)
// Space Complexity - O(1)
​
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
        
//         int num_pairs = 0;
        
//         for(int i = 0; i < nums.size(); i++)
//             for(int j = i + 1; j < nums.size(); j++)
//                 if(nums[i] == nums[j])
//                     num_pairs++;
        
//         return num_pairs;
//     }
// };
