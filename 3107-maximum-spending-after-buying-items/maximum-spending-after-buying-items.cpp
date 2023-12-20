class cmp {
    public:
    bool operator()(vector<int> &a,vector<int> &b) {
        return a[0]>b[0];
    }
};

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int n = values.size();
        int m = values[0].size();
        priority_queue<vector<int>,vector<vector<int>> , cmp> q;
        long long d = 1,ans=0;

        for(int i=0 ; i<n ; ++i) {
            q.push({values[i][m-1],i,m-1});
        }

        while(!q.empty()) {
            vector<int> k = q.top(); q.pop();
            long long val = k[0];
            int ind1 = k[1];
            int ind2 = k[2]-1;
            if(ind2 >= 0) {
                q.push({values[ind1][ind2],ind1,ind2});
            }
            ans = ans + values[ind1][ind2+1] * d;
            d+=1;
        }
        return ans;
    }
};