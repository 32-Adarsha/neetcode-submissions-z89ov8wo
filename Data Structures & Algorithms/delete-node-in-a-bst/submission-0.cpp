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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) {
      return root;
    }
    cout<<root->val<<endl;

    if (root->val == key) {
      if (!root->left || !root->right) {
        TreeNode *rValue = (root->left) ? root->left : root->right;
        return rValue;
      }

      TreeNode *left = root->left;
      TreeNode *right = root->right;

      while (left->right) {
        left = left->right;
      }

      left->right = right->left;
      right->left = root->left;

      return right;
    }

    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      root->left = deleteNode(root->left, key);
    }

    return root;
  }
};