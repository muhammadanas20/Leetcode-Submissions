/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //using hash set easiest approach
        unordered_set<ListNode*> seen;
        for(ListNode* x = head;x != nullptr ; x = x->next){
            if(seen.count(x)){
                return true;
            }else{
                seen.insert(x);
            }
        }
        return false;
    }
};