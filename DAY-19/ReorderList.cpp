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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        int c = 0;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            c++;
        }
        c = c/2;
        temp = head;
        while(c--){
            prev = temp;
            temp = temp->next;
        }
        ListNode* node1 = prev->next;
        prev->next = NULL;
        stack<ListNode*> s;
        ListNode* tem = NULL;
        while(node1!=NULL){
            tem = node1;
            node1 = node1->next;
            tem->next = NULL;
            s.push(tem);
        }
        temp = head;
        ListNode* next = head->next;
        ListNode* p1 = NULL;
        while(!s.empty()){
            ListNode* n = s.top();
            s.pop();
            n->next = temp->next;
            temp->next = n;
            p1 = temp;
            temp = next;
            if(next==NULL){
                break;
            }
            next = next->next;
        }
        if(!s.empty()){
            ListNode* node = s.top();
            p1 = p1->next;
            p1->next = node;
        }
    }
};