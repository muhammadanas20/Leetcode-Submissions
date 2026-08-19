

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        // Map row_number -> bitmask of reserved seats (for seats 2 to 9)
        std::unordered_map<int, int> row_masks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                // Shift bit by (col - 2) to build a mask for seats 2-9
                row_masks[row] |= (1 << (col - 2));
            }
        }
        
        // Assume initially that all n rows can host 2 families
        int max_families = n * 2;
        
        // Binary masks corresponding to the 3 valid blocks across seats 2 to 9
        // Index mapping: Seat 2 -> bit 0, Seat 3 -> bit 1,., Seat 9 -> bit 7
        int left_mask  = 0b00001111; // Seats 2, 3, 4, 5
        int right_mask = 0b11110000; // Seats 6, 7, 8, 9
        int mid_mask   = 0b00111100; // Seats 4, 5, 6, 7
        
        for (const auto& [row, mask] : row_masks) {
            bool left_blocked  = (mask & left_mask) != 0;
            bool right_blocked = (mask & right_mask) != 0;
            bool mid_blocked   = (mask & mid_mask) != 0;
            
            int lost = 0;
            
            if (left_blocked && right_blocked && mid_blocked) {
                lost = 2; // Completely blocked
            } else if (left_blocked && right_blocked) {
                lost = 1; // Only mid is available, lost 1 spot
            } else if (left_blocked || right_blocked) {
                lost = 1; // One side is blocked, the other is open, lost 1 spot
            }
            
            max_families -= lost;
        }
        
        return max_families;
    }
};
