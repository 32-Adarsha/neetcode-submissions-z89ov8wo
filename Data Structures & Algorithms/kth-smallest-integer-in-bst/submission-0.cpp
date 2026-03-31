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
 
struct result {
    bool found;
    int curr;
    int value;
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        result r =  {false , 0 , -1};
        result res = kSmall(root , r , k );
        return res.value;
    }

    result kSmall(TreeNode* node , result r , int k){
        if(!node) return r;

        result l = kSmall(node->left , r , k);

        if (l.found) return l;

        l.curr++;

        if (l.curr == k) return {true , l.curr , node->val} ;


        result t = kSmall(node->right , l , k);


        return t; 
        
    }
   
};
