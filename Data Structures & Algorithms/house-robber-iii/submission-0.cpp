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
  int rob(TreeNode *root) {
    auto result = dfs(root);
    return std::max(result.first, result.second);
  }

  std::pair<int, int> dfs(TreeNode *root) {
    if (!root) {
      return {0, 0};
    }

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    std::pair<int, int> mid = {root->val + left.second + right.second,
                               std::max(left.first, left.second) +
                                   std::max(right.first, right.second)};

    return mid;
  }
};