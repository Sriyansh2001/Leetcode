class Solution {
public:
    void findMinPath(vector<vector<int>> &g,int final, int source, vector<int> &dis) {
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int value = q.front();
                q.pop();
                if(value == final) {
                    return;
                }
                for(auto j:g[value]) {
                    if(dis[value] + 1 < dis[j]){
                        dis[j] = dis[value] + 1;
                        q.push(j);
                    }
                }
            }
        }
        return ;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        vector<int> dis(n, 0);
        vector<vector<int>> g(n);
        for(int i=0 ; i<n ; ++i) {
            dis[i] = i;
            if(i != n-1) {
                g[i].push_back(i+1);
            }
        }
        int ind = 0;
        for(auto i:queries) {
            int u = i[0];
            int v = i[1];
            g[u].push_back(v);
            findMinPath(g,n-1,u,dis);
            ans[ind] = dis[n-1];
            ind++;
        }
        return ans;
    }
};