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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(!root && !subRoot){
        return true;
       }

       if(!root){
        return false;
       }
        bool temp = false;
       if(root->val == subRoot->val){
            temp = isSameTree(root ,subRoot);
            
       }

       if(temp) return true;

       bool left = isSubtree(root->left , subRoot);
       bool right = isSubtree(root->right , subRoot);


       return left || right;


    }

    bool isSameTree(TreeNode *p , TreeNode *q){
        if(!p && !q){
            return true;
        }

        if(!p || !q || p->val != q->val){
            return false;
        }

        bool left = isSameTree(p->left ,q->left);
        bool right = isSameTree(p->right , q->right);

        return left && right;
    }
};
