class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; 
        int minidx = 0;
        int maxidx = 0;
        for(int i=0;i<n;i++){
            if(nums[maxidx] < nums[i]) maxidx = i;
            if(nums[minidx] > nums[i]) minidx = i;
        }

        // Ensure i is the smaller index and j is the larger index
        int i = min(minidx, maxidx);
        int j = max(minidx, maxidx);
        
        // Find the minimum of the three possible deletion strategies
        int both_front = j + 1;
        int both_back = n - i;
        int from_both_sides = (i + 1) + (n - j);
        
        return min({both_front, both_back, from_both_sides});
    }
};