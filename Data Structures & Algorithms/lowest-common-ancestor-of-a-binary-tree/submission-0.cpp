/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
TreeNode* result = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findCommon(root , p , q);        
        return result;
    }

    pair<bool , bool> findCommon(TreeNode* root ,TreeNode* p , TreeNode* q){
        if(!root){
            return {false , false};
        }

        pair<bool , bool> temp = {false , false};
        auto left = findCommon(root->left ,  p , q);
        auto right = findCommon(root->right , p , q);

        if(result != nullptr){
            return {true , true};
        }

        if(root == p){
            temp.first = true;
        }

        if(root == q){
            temp.second = true;
        }
        
        temp.first = left.first || right.first || temp.first;
        temp.second = left.second || right.second || temp.second;

        if(temp.first && temp.second){
            result = root;
        }

        return temp;
        
    }
     
};