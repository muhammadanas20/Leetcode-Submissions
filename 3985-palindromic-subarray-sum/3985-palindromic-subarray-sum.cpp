class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // Step 1: Precompute prefix sums for O(1) subarray sum queries
        std::vector<long long> pref(n + 1, 0);
        long long maxSingleElement = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
            if (nums[i] > maxSingleElement) {
                maxSingleElement = nums[i];
            }
        }
        
        // Step 2: Transform the array to handle even and odd lengths uniformly
        std::vector<int> T(2 * n + 1, -1);
        for (int i = 0; i < n; ++i) {
            T[2 * i + 1] = nums[i];
        }
        
        int m = T.size();
        std::vector<int> P(m, 0);
        int C = 0, R = 0;
        long long maxSum = maxSingleElement; // Initialize with the largest single element
        
        // Step 3: Run Manacher's Algorithm
        for (int i = 0; i < m; ++i) {
            int i_mirror = 2 * C - i;
            
            if (R > i) {
                P[i] = std::min(R - i, P[i_mirror]);
            } else {
                P[i] = 0;
            }
            
            // Expand around the current center i
            while (i - 1 - P[i] >= 0 && i + 1 + P[i] < m && T[i - 1 - P[i]] == T[i + 1 + P[i]]) {
                P[i]++;
            }
            
            // Update the center and rightmost boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
            
            // Step 4: Map the expanded palindrome back to the original array positions
            int len = P[i]; 
            int start_idx = (i - len) / 2;
            
            if (len > 0) {
                long long currentSum = pref[start_idx + len] - pref[start_idx];
                maxSum = std::max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};