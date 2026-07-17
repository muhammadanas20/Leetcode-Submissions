class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> merged; 
        for(auto num : nums){
            merged.push_back(num);
        }
        for(auto num : nums){
            merged.push_back(num);
        }
        return merged;
    }
};