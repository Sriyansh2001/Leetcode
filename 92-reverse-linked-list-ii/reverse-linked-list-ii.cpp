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
    ListNode* reverse(ListNode* head,int times) {
        ListNode* curr=head,*prev=NULL,*next;
        while(curr && times>0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            times-=1;
        }
        head->next = curr;
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = NULL,*curr = head;
        int l = left;
        left-=1;
        while(left > 0) {
            temp = curr;
            curr = curr->next;
            left-=1;
        }
        if(temp) {
            temp->next = reverse(curr,(right-l)+1);
            return head;
        }
        else {
            return reverse(curr,right);
        }
        return NULL;
    }
};