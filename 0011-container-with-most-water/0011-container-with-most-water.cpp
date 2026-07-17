class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
     //two pointer: pointer move left when left or right height is smaller if its equal then left or right choice
        while( left < right){
            int i = height[left];
            int j= height[right];
            int area = min(i,j) * (right - left);

            res = max(res,area);
              
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};