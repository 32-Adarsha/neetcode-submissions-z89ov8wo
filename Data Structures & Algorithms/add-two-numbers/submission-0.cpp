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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* head = nullptr;
       ListNode* prev = nullptr;
       int carry = 0;
       while(l1 != nullptr && l2 != nullptr){
            int addition = l1->val + l2->val + carry;
            carry = addition / 10;
            ListNode* temp = new ListNode(addition % 10);
            if(head == nullptr){
                head = temp;
                prev = head;
            } else {
                prev->next = temp;
                prev = temp;
            }

            l1 = l1->next;
            l2 = l2->next;
       } 


       while(l1 != nullptr){
          int addition = l1->val + carry; 
          carry = addition / 10;
          ListNode* temp = new ListNode(addition%10);
          if(head == nullptr){
            head = temp;
            prev = head;
          }else{
            prev->next = temp;
            prev =temp;
          }

          l1 = l1->next;
       }

       while(l2 != nullptr){
          int addition = l2->val + carry; 
          carry = addition / 10;
          ListNode* temp = new ListNode(addition%10);
          if(head == nullptr){
            head = temp;
            prev = head;
          }else{
            prev->next = temp;
            prev =temp;
          }
          
          l2 = l2->next;
       }

       cout<<carry<<endl;
       if(carry != 0){
         ListNode* temp = new ListNode(carry);
         prev->next = temp;
       }


       return head;
    }
};
