class Solution {
public:
    vector<int> topologicalsort(queue<int> &q,vector<vector<int>> &g,vector<int> &indg) {
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
        return ans;
    }

    vector<int> toposortgrouptogether(vector<vector<int>> &g,vector<int> &vis) {
        int n = g.size();
        queue<int> q;
        for(int i=0 ;  i<n ; ++i) {
            if(vis[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans=topologicalsort(q,g,vis);
        return ans;
    }

    vector<int> toposorteverysinglegroupelement(vector<vector<int>> &g,vector<int> &val,vector<int> &indg) {
        queue<int> q;
        for(auto i:val) {
            if(indg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans = topologicalsort(q,g,indg);
        return ans;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> g(n+m);
        vector<int> vis(n+m,INT_MAX);
        vector<vector<int>> countspe(n);
        vector<int> indg(n,0);
        vector<vector<int>> selfgroup(n);

        for(int i=0 ; i<n ; ++i) {
            if(group[i] != -1) {
                vis[n+group[i]] = 0;
                continue;
            }
            vis[i] = 0;
        }
        
        for(int i=0 ; i<n ; ++i) {
            if(group[i] != -1) {
                countspe[group[i]].push_back(i);
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
                for(int j=0 ; j<beforeItems[i].size() ; ++j) {
                    vis[i]+=1;
                    int ind = group[beforeItems[i][j]] == -1? beforeItems[i][j] : n+group[beforeItems[i][j]];
                    g[ind].push_back(i);
                }
            }
        }

        vector<int> res = toposortgrouptogether(g,vis);

        vector<vector<int>> mp(m);
        for(int i=0 ; i<m ; ++i) {
            mp[i] = toposorteverysinglegroupelement(selfgroup,countspe[i],indg);
        }

        vector<int> ans;
        for(int i=0 ; i<res.size() ; ++i) {
            if(res[i]>=n) {
                for(auto j:mp[res[i]-n]) ans.push_back(j);
            }
            else {
                ans.push_back(res[i]);
            }
        }

        if(ans.size() != n) return {};
        return ans;
    }
};