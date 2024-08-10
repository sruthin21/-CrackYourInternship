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
    ListNode* reverse(ListNode* &head){
        if(head==NULL || head->next==NULL) return head;
         ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;
        while(curr!=NULL){
            if(next==NULL){
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            else{
                  curr->next = prev;
                    prev = curr;
                    curr = next;
                    next = next->next;
            }
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        } 
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
        }
        ListNode* temp1 = head;
        prev->next = reverse(slow);
        ListNode* temp2 = prev->next;
        ListNode* temp = prev->next;
        while(temp1!=temp && temp2!=NULL){
            if(temp1->val == temp2->val){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};