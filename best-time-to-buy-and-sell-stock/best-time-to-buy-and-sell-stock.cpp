class Solution {
public:
    int maxProfit(vector <int> &prices) {
        int max_profit = 0, min_val = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
            if(prices[i] < min_val)
                min_val = prices[i];
            else if(prices[i] - min_val > max_profit)
                max_profit = prices[i] - min_val;
        return max_profit;
    }
};
