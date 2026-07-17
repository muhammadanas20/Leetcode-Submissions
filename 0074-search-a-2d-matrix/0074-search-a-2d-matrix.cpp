class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int h = (rows*cols) - 1;

        while(l <= h){
            int mid = l +(h - l)/2;

            int r = mid/cols;
            int c = mid%cols;

            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] < target){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        return false;
    }
};