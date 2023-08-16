class linklist {
public:
    int val;
    linklist *next;
    linklist *prev;

    linklist() {
        this->next = nullptr;
        this->prev = nullptr;
    }
    linklist(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class dequee {
private:
    linklist *head,*tail;
    int space;
public:
    dequee() {
        space = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool pushfront(int val) {
        linklist *new_node = new linklist(val);
        if(head == nullptr) {
            head = new_node;
            tail  = new_node;
        }
        else {
            new_node->next = head;
            head -> prev = new_node;
            head = new_node;
        }
        space+=1;
        return true;
    }

    bool popfront() {
        if(head == nullptr) {
            return false;
        }
        linklist* old_node = head;
        head = head->next;

        if(head == nullptr) tail = nullptr;
        else head->prev = nullptr;

        delete old_node;
        space-=1;
        return true;
    }

    bool pushback(int val) {
        linklist *new_node = new linklist(val);
        if(tail == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        space+=1;
        return true;
    }

    bool popback() {
        if(tail == nullptr) {
            return false;
        }
        linklist *old_node = tail;
        tail = tail->prev;
        
        if(tail == nullptr) head = nullptr;
        else tail->next = nullptr;
        
        delete old_node;
        space-=1;
        return true;
    }

    int front() {
        if(head == nullptr) return -1;
        return head->val;
    }

    int back() {
        if(tail == nullptr) return -1;
        return tail->val;
    }

    int size() {
        return space;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        dequee q;
        int n = nums.size();
        int *arr = (int*)malloc((n-k+1)*sizeof(int));
        int ptr = 0;
        for(int i=0 ; i<k ; ++i) {
            while(q.size() && q.back() < nums[i]) {
                q.popback();
            }
            q.pushback(nums[i]);
        } 
        arr[ptr] = q.front();
        ptr+=1;
        for(int i=k ; i<n ; ++i) {
            if(nums[i-k] == q.front()) {
                q.popfront();
            }
            while(q.size() && q.back() < nums[i]) {
                q.popback();
            }
            q.pushback(nums[i]);
            arr[ptr] = q.front();
            ptr+=1;
        }
        vector<int> res;
        for(int i=0 ; i<n-k+1 ; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
};