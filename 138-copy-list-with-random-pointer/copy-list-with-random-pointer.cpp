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
        // Initialization
        map<Node*,Node*> mp;
        Node *curr = head, *ans = new Node(-1), *res = ans;
        mp[NULL] = NULL;
        // Building list with reference pointers as NULL.
        // Storing reference pointer in map.
        while(curr != NULL) {
            ans->next = new Node(curr->val);
            ans = ans->next;
            mp[curr] = ans;
            curr = curr->next;
        }
        // Reinitalize
        curr = head;
        ans = res->next;
        // assigning reference pointer of the list
        while(curr != NULL) {
            ans->random = mp[curr->random];
            curr = curr->next;
            ans = ans->next;
        }
        // Returing head of newly created node.
        return res->next;   
    }
};