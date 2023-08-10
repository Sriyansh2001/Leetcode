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
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head, *next = head;

        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) {
            return head;
        }

        ListNode* nxt = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return nxt;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        
        ListNode* curr = head, *next = head->next, *root=nullptr;

        while(curr) {
            curr->next = root;
            root = curr;
            curr = next;
            if(curr) next = curr->next;
        }

        return root;
    }
};