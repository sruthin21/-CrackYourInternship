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
    void rev(ListNode* &head){
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
        head = curr;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        int l = left;
        left--;
        ListNode* n1 = NULL;
        ListNode* temp1 = head;
        while(left>0 && temp1!=NULL){
            n1 = temp1;
            temp1 = temp1->next;
            left--;
        }
        ListNode* temp2 = head;
        right--;
        while(right>0 && temp2!=NULL){
            temp2 = temp2->next;
            right--;
        }
        ListNode* n2 = temp2->next;
        if(l==1){
                head = temp1;
                temp2->next = NULL;
                rev(head);
                 ListNode* tem = temp1;
                ListNode* prev = NULL;
                while(tem!=NULL){
                    prev = tem;
                    tem = tem->next;
                }
                prev->next = n2;
        }
        else{
            n1->next = NULL;
            temp2->next = NULL;
            rev(temp1);
            n1->next = temp1;
            ListNode* tem = temp1;
            ListNode* prev = NULL;
            while(tem!=NULL){
                prev = tem;
                tem = tem->next;
            }
            prev->next = n2;
        }
        
        return head;
    }
};