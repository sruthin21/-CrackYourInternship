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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(l1!=NULL && l2!=NULL){
            int num = l1->val+l2->val+carry;
           int sum = num%10;
            carry = num/10;
            curr -> next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2-> next;
        }
        while(l2!=NULL){
            int num = l2->val+carry;
           int sum = num%10;
            carry = num/10;
            curr->next = new ListNode(sum);
             curr = curr->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int num = l1->val+carry;
            int sum = num%10;
            carry = num/10;
            curr->next = new ListNode(sum);
             curr = curr->next;
            l1 = l1->next;
        }
        if(carry>0){
            curr -> next = new ListNode(carry);
        }
        return head->next;
    }
};