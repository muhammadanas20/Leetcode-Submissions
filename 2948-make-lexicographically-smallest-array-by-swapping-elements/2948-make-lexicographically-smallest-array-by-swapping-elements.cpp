#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        std::vector<std::pair<int, int>> indexed_nums(n);
        
        for (int i = 0; i < n; ++i) {
            indexed_nums[i] = {nums[i], i};
        }
        
        // Sort elements by their values
        std::sort(indexed_nums.begin(), indexed_nums.end());
        
        std::vector<int> res(n);
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            // Find the boundary of the current connected component
            while (j < n && indexed_nums[j].first - indexed_nums[j - 1].first <= limit) {
                j++;
            }
            
            // Extract indices for the current group
            std::vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(indexed_nums[k].second);
            }
            
            // Sort indices to place values in the leftmost available positions
            std::sort(indices.begin(), indices.end());
            
            // Assign sorted values to sorted indices
            for (int k = i; k < j; ++k) {
                res[indices[k - i]] = indexed_nums[k].first;
            }
            
            i = j; // Move to the next group
        }
        
        return res;
    }
};
