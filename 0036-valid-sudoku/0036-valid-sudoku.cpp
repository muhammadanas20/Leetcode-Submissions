class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Check all rows
        for(int row = 0; row < 9; row++){
            unordered_set<char> seen;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.') continue;
                if(seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
        }
        
        // 2. Check all columns
        for(int col = 0; col < 9; col++){
            unordered_set<char> seen;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.') continue;
                if(seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
        }
        
        // 3. Check all 3x3 boxes
        // 'square' ranges from 0 to 8, indexing the nine 3x3 sub-grids from top-left to bottom-right.
        for(int square = 0; square < 9; square++){
            unordered_set<char> seen;
            
            // 'i' and 'j' represent the local row and column indexes (0, 1, or 2) inside a single 3x3 box.
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    
                    /* 
                       FORMULA EXPLANATION FOR ROW:
                       - (square / 3) determines the vertical block position of the box (0, 1, or 2).
                         - Boxes 0, 1, 2 -> 0
                         - Boxes 3, 4, 5 -> 1
                         - Boxes 6, 7, 8 -> 2
                       - Multiplying by 3 shifts this block position to the actual starting global row index (0, 3, or 6).
                       - Adding 'i' moves down to the specific row within that 3x3 box.
                    */
                    int row = (square / 3) * 3 + i;
                    
                    /* 
                       FORMULA EXPLANATION FOR COLUMN:
                       - (square % 3) determines the horizontal block position of the box (0, 1, or 2).
                         - Boxes 0, 3, 6 -> 0
                         - Boxes 1, 4, 7 -> 1
                         - Boxes 2, 5, 8 -> 2
                       - Multiplying by 3 shifts this block position to the actual starting global column index (0, 3, or 6).
                       - Adding 'j' moves right to the specific column within that 3x3 box.
                    */
                    int col = (square % 3) * 3 + j;
                    
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
