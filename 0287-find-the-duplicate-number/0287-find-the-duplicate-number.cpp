class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //using floyed cycle
        int fast = 0;
        int  slow = 0;

        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow == fast) break;
        }

        fast  = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
      return slow;
    }
};