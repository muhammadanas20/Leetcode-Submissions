class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window method shrink window
        int l = 0;
        int res = INT_MAX;
        int sum = 0;
        for(int r =0;r < nums.size(); r++){
            sum += nums[r]; //increase window
            while(sum >= target){ //run while target is = or greter than curr sum
            res = min(res,r-l+1); //record len of subarray
            sum -= nums[l]; //shrink window from left side;
            l++; //index move to next
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};