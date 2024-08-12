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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int c = 0;
        ListNode* node = head;
        while(node!=NULL){
            c++;
            node = node->next;
        }
        if(c==n){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            return head;
        }
        int num = c-n;
        num--;
        node = head;
        ListNode* next = head->next;
        while(node!=NULL && num>0){
            node = next;
            next = next->next;
            num--;
        }
        node->next = next->next;
        next->next = NULL;
        return head;
    }
};