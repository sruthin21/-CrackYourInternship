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

public:
    bool leaf(TreeNode* node){
        if(node->left == NULL && node->right==NULL){
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                if(leaf(temp->left)){
                    sum = sum+temp->left->val;
                }
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return sum;
    }
};