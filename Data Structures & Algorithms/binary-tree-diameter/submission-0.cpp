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
  int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    recursion(root, diameter);
    return diameter-1;
  }

  int recursion(TreeNode *root, int &diameter) {
    if (root == nullptr)
      return 0;

    int left = recursion(root->left, diameter);
    int right = recursion(root->right, diameter);

    int width = left + right + 1;
    diameter = std::max(diameter, width);

    return std::max(left, right) + 1;
  }
};;
