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
    void deleteNode(ListNode* node) {

        if(node->next==NULL){
            return;
        }

        ListNode* prev=node;
        ListNode* curr=node->next;
        ListNode*next_next=node->next->next;

        prev->val=curr->val;

        prev->next=next_next;

        delete curr;

        return;


        
    }
};