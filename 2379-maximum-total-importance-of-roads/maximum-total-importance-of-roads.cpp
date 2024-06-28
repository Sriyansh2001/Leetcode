bool cmp(int a,int b) {
    return a<b;
}

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> g(n);
        int m = roads.size();
        for(int i=0 ; i<m ; ++i) {
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int> ind(n);
        for(int i=0 ; i<n ; ++i) {
            ind[i] = g[i].size();
        }
        unordered_map<int,vector<int>> mp;
        vector<int> check = ind;
        sort(check.begin(),check.end(),cmp);
        for(int i=0 ; i<n ; ++i) {
            mp[check[i]].push_back(i+1);
        }
        vector<bool> vis(n,false);
        priority_queue<vector<int>> q;
        vector<int> ans(n,-1);
        for(int i=0 ; i<n ; ++i) {
            q.push({ind[i],i});
        }
        long long int res=0;
        while(!q.empty()) {
            vector<int> k = q.top();
            q.pop();
            if(ans[k[1]]==-1) {
                int v = ind[k[1]];
                ans[k[1]] = mp[v][mp[v].size()-1];
                mp[v].pop_back();
            }
            vis[k[1]]=true;
            for(auto i:g[k[1]]) {
                if(vis[i]) continue;
                if(ans[i]==-1) {
                    int v = ind[i];
                    ans[i] = mp[v][mp[v].size()-1];
                    mp[v].pop_back();
                }
                res = res+ans[i]+ans[k[1]];
            }
        }      
        return res;
    }
};














