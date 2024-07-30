/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool check(TreeNode* root,int sum,int target){
        if(sum == target && root->left==NULL && root->right==NULL){
            return true;
        }
      
        int ans = sum;
        bool flag1 = false;
        bool flag2 = false;
        if(root->left!=NULL){
             sum = sum+root->left->val;
             flag1 = check(root->left,sum,target);
        }
        if(root->right!=NULL){
             ans = ans+root->right->val;
            flag2 = check(root->right,ans,target);
        }
        return flag1 || flag2;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        int sum = root->val;
        return check(root,sum,targetSum);
    }
};