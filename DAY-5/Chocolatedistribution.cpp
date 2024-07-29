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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* res=nullptr,*cur=nullptr,*temp=nullptr;
        while(list1 && list2){
            if(list1->val<=list2->val){
                temp=list1;
                list1=list1->next;
            } else {
                temp=list2;
                list2=list2->next;
            }
            if(!res) res=cur=temp;
            else {
                cur->next=temp;
                cur=cur->next;
            }
        }

        if(list1) cur->next=list1;
        if(list2) cur->next=list2;

        return res;
    }
};