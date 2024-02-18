class comp {
public:
    bool operator()(vector<long> &a,vector<long> &b) {
        if(a[0] == b[0]) return a[1]>b[1];
        if(a[0]<b[0]) return false;
        return true;
    }
};

class com {
public:
    bool operator()(int a,int b) {
        return a>b;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<vector<long>,vector<vector<long>> ,comp > busy;
        priority_queue<int,vector<int>,com> free;
        vector<long> used(n,0);
        int m = meetings.size();

        for(int i=0 ; i<n ; ++i) {
            free.push(i);
        }
        long mx = 0;
        
        for(int i=0 ; i<m ; ++i) {
            while(!busy.empty() && busy.top()[0] <= meetings[i][0]) {
                free.push(busy.top()[1]);
                busy.pop();
            }
            if(!free.empty()) {
                busy.push({meetings[i][1],free.top()});
                used[free.top()]++;
                mx = max(used[free.top()],mx);
                free.pop();
            }
            else {
                long val = meetings[i][1]-meetings[i][0];
                int u = busy.top()[1];
                long c = val + busy.top()[0];
                busy.pop();
                busy.push({c,u});
                used[u]++;
                mx = max(used[u],mx);
            }
        }
        
        for(int i=0 ; i<m ; ++i) {
            if(used[i] == mx) return i;
        }
        return 0;
    }
};