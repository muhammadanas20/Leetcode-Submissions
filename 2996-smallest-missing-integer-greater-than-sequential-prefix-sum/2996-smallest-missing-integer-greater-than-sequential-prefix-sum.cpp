

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        
        // 1. Calculate longest sequential prefix sum
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // 2. Sort to find missing elements linearly
        std::sort(nums.begin(), nums.end());
        
        // 3. Increment sum if it matches any element
        for (int num : nums) {
            if (num == sum) {
                sum++;
            }
        }
        
        return sum;
    }
};
