class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // count[0]: remainders of 0, count[1]: remainders of 1, count[2]: remainders of 2
        vector<int> count(3,0);
        for (int stone : stones){
            count[stone % 3]++;
        }
         // If count of 0-remainder stones is even, Alice wins if both 1s and 2s are available
        if(count[0] % 2 == 0){
            return min (count[1],count[2]) >  0;
        }
                // If count of 0-remainder stones is odd, Alice wins if the absolute difference > 2
        return abs(count[1] - count[2]) > 2;
    }
};