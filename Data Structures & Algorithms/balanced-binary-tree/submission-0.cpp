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
  bool isBalanced(TreeNode *root) {
    std::pair<int, bool> result = dfs(root);
    return result.second;
  }

  std::pair<int, bool> dfs(TreeNode *root) {
    if (root == nullptr)
      return {0, true};

    std::pair<int, bool> left = dfs(root->left);
    std::pair<int, bool> right = dfs(root->right);

    if (left.second && right.second) {
      int diff = abs(left.first - right.first);
      return {std::max(left.first, right.first) + 1, (diff > 1) ? false : true};
    }

    return {0, false};
  }
};
