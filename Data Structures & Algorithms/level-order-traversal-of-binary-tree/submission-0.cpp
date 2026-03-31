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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> result;
       queue<TreeNode*> treeStack;

       if(root){
         treeStack.push(root);
       }

       while(!treeStack.empty()){
          vector<int> temp_holder;   
          cout<<treeStack.size()<<endl; 
          int length = treeStack.size() - 1;
          for(int i = 0 ; i <= length ; ++i) {
            TreeNode *top = treeStack.front();
            treeStack.pop();
            temp_holder.push_back(top->val);
            if(top->left) {
                cout<<top->left->val<<endl;
               treeStack.push(top->left); 
            } 
            if(top->right) {
                cout<<top->right->val<<endl;
                treeStack.push(top->right); 
            }
          }

          result.push_back(temp_holder);


       } 

        return result;



    }
};
