
class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k is equal to the size of the array
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }
        
        // Count frequencies of all elements
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Case 2: k equals 1
        if (k == 1) {
            int max_val = -1;
            for (int num : nums) {
                if (count[num] == 1) {
                    max_val = std::max(max_val, num);
                }
            }
            return max_val;
        }
        
        // Case 3: 1 < k < n (Only boundary elements can be unique to 1 subarray)
        int max_val = -1;
        if (count[nums[0]] == 1) {
            max_val = std::max(max_val, nums[0]);
        }
        if (count[nums[n - 1]] == 1) {
            max_val = std::max(max_val, nums[n - 1]);
        }
        
        return max_val;
    }
};
