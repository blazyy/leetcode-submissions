class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector <int> luckies;
        unordered_map <int, int> counts;
        for(auto num : arr)
            if(counts.find(num) != counts.end())
                counts[num]++;
            else
                counts[num] = 1;
        for(auto count : counts)
            if(count.first == count.second)
                luckies.push_back(count.first);
        if(luckies.size() == 0)
            return -1;
        return *max_element(luckies.begin(), luckies.end());
    }
};
