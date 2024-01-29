class List{
public:
    int val;
    List *next,*prev;

    List(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class stack1{
    List* head;
    List* tail;
public:
    stack1() {
        head = new List(-1);
    }

    void push(int val) {
        List* link = new List(val);
        head->next = link;
        link->prev = head;
        head = head->next;
    }

    int top() {
        if(head->val == -1) {
            return -1;
        }
        return head->val;
    }

    void pop() {
        if(isempty()) {
            return ;
        }
        head = head->prev;
        delete head->next;
        head->next = NULL;
    }

    bool isempty() {
        return head->val == -1;
    }

    void print() {
        List* temp = head;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->prev;
        } cout << "\n";
    }
};

class MyQueue {
public:
    stack1 s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.isempty()) {
            int result = s2.top();
            s2.pop();
            return result;
        }
        else {
            while(!s1.isempty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int result = s2.top();
            s2.pop();
            return result;
        }
    }

    int peek() {
        if(!s2.isempty()) {
            return s2.top();
        }
        else {
            while(!s1.isempty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.isempty() && s2.isempty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */