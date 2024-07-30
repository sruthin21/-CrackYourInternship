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
    bool check(TreeNode* root1,TreeNode* root2){
        if(root1 ==NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL){
            return false;
        }
        if(root1->left==NULL && root2->right==NULL && root1->right!=NULL && root2->left!=NULL){
                 if(root1->right->val != root2->left->val){
                    return false;
                 }
        }
        else if(root1->left!=NULL && root2->right!=NULL && root1->right==NULL && root2->left==NULL){
                if(root1->left->val != root2->right->val){
                    return false;
                 }
        }
        else if(root1->left==NULL && root2->right==NULL && root1->right==NULL && root2->left==NULL){
            return true;
        }
        else if(root1->left!=NULL && root2->right!=NULL && root1->right!=NULL && root2->left!=NULL){
           if(root1->left->val !=root2->right->val || root1->right->val != root2->left->val){
            return false;
          }
        }
        return check(root1->left,root2->right) && check(root1->right,root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root ==NULL){
            return true;
        }
        if(root->left== NULL && root->right==NULL){
            return true;
        }
        if(root->left==NULL || root->right==NULL){
            return false;
        }
        if(root->left->val != root->right->val){
            return false;
        }

       return check(root->left,root->right);

    }
};