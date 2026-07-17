class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // Step 1: Find the middle using tortoise and hare approach
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr; // Explicitly initialized to avoid garbage memory
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: Compare the first half and the reversed second half
        ListNode* left = head;
        ListNode* right = prev; // 'prev' is now the head of the reversed second half
        
        while (right != nullptr) { // Only need to check until the end of the second half
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};