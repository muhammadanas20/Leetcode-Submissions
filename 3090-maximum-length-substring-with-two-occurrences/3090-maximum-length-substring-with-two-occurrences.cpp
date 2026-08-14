class Solution {
public:
    int maximumLengthSubstring(string s) {
        //sliding window pattern
        int left = 0;
        int max_length = 0;
        vector<int>freq(26,0);
        for(int right = 0; right < s.length(); right++){
              freq[s[right] - 'a']++; //count occurance

              while(freq[s[right] - 'a'] > 2){
                freq[s[left] - 'a']--;  //remoe from left shrinks window
                left++; //move left pointer to next
              }

              max_length = max(max_length,right - left + 1); // update to find max substring length

        }
        return max_length;
    }
};