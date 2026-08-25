class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // using uorderd set set 

        unordered_set<int> set(nums.begin(),nums.end());

        long long curr_multiple = k;

        while(true){
            if(set.find(curr_multiple) == set.end()){
                //if not found in set then it should return current mulitple otherwise move to next  (Note when not found in set return addres of end pointer of set )
                return curr_multiple;
            }
            curr_multiple += k;
        }
    }
};