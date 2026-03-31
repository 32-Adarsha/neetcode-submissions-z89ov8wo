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
    int preorderIndex = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return build(preorder , inorder , 0 , preorder.size()-1); 
    }


    TreeNode* build(vector<int>& preorder , vector<int>& inorder , int start , int end){
        if (start > end) return nullptr;

        TreeNode* node = new TreeNode(preorder[preorderIndex++]);
        auto it = find(inorder.begin() , inorder.end() , node->val);
        int idx = distance(inorder.begin(), it);

        node->left = build(preorder , inorder , start , idx-1);
        node->right = build(preorder , inorder , idx+1 , end);

        return node;

    }
};
