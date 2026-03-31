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
  std::vector<int> rightSideView(TreeNode *root) {

    std::deque<TreeNode *> dq;
    std::vector<int> result;

    if(!root) return {}; 

    // EXPLAIN: pushe the root;
    dq.push_back(root);

    while (!dq.empty()) {

      // EXPLAIN: push the last TreeNode of that level
      result.push_back(dq.back()->val);

      // EXPLAIN: Repeat until we exaust all element of that level
      int s = dq.size();
      for (int i = 0; i < s ; ++i) {
        TreeNode *poped = dq.front();
        dq.pop_front();
        if (poped->left != nullptr){
          dq.push_back(poped->left);
          //cout<<dq.back()->val<<" ";
        } 
        if (poped->right != nullptr){
          dq.push_back(poped->right);
          //cout<<dq.back()->val<<" ";
        }
        
      }
      cout<<endl;
    }

    return result;
  }
};
