class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // We need at least 3 nodes to have a critical point
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int first_cp = -1; // Index of the very first critical point
        int prev_cp = -1;  // Index of the previous critical point found
        int min_dist = INT_MAX;
        int index = 1;     // 0-indexed position tracking (head is 0, head->next is 1)

        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            
            // Check for Local Maxima or Local Minima
            bool is_max = (curr->val > prev->val && curr->val > next->val);
            bool is_min = (curr->val < prev->val && curr->val < next->val);

            if (is_max || is_min) {
                if (first_cp == -1) {
                    first_cp = index; // Record the first critical point
                } else {
                    // Update the minimum distance between adjacent critical points
                    min_dist = min(min_dist, index - prev_cp);
                }
                prev_cp = index; // Update the most recent critical point position
            }

            // Move pointers forward safely
            prev = curr;
            curr = next;
            index++;
        }

        // If fewer than two critical points were found
        if (first_cp == prev_cp) {
            return {-1, -1};
        }

        // Maximum distance is always between the very first and the very last critical point
        int max_dist = prev_cp - first_cp;

        return {min_dist, max_dist};
    }
};
