class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int to_return;
        unordered_map <int, int> counts;
        for(auto num : nums){
            if(counts.find(num) != counts.end()) counts[num]++;
            else counts[num] = 1;
        }
        for(auto count : counts){
            if(count.second > nums.size() / 2){
                to_return = count.first;
                break;                
            }
        }
        return to_return;
    }
};
