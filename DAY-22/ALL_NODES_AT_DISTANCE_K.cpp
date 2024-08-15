/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void help(unordered_map<TreeNode*,TreeNode*> &map,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                map[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                map[node->right] = node;
                q.push(node->right);
            }
        }
    } 

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> map;
        help(map,root);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        int dis = 0;
        while(!q.empty()){
            if(dis==k){
                    break;
            } 
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){
                      if(!vis[node->left]){
                        q.push(node->left);
                        vis[node->left]=true;    
                      }      
                }
                if(node->right!=NULL ){
                    if(!vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                    }
                }
                if(map.find(node) != map.end()){
                    if(!vis[map[node]]){
                       q.push(map[node]);
                       vis[map[node]]=true;
                    }
                }
            }
            dis++;
        }
        vector<int> ans;
        while(!q.empty()){
           TreeNode* node = q.front();
           q.pop();
           ans.push_back(node->val);
        }
        return ans;
    }
};