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
  ListNode *reverseKGroup(ListNode *head, int k) {
    cout<<"Here"<<endl;
    ListNode *start = new ListNode(-1);
    start->next = head;

    ListNode *tail = start;
    ListNode *lastHead = start;
    int count = k;

    while (tail->next) {
      tail = tail->next;
      count--;
      if (count == 0) {
        lastHead = reverseK(lastHead, tail);
        tail = lastHead;
        count = k;
      }
    }

    
    return start->next;
  }

  ListNode *reverseK(ListNode *front, ListNode *back) {
    ListNode *start = front;
    ListNode *returnValue = front->next;
    front = front->next;
    start->next = (back != nullptr)? back->next : nullptr;
    back->next = nullptr;
    stack<int> s;
    while (front) {
      ListNode *temp = front->next;
      front->next = start->next;
      start->next = front;
      s.push(front->val);
      front = temp;
    }

    while(!s.empty()){
        cout<< s.top() << " ";
        s.pop();
    }
    
    return returnValue;
  }
};