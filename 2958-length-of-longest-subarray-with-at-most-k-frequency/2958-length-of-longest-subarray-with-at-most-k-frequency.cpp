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
// std::unordered_map<int, int> keeps track of element frequencies with an average \(\mathcal{O}(1)\) lookup time.The for loop expands the window by incrementing the right pointer.The while loop maintains the problem's condition by reducing frequencies and moving the left pointer forward.right - left + 1 calculates the size of the current valid subarray sequence