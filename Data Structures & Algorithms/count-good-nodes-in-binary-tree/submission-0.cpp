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
  int goodNodes(TreeNode *root) {
    if (!root)
      return 0;
    int count = 1;
    dfs(root->left, root->val, count);
    dfs(root->right, root->val, count);
    return count;
  }

  void dfs(TreeNode *root, int maximum, int &count) {
    if (root == nullptr)
      return;

    if (root->val >= maximum)
      count++;
    dfs(root->left, std::max(maximum, root->val), count);
    dfs(root->right, std::max(maximum, root->val), count);
  }
};
