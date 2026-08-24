
class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Calculate the total sum of all stones in-place
        // stones[i] will store the prefix sum up to index i
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Step 2: Base case. 
        // If the player takes all stones, the score is stones[n-1].
        int max_diff = stones[n - 1];
        
        // Step 3: Iterate backwards from index n-2 down to 1
        // At each step, choose between:
        // 1. Splitting at the current index: stones[i] - max_diff
        // 2. Passing on this index and keeping the previous maximum difference
        for (int i = n - 2; i > 0; --i) {
            max_diff = std::max(max_diff, stones[i] - max_diff);
        }
        
        return max_diff;
    }
};