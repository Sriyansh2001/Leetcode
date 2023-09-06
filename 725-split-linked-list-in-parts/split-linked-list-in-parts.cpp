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