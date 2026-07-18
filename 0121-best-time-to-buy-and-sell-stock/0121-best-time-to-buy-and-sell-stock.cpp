class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0; //buy day
        int r = 1; //sell day

        int maxP = 0; //max profit so far
        
        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l]; // calc profit r -l
                maxP = max(maxP,profit); // update the max onw
            }else{
                l = r; //found the cheaper buying day
            }
            r++; //checkig next selling day is giving max profit
        }
        return maxP;
    }
};