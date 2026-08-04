class Solution {
public:
    std::vector<int> findMissingElements(std::vector<int>& nums) {
        if (nums.empty()) return {};

        // Find the boundary limits
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());

        // Store all existing numbers for fast lookup
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        std::vector<int> res;

        // Check which numbers in the range [min, max] are missing
        for (int i = min_val; i <= max_val; i++) {
            if (num_set.find(i) == num_set.end()) {
                res.push_back(i);
            }
        }

        // The result is already sorted because we iterated from min to max
        return res;
    }
};