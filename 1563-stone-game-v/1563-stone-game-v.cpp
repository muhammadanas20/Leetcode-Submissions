
class Solution {
private:
    int memo[501][501];

    int solve(const std::vector<int>& a, const std::vector<int>& prefix, int l, int r) {
        if (l == r) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int max_score = 0;
        for (int k = l; k < r; ++k) {
            // Get left and right segment sums in O(1)
            int left_sum = prefix[k] - (l == 0 ? 0 : prefix[l - 1]);
            int right_sum = prefix[r] - prefix[k];

            if (left_sum < right_sum) {
                max_score = std::max(max_score, left_sum + solve(a, prefix, l, k));
            } else if (left_sum > right_sum) {
                max_score = std::max(max_score, right_sum + solve(a, prefix, k + 1, r));
            } else {
                // If equal, Alice chooses the maximum score from both branches
                int best_choice = std::max(solve(a, prefix, l, k), solve(a, prefix, k + 1, r));
                max_score = std::max(max_score, left_sum + best_choice);
            }
        }

        return memo[l][r] = max_score;
    }

public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::memset(memo, -1, sizeof(memo));

        // Build prefix sum array
        std::vector<int> prefix(n);
        std::partial_sum(stoneValue.begin(), stoneValue.end(), prefix.begin());

        return solve(stoneValue, prefix, 0, n - 1);
    }
};
