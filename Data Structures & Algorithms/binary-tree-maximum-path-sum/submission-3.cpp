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
    int maxValue = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
      maxSumPath(root);
      return maxValue;
    }

    int maxSumPath(TreeNode* root){
       
        if(!root) {
           
            return 0;
        }
    
        int left = maxSumPath(root->left);
        

        int right = maxSumPath(root->right);
       
     
        int currMax = max(left + root->val + right , max(left + root->val , max(right+root->val , root->val)));
      
       
        maxValue = max(currMax , maxValue);
      
        return root->val + max(left  , max(right , 0));
        
    }
};
