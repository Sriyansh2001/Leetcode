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
    ListNode* reverselist(ListNode* head) {
        ListNode* curr = head, *next = head, *prev = nullptr;

        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        int result = 0;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* headptr = reverselist(slow);

        while(head && headptr) {
            result = max(result,head->val+headptr->val);
            head = head->next;
            headptr = headptr->next;
        }

        return result;
    }
};