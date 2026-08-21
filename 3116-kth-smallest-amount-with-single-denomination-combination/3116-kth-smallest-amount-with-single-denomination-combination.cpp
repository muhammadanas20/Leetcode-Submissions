class Solution {
    private:
    long long gcd(long long a,long long b){
        return b == 0 ? a : gcd(b,a % b);
    }
    long long lcm(long long a,long long b){
       if(a == 0 || b == 0) return 0;
       return (a /gcd(a,b)) * b ;
    }
     // Counts how many valid amounts <= mid can be formed
    long long countAmounts(long long mid, const std::vector<int>& coins) {
        int n = coins.size();
        long long totalCount = 0;

        // Iterate through all possible subsets using bitmasking (excluding the empty subset)
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long currentLcm = 1;
            int bitCount = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bitCount++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    // Break early if LCM exceeds mid to avoid integer overflow
                    if (currentLcm > mid) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            // Inclusion-Exclusion logic
            if (bitCount % 2 == 1) {
                totalCount += mid / currentLcm; // Odd size: add
            } else {
                totalCount -= mid / currentLcm; // Even size: subtract
            }
        }
        return totalCount;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
         // Find the minimum coin value to establish the upper bound
        long long minCoin = *std::min_element(coins.begin(), coins.end());
        
        long long low = 1;
        long long high = minCoin * k;
        long long ans = high;

        // Binary search for the exact kth value
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                ans = mid;       // Found a candidate, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1;   // Not enough amounts, move range higher
            }
        }
        return ans;
    }
};