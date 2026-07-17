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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
         int k = lists.size();
         //using divide and conquer rule to reduce time complexity to olog n
           while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = merge(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2; // Move the boundary for the next merge step
        }
        return lists[0];
    }
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode dummy(0);
        ListNode* head = &dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                head->next = list1;
                list1 = list1->next;
            }else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if(list1 != nullptr){
            head->next = list1;
        }else{
            head->next = list2;
        }
        return dummy.next;
    }
};