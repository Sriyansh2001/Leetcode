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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 0;
        while(temp) {
            temp = temp->next;
            size+=1;
        }
        vector<ListNode*> ans;
        int dis,extra;
        if(size >= k) {
            dis = size/k;
            extra = size%k;
        }
        else {
            int last = 0;
            while(head) {
                ans.push_back(head);
                head = head->next;
                ans[last]->next = NULL;
                last+=1;
                k-=1;
            }
            while(k--) {
                ans.push_back(NULL);
            } 
            return ans;
        }
        int sz;
        while(head) {
            sz = dis;
            ans.push_back(head);
            while(head && --sz) {
                head = head->next;
            }
            if(extra && head) {
                head = head->next;
                extra-=1;
            }
            ListNode* temp = head;
            if(head) head = head->next;
            if(temp) temp->next = NULL;
        }
        return ans;
    }
};


class Solution {
    int size_of(ListNode *head) {
        int len = 0;
        while(head) {
            head = head->next;
            ++len;
        }
        return len;
    }

    vector<ListNode*> assign_directly(ListNode* head,int k) {
        vector<ListNode*> result;
        int last = 0;
        while(head) {
            result.push_back(head);
            head = head->next;
            result[last]->next = NULL;
            --k; ++last;
        }
        while(k--) {
            result.push_back(NULL);
        }
        return result;
    }

    vector<ListNode*> compute_using_logics(ListNode* head, int k, int size) {
        int diff = size/k, extra = size%k, len;
        ListNode* temp;
        vector<ListNode*> result;
        while(head) {
            result.push_back(head);
            len = diff;
            while(head && --len) {
                head = head->next;
            }
            if(extra) {
                head = head->next;
                --extra;
            }
            temp = head;
            if(head) head = head->next;
            if(temp) temp->next = NULL;
        }
        return result;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = size_of(head);
        if(size > k) {
            return compute_using_logics(head, k, size);
        }
        return assign_directly(head, k);
    }
};