class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        
        for (size_t i = 1; i < prices.size(); i++) {
            // If the price went up compared to yesterday, take the profit
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        
        return totalProfit;
    }
};
