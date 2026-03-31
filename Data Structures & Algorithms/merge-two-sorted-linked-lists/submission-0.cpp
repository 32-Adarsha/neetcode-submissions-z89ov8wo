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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode *tracker = new ListNode();
       ListNode *head = tracker;
       while(list1 && list2){
            if(list1->val <= list2->val){
                ListNode *temp = list1->next;
                list1->next = tracker->next;
                tracker->next = list1;
                list1 = temp;
                tracker = tracker->next;
            } else {
                ListNode *temp = list2->next;
                list2->next = tracker->next;
                tracker->next = list2;
                list2 = temp;
                tracker = tracker->next;
            }
       }

       while(list1){
            ListNode *temp = list1->next;
            list1->next = tracker->next;
            tracker->next = list1;
            list1 = temp;
            tracker = tracker->next;
       } 

       while(list2){
         ListNode *temp = list2->next;
                list2->next = tracker->next;
                tracker->next = list2;
                list2 = temp;
                tracker = tracker->next;
       }

       return head->next;
    }
};
