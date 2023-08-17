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

class Solution1 {
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


class Solution {
    Node* createNode(Node* head) {
        Node *temp = head, *node;
        while(temp) {
            node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }
        return head;
    }

    Node* setRandom(Node* head) {
        Node *temp = head, *node;
        while(head) {
            if(head->random != nullptr) {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        return temp;
    }

    Node* seperateList(Node* head) {
        Node *temp = head, *node, *res = head->next;
        while(head) {
            node = head->next;
            head->next = head->next->next;
            head = head->next;
            if(head) {
                node->next = head->next;
                node = node->next;
            }
        }
        return res;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* node = createNode(head);
        node = setRandom(head);
        node = seperateList(head);
        return node;
    }
};