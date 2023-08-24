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
    // Check wheater the current list has k nodes or not.
    bool possible(ListNode* head,int k) {
        while(head && k) {
            head = head->next;
            k-=1;
        }
        return k==0;
    }

    // Function to reverse the k-list.
    ListNode* reverselist(ListNode* head,int k) {
        if(head == nullptr) {
            return nullptr;
        }
        // Check wheater list has k nodes or not.
        if(!possible(head,k)) {
            return head;
        }
        // Initialization of pointers.
        ListNode* curr=head,*prev=nullptr,*next=nullptr;
        int t = k;
        // Reverse k nodes.
        while(curr && k) {
            k-=1;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Calling same function for remaining values of list
        // and store it into the next of current list.
        head->next = reverselist(curr,t);
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Calling the function that contain logic.
        return reverselist(head,k);
    }
};