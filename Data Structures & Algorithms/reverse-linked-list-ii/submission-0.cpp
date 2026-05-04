/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *root = new ListNode();
    root->next = head;
    ListNode *prev = root;
    ListNode *temp = head;
    int pos = 1;
    while (temp) {
      if (pos == left) {
        prev->next = reverse(right - left + 1, temp);
        break;
      }
      prev = temp;
      temp = temp->next;
      pos++;
    }

    return root->next;
  }

  ListNode *reverse(int count, ListNode *node) {
    ListNode *root = nullptr;
    ListNode *tail = node;
    int i = 0;
    while (node && i < count) {
      ListNode *temp_next = node->next;
      node->next = root;
      root = node;
      node = temp_next;
      i++;
    }

    tail->next = node;
    return root;
  }
};