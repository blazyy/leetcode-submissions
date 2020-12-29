class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra_candies) {
        vector <bool> has_extra_candies;
        int max_candies = *max_element(candies.begin(), candies.end());
        for(auto candy : candies)
            has_extra_candies.push_back(candy + extra_candies >= max_candies);
        return has_extra_candies;
    }
};
