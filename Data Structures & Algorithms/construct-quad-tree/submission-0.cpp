/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
  Node *construct(vector<vector<int>> &grid) {
    return DivideAndConcure(grid, 0, 0, grid.size());
  }

  Node *DivideAndConcure(vector<vector<int>> &gird, int left, int top,
                         int width) {
    bool varies = false;
    bool initial_value = gird[top][left];
    for (int i = left; i < (left + width); ++i) {
      for (int j = top; j < (top + width); ++j) {
        if (gird[j][i] != initial_value) {
          varies = true;
          break;
        }
      }
      if (varies)
        break;
    }

    if (!varies) {
      return new Node(initial_value, true);
    }


    int half_width = width / 2;
    Node *n = new Node(false, false);

    n->topLeft = DivideAndConcure(gird, left, top, half_width);
    n->topRight = DivideAndConcure(gird, left + half_width, top, half_width);
    n->bottomLeft = DivideAndConcure(gird, left, top + half_width, half_width);
    n->bottomRight =
        DivideAndConcure(gird, left + half_width, top + half_width, half_width);

    return n;
  }
};