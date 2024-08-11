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
    void  rev(ListNode* &head){
        if(head==NULL || head->next==NULL){
            return;
        }
       ListNode* prev = NULL;
       ListNode* curr = head;
       ListNode* next = head->next;
       while(next!=NULL){
           curr->next = prev;
           prev = curr;
           curr = next;
           next = next->next;
       }
       curr->next = prev;
       prev = curr;
       head = prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        rev(l1);
        rev(l2);
        int carry = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(t1!=NULL && t2!=NULL){
            int num = t1->val+t2->val+carry;
            int sum = num%10;
             carry = num/10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1!=NULL){
            int num = t1->val+carry;
            int sum = num%10;
             carry = num/10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            t1 = t1->next;
        }
        while(t2!=NULL){
            int num = t2->val+carry;
            int sum = num%10;
             carry = num/10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            t2 = t2->next;
        }
        if(carry>0){
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        curr = head->next;
        head->next = NULL;
        head = curr;
        rev(head);
        return head;
    }
};