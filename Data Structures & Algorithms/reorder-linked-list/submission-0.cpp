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
    void reorderList(ListNode* head) {
        ListNode* mid = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            mid = mid->next;
            fast = fast->next->next;
        }

        // Now I am going to reverse form the mid;
        fast = mid->next;
        mid->next = nullptr;
        while(fast){
            ListNode *temp = fast->next;
            fast->next = mid->next;
            mid->next = fast;
            fast = temp;
        }

        fast = mid->next;
        mid->next = nullptr;
        mid = head;

        while(fast){
            ListNode *temp = mid->next;
            ListNode *temp2 = fast->next;
            fast->next = temp;
            mid->next = fast;
            fast = temp2;
            mid = temp; 
        }
         


    

    }
};
