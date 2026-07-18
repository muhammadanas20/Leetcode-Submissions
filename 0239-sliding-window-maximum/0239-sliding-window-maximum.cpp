class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> res;
        deque<int> dq;

        for(int i=0;i<nums.size();i++){
            //remove index of previous window
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            //remove all smaller values than mums[i]
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            //insert current idx
            dq.push_back(i);
            //add 1 complete window max into res which is front idx
            if(i >= k - 1){
             res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};