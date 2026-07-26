class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] == target) return true;
            
            // Critical edge case for duplicates: shrink search space
            if (nums[l] == nums[m] && nums[m] == nums[r]) {
                l++;
                r--;
                continue;
            }
            
            // Check if the left half is normally sorted
            if (nums[l] <= nums[m]) {
                // Check if target lies within the sorted left half
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } 
            // Otherwise, the right half must be normally sorted
            else {
                // Check if target lies within the sorted right half
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};
