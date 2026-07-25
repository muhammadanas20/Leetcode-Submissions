class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //using binary search finding value if not found then return l means first index of next bound region will be the placce of insertionof that target other wise return m

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int m = l + ( r - l )/2;
            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m + 1;
            else r = m - 1;
        }

        return l;
    }
};