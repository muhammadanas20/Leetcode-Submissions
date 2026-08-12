class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int length = 0;
        unordered_map<int,int> freq;
        int left = 0;

        for(int right = 0;right < nums.size(); right++){
            freq[nums[right]]++;
             // Shrink the window from the left if the current element's frequency exceeds k
            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            // Calculate and update the maximum valid subarray length
            length = std::max(length, right - left + 1);

        }
        return length;

    }
};