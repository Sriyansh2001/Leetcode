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
        struct ListNode* ans = head;
        int total = 0;
        struct ListNode *temp = head;
        while(temp!=NULL){
            total++;
            temp = temp->next;
        }
        temp = head;
        total = total-n;
        if(total==0){
            return head->next;
        }
        while(total){
            temp = head;
            head = head->next;
            total--;
        }
        if(head==NULL){
            return ans;
        }else{
            temp->next = head->next;
        }return ans;
    }
};