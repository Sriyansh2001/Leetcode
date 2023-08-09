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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        ListNode* list1 = head;
        ListNode* list2 = head->next;
        ListNode* even = list2 , *odd = list1;
        bool even_ptr = false;

        while(list1 && list2) {
            if(even_ptr) {
                if(list2->next) {
                    list2->next = list2->next->next;
                }
                list2 = list2->next;
            }    
            else {
                if(list1->next) {
                    list1->next = list1->next->next;
                }
                list1 = list1->next;
            }
            even_ptr = !even_ptr;
        }

        list1 = odd;

        while(list1->next) {
            list1 = list1->next;
        }

        list1->next = even;
        return odd;
    }
};