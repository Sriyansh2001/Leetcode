class Solution {
public:
    vector<int> toposort(vector<vector<int>> &g,vector<int> &vis,int res) {
        int n = g.size();
        queue<int> q;
        
        for(int i=0 ;  i<n ; ++i) {
            if(vis[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int k = q.front(); q.pop();
            ans.push_back(k);
            for(auto i:g[k]) {
                vis[i]-=1;
                if(vis[i] == 0) {
                    q.push(i);
                }
            }
        }

        if(ans.size()!=res) return {}; return ans;
    }

    // vector<int> solve(int n,vector<vector<int>> &beforeItems,vector<int> &group,int val) {
    //     vector<int> vis(n,0);
    //     vector<vector<int>> g(n);
    //     int count = 0;

    //     for(int i=0 ; i<n ; ++i) {
    //         if(group[i] == val) {
    //             count+=1;
    //             for(int j=0 ; j<beforeItems[i].size() ; ++j) {
    //                 if(group[beforeItems[i][j]] == val) {
    //                     vis[i] += 1;
    //                     g[beforeItems[i][j]].push_back(i);
    //                 }
    //             }
    //         }
    //         else vis[i] = INT_MAX;
    //     }
    //     return toposort(g,vis,count);
    // }

    vector<int> solve(vector<vector<int>> &g,vector<int> &val,vector<int> &indg) {
        queue<int> q;

        for(auto i:val) {
            if(indg[i] == 0) {
                q.push(i);
            }
        }

        
        vector<int> ans;

        while(!q.empty()) {
            int k = q.front(); q.pop();
            ans.push_back(k);
            for(auto i:g[k]) {
                indg[i]-=1;
                if(indg[i] == 0) {
                    q.push(i);
                }
            }
        }

        if(val.size() == ans.size()) return ans;
        return {};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> g(n+m);
        vector<int> vis(n+m,INT_MAX);
        vector<vector<int>> countspe(n);
        vector<int> indg(n,0);
        for(int i=0 ; i<n ; ++i) {
            if(group[i] != -1) {
                vis[n+group[i]] = 0;
                continue;
            }
            vis[i] = 0;
        }
        int count = 0;
        set<int> st;
        vector<vector<int>> selfgroup(n);
        for(int i=0 ; i<n ; ++i) {
            if(group[i] != -1) {
                countspe[group[i]].push_back(i);
                st.insert(group[i]);
                for(int j=0 ; j<beforeItems[i].size() ; ++j) {
                    int ind = group[beforeItems[i][j]] == -1? beforeItems[i][j] : n+group[beforeItems[i][j]];
                    if(group[beforeItems[i][j]] != group[i]) {
                        vis[n+group[i]]+=1;
                        g[ind].push_back(n+group[i]);
                    }
                    else {
                        selfgroup[beforeItems[i][j]].push_back(i);
                        indg[i]+=1;
                    }
                }
            }
            else {
                count+=1;
                for(int j=0 ; j<beforeItems[i].size() ; ++j) {
                    vis[i]+=1;
                    int ind = group[beforeItems[i][j]] == -1? beforeItems[i][j] : n+group[beforeItems[i][j]];
                    g[ind].push_back(i);
                }
            }
        }

        vector<int> res = toposort(g,vis,count+st.size());

        if(res.size() == 0) {
            return {};
        }

        map<int,vector<int>> mp;
        for(int i=n ; i<n+m ; ++i) {
            mp[i] = solve(selfgroup,countspe[i-n],indg);
        }

        vector<int> ans;
        for(int i=0 ; i<res.size() ; ++i) {
            if(mp.find(res[i])!=mp.end()) {
                for(auto j:mp[res[i]]) ans.push_back(j);
            }
            else {
                ans.push_back(res[i]);
            }
        }

        if(ans.size() != n) return {};
        return ans;
    }
};