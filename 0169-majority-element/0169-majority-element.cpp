class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size()/2;
        for(int num : nums){
            count[num]++;
        }
        for(auto pair:count){
            if(pair.second > n){
                return pair.first;
            }
        }
         return -1; 
    }
};