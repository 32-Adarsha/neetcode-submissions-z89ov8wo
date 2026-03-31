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

#include <sstream>

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       queue<TreeNode*> q;
       vector<string> result;

       if(root) q.push(root);

       while(q.size()>0){
        TreeNode* front = q.front();
        q.pop();
        if(front){
            q.push(front->left);
            q.push(front->right);
            
        }

        if(!front){
            result.push_back("null");
        } else {
            result.push_back(to_string(front->val));
        }

       }  
       string s  = "";
       int t = result.size()-1;
       while(t>= 0 && result[t]=="null"){
            t--;
       };
       
       for(int i = 0 ; i <= t ; i++){
            if(i == 0){
                s += result[i];
            }else{
                s +=","+result[i];
            }
       };
       return s;





    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        

       // converting the stirng to array of vector
       if (data == "") return nullptr;
       vector<string> bArray;
       stringstream ss(data);
       string token;
       while(getline(ss , token , ',')){
           bArray.push_back(token);
       };
       

       queue<TreeNode*> q;
       TreeNode* head = new TreeNode(stoi(bArray[0]));
       q.push(head);
       int tracker = 1;
       while(tracker < bArray.size() && q.size() > 0){
            int length = q.size();
            TreeNode* root = q.front() ; q.pop();
            
               for(int j = 0 ; j < 2 ; j++){
                 if( bArray.size() <= tracker) break;
                 string value = bArray[tracker];
                
                 if(value == "null") {
                    (j == 0) ? root->left = nullptr : root->right = nullptr;
                 } else {
                    TreeNode* temp = new TreeNode(stoi(bArray[tracker]));
                    (j == 0) ? root->left = temp : root->right = temp;
                    q.push(temp);
                 }
                 tracker++;
               }
            
       };







       
       return head; 
    }
};
