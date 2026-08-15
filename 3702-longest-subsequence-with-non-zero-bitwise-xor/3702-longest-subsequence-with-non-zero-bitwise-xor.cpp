#include <vector>
#include <numeric>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int n = nums.size();
        int total_xor = 0;
        bool has_non_zero = false;

        for (int x : nums) {
            total_xor ^= x;
            if (x != 0) {
                has_non_zero = true;
            }
        }

        // If total XOR is non-zero, the whole sequence works
        if (total_xor != 0) {
            return n;
        }

        // If total XOR is zero, but there is at least one non-zero element,
        // we can remove that non-zero element to make the remaining XOR non-zero
        if (has_non_zero) {
            return n - 1;
        }

        // If all elements are zero, no non-zero XOR subsequence is possible
        return 0;
    }
};
