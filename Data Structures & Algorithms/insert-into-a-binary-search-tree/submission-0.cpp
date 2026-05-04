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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(!root){
         return new TreeNode(val);
       }
         
       TreeNode* temp = root;
       TreeNode* prev = nullptr;
       bool LeftBranch = false;
       while(temp){
          if(val < temp->val){
             prev = temp;
             temp = temp->left;
             LeftBranch = true;
          }else {
             prev = temp;
             temp = temp->right;
             LeftBranch = false;
          }
       } 

      if(LeftBranch){
         prev->left = new TreeNode(val);
      }else{
        prev->right = new TreeNode(val);
      } 

      return root;

    }
};