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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *temp2 = new ListNode(0);
        temp2->next = head;
        int i = 1;

        while(temp){

            if(i >= n+1){
                temp2 = temp2->next;
            }

            temp = temp->next;
            i++;
        }

        if(temp2->next == head){
            return head->next;
        }
        
        temp2->next = temp2->next->next;

        return head;

    }
};
