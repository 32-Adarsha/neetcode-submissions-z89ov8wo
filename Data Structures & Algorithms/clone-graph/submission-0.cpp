/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> visited; 
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* root = new Node(node->val);
        visited[node] = root;
        for( Node* neighborsNode : node->neighbors){
            if (visited.find(neighborsNode) == visited.end()){
                Node* rtn_Node = cloneGraph(neighborsNode);
                root->neighbors.push_back(rtn_Node);
            } else {
                root->neighbors.push_back(visited[neighborsNode]);
            } 
        }  
        return root;
    }
};
