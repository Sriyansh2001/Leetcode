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


class Solution {
    // Calculate the length of LinkedList.
    int lengthof(ListNode* head) {
        int size = 0;
        while(head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* reverselist(ListNode* head,int k,int size) {
        if(head == nullptr) {
            return nullptr;
        }
        // Initialization.
        ListNode *start=nullptr, *end=nullptr, *tstart=nullptr, *tend=nullptr;
        ListNode *ptr=nullptr;
        // Run a loop to reverse in k groups.
        while(size >= k) {
            int tsize = k;
            while(tsize--) {
                ptr = head->next;
                head->next = nullptr;
                if(tstart == nullptr) {
                    tstart = head;
                    tend = head;
                }
                else {
                    head->next = tstart;
                    tstart = head;
                }
                head = ptr;
            }
            size -= k;
            if(start == nullptr) {
                start = tstart;
                end = tend;
            }
            else {
                end->next = tstart;
                end = tend;
            }
            tstart = nullptr;
            tend = nullptr;
        }
        end->next = ptr;
        return start;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = lengthof(head);
        return reverselist(head,k,size);
    }
};