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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = nullptr;
        for(ListNode *l : lists){
            result = mergeTwo(result ,l );
        }

        return result;
    }

    ListNode* mergeTwo(ListNode *first , ListNode *second){
        ListNode *head= new ListNode();
        ListNode *temp = head;
        while(first && second){
            if(first->val <= second->val ){
                ListNode *temp2 = first->next;
                first->next = temp->next;
                temp->next = first;
                first = temp2;
                temp = temp->next;
            } else {
                ListNode *temp2 = second->next;
                second->next = temp->next;
                temp->next = second;
                second = temp2;
                temp = temp->next;
            }
        }

        if(first){
            temp->next = first;
        }

        if(second){
            temp->next = second;
        }

        return head->next;
    }

    
};
