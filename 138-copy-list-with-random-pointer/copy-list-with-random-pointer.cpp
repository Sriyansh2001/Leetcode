/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        map<Node*,Node*> mp;
        Node* curr = head;
        Node* ans = new Node(-1);
        Node* res = ans;
        mp[NULL] = NULL;
        while(curr != NULL) {
            ans->next = new Node(curr->val);
            ans = ans->next;
            mp[curr] = ans;
            curr = curr->next;
        }
        curr = head;
        ans = res->next;
        while(curr != NULL) {
            ans->random = mp[curr->random];
            curr = curr->next;
            ans = ans->next;
        }
        return res->next;
    }
};