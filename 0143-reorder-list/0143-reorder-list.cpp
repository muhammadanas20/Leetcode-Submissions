/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        //store the second list head
        ListNode* second = slow->next;
        //reverse the second by split it first
        slow->next = nullptr;
        ListNode* prev = nullptr; //for reverse
        while(second != nullptr){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode* first = head;
        second = prev;
    //merging list  alternatively first ad second
        while(second != nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
        
    }
};