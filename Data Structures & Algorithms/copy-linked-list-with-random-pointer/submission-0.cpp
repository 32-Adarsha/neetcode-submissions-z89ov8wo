/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
  Node *copyRandomList(Node *head) {

    //  NOTE: mapper to map previous node to its replicate so that it is easy
    //  for random pointer
    std::unordered_map<Node *, Node *> mapper;

    //  NOTE: necessary init for
    Node *tempHead = head;
    Node *newHead = NULL;
    Node *prev = newHead;

    // NOTE: first pass to get all the node and map it to its copy
    while (tempHead != NULL) {
      Node *temp = new Node(tempHead->val);
      mapper[tempHead] = temp;

      if (newHead != NULL) {
        prev->next = temp;
        prev = prev->next;
      } else {
        newHead = temp;
        prev = newHead;
      }

      tempHead = tempHead->next;
    }

    tempHead = head;
    Node *tempNewHead = newHead;
    while (tempHead != NULL) {
      Node *temp = mapper[tempHead->random];
      tempNewHead->random = temp;

      // NOTE: Move to next node in linked list
      tempHead = tempHead->next;
      tempNewHead = tempNewHead->next;
    }

    return newHead;
  }
};