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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = assign_node(head,x);
        return solve_partition(head,x,curr);
    }
private:
    ListNode* solve_partition(ListNode* head,int x,ListNode* curr) {
        ListNode *answer = head, *prev = nullptr;
        if(curr != nullptr) {
            head = curr->next;
            prev = curr;
        }

        while(head != nullptr) {
            if(head->val < x) {
                if(curr == nullptr) {
                    prev->next = head->next;
                    curr = head;
                    curr->next = answer;
                    answer = head;
                    head = prev->next;
                }
                else {
                    prev->next = head->next;
                    head->next = curr->next;
                    curr->next = head;
                    head = prev->next;
                    curr = curr->next;
                }
            }
            else {
                prev = head;
                head = head->next;
            }
        }

        return answer;
    }

    ListNode* assign_node(ListNode* head,int x) {
        ListNode* curr = head, *prev = nullptr;
        while(curr != nullptr && curr->val < x) {
            prev = curr;
            curr = curr->next;
        }
        return prev;
    }
};