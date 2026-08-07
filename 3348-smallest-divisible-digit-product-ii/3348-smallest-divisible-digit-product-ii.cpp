class Solution {
private:
    // Helper to calculate the counts of digits needed to satisfy remaining prime factors
    void get_min_suffix_counts(int r2, int r3, int r5, int r7, std::vector<int>& counts) {
        r2 = std::max(0, r2);
        r3 = std::max(0, r3);
        r5 = std::max(0, r5);
        r7 = std::max(0, r7);

        counts[7] = r7;
        counts[5] = r5;

        // Group factors of 2 and 3 into the largest possible single digits
        int n8 = r2 / 3;
        int n9 = r3 / 2;
        int rem2 = r2 % 3;
        int rem3 = r3 % 2;

        int n2 = 0, n3 = 0, n4 = 0, n6 = 0;
        if (rem2 == 0 && rem3 == 1) {
            n3 = 1;
        } else if (rem2 == 1 && rem3 == 0) {
            n2 = 1;
        } else if (rem2 == 1 && rem3 == 1) {
            n6 = 1;
        } else if (rem2 == 2 && rem3 == 0) {
            n4 = 1;
        } else if (rem2 == 2 && rem3 == 1) {
            n2 = 1;
            n6 = 1; // 2 and 6 is lexicographically smaller than 3 and 4
        }

        counts[2] = n2;
        counts[3] = n3;
        counts[4] = n4;
        counts[6] = n6;
        counts[8] = n8;
        counts[9] = n9;
    }

    // Helper to build the sorted suffix string from digit counts
    std::string build_suffix(const std::vector<int>& counts) {
        std::string suffix = "";
        for (int d = 2; d <= 9; ++d) {
            suffix.append(counts[d], '0' + d);
        }
        return suffix;
    }

    // Helper to add prime factors of a single digit
    void add_factors(int d, int& f2, int& f3, int& f5, int& f7) {
        if (d == 0) return;
        while (d % 2 == 0) { f2++; d /= 2; }
        while (d % 3 == 0) { f3++; d /= 3; }
        if (d % 5 == 0) f5++;
        if (d % 7 == 0) f7++;
    }

public:
    std::string smallestNumber(std::string num, long long t) {
        // Step 1: Prime factorize t
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (t % 2 == 0) { req2++; t /= 2; }
        while (t % 3 == 0) { req3++; t /= 3; }
        while (t % 5 == 0) { req5++; t /= 5; }
        while (t % 7 == 0) { req7++; t /= 7; }

        if (t > 1) return "-1"; // Contains prime factors other than 2, 3, 5, 7

        int n = num.length();
        
        // Pre-calculate prefix prime factor counts
        std::vector<std::vector<int>> pre(n + 1, std::vector<int>(8, 0)); // indices 2, 3, 5, 7
        int first_zero = -1;

        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i];
            if (num[i] == '0') {
                if (first_zero == -1) first_zero = i;
                continue;
            }
            add_factors(num[i] - '0', pre[i + 1][2], pre[i + 1][3], pre[i + 1][5], pre[i + 1][7]);
        }

        // Case A: Check if num itself is valid and zero-free
        if (first_zero == -1) {
            if (pre[n][2] >= req2 && pre[n][3] >= req3 && pre[n][5] >= req5 && pre[n][7] >= req7) {
                return num;
            }
        }

        // Case B: Try to keep a prefix of length i and increment the digit at position i
        int limit = (first_zero != -1) ? first_zero : n - 1;
        for (int i = limit; i >= 0; --i) {
            int start_digit = (num[i] - '0') + 1;
            for (int d = start_digit; d <= 9; ++d) {
                int r2 = req2 - pre[i][2];
                int r3 = req3 - pre[i][3];
                int r5 = req5 - pre[i][5];
                int r7 = req7 - pre[i][7];

                // Subtract factors of the newly placed digit d
                int temp_d = d;
                while (temp_d % 2 == 0) { r2--; temp_d /= 2; }
                while (temp_d % 3 == 0) { r3--; temp_d /= 3; }
                if (temp_d % 5 == 0) r5--;
                if (temp_d % 7 == 0) r7--;

                std::vector<int> counts(10, 0);
                get_min_suffix_counts(r2, r3, r5, r7, counts);
                
                int suffix_len = 0;
                for (int c : counts) suffix_len += c;

                int rem_space = n - 1 - i;
                if (suffix_len <= rem_space) {
                    std::string ans = num.substr(0, i) + std::to_string(d);
                    ans.append(rem_space - suffix_len, '1'); // Pad with '1's for smallest value
                    ans += build_suffix(counts);
                    return ans;
                }
            }
        }

        // Case C: The output must be strictly longer than len(num)
        int target_len = n + 1;
        while (true) {
            std::vector<int> counts(10, 0);
            get_min_suffix_counts(req2, req3, req5, req7, counts);

            int suffix_len = 0;
            for (int c : counts) suffix_len += c;

            if (suffix_len <= target_len) {
                std::string ans = "";
                ans.append(target_len - suffix_len, '1');
                ans += build_suffix(counts);
                return ans;
            }
            target_len++;
        }
    }
};