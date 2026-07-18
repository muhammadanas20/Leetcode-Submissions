
// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node* child;
// };

class Solution {
public:
    Node* flatten(Node* head) {
       Node* curr = head;
       while(curr != nullptr){
            if(curr->child != nullptr){
                Node* tail = curr->child;
                while(tail->next != nullptr){
                    tail = tail->next;
                }
                if(curr->next != nullptr){
                     tail->next = curr->next;
                     curr->next->prev = tail;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
       }
       return head;
    }
};