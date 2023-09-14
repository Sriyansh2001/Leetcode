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
        int carry = 0;
        int val;
        ListNode* dump = new ListNode(-1);
        ListNode* temp = dump;
        while(l1 && l2) {
            val = l1->val + l2->val + carry;
            temp->next = new ListNode(val%10);
            carry = val/10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while(l1) {
            val = l1->val+carry;
            temp->next = new ListNode(val%10);
            carry = val/10;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2) {
            val = l2->val+carry;
            temp->next = new ListNode(val%10);
            carry = val/10;
            l2 = l2->next;
            temp = temp->next;
        }
        if(carry) {
            temp->next = new ListNode(1);
        }
        return dump->next;
    }
};