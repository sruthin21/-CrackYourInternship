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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            if(curr->val==val){
                  if(prev==NULL){
                     curr->next = NULL;
                     head = next;
                     curr = next;
                  }
                  else{
                    prev->next = next;
                    curr = curr->next;
                  }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};