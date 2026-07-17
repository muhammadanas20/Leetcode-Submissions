class Solution {
public:
    int divisibleGame(std::vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        
        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }

        // Collect all unique valid divisors > 1 present in the array
        std::vector<bool> candidate_k(max_val + 2, false);
        for (int num : nums) {
            for (int d = 1; d * d <= num; ++d) {
                if (num % d == 0) {
                    if (d > 1) candidate_k[d] = true;
                    if (num / d > 1) candidate_k[num / d] = true;
                }
            }
        }
        // Always include max_val + 1 to capture the baseline scenario (no elements divisible)
        candidate_k[max_val + 1] = true;

        long long max_score_diff = LLONG_MIN;
        long long chosen_k = -1;

        // Run Kadane's algorithm for each unique candidate k
        for (int k = 2; k <= max_val + 1; ++k) {
            if (!candidate_k[k]) continue;

            long long current_max = LLONG_MIN;
            long long running_sum = 0;

            for (int i = 0; i < n; ++i) {
                long long val = (nums[i] % k == 0) ? nums[i] : -nums[i];
                running_sum += val;
                if (running_sum > current_max) {
                    current_max = running_sum;
                }
                if (running_sum < 0) {
                    running_sum = 0;
                }
            }

            if (current_max > max_score_diff) {
                max_score_diff = current_max;
                chosen_k = k;
            } else if (current_max == max_score_diff) {
                if (chosen_k == -1 || k < chosen_k) {
                    chosen_k = k;
                }
            }
        }

        // Compute the result modulo 10^9 + 7 safely dealing with negative products
        long long result = (max_score_diff % MOD) * (chosen_k % MOD);
        result %= MOD;
        if (result < 0) {
            result += MOD;
        }

        return result;
    }
};