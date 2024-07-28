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
    private:
    int pow(int n){
        int ans = 1;
        for(int i=1;i<=n;i++){
            ans = ans*2;
        }
        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        count--;
        temp = head;
        int ans = 0;
        while(count>=0){
           if(temp->val==1){
              ans = ans+pow(count);
           }
           temp = temp->next;
           count--;
        }
        return ans;
    }
};