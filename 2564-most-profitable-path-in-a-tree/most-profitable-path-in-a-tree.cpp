class Solution {
public:
    int m;

    vector<vector<int>> createGraph(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> g(n+1);
        for(int i=0 ; i<n ; ++i) {
            g[graph[i][0]].push_back(graph[i][1]);
            g[graph[i][1]].push_back(graph[i][0]);
        }
        return g;
    }

    bool getBobPath(vector<vector<int>> &graph, vector<bool> &vis, vector<int> &path, int node) {
        if(node == 0) {
            path.push_back(0);
            return true;
        }
        int adj = graph[node].size();
        vis[node] = true;
        path.push_back(node);
        bool isGetPath = false;
        for(int i=0 ; i<adj ; ++i) {
            int nextNode = graph[node][i];
            if(!vis[nextNode]) {
                isGetPath = getBobPath(graph, vis, path, nextNode);
                if(isGetPath) {
                    return true;
                }
            }
        }
        path.pop_back();
        return false;
    }

    int getMaximumDistance(vector<vector<int>> &g,map<int, int> &path,int node, vector<int> &amount, int par, int steps) {
        int adj = g[node].size();
        int currentAmount = amount[node];
        if(path.find(node) != path.end()) {
            if(path[node] < steps) {
                currentAmount = 0;
            } else if(path[node] == steps) {
                currentAmount = currentAmount / 2;
            }
        }
        int res = currentAmount;
        for(int i=0 ; i<adj ; ++i) {
            int nextNode = g[node][i];
            if(nextNode == par) {
                continue;
            }
            if(res != currentAmount)
                res = max(res, getMaximumDistance(g,path,nextNode,amount,node, steps+1) + currentAmount);
            else
                res = getMaximumDistance(g,path,nextNode,amount,node, steps+1) + currentAmount;
        }
        return res;
    }    

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        vector<vector<int>> g = createGraph(edges);
        vector<int> path;
        vector<bool> vis(n+1, false);
        getBobPath(g,vis,path,bob);
        map<int,int> bobPath;
        m = path.size();    
        for(int i=0 ; i<m ; ++i) {
            bobPath[path[i]] = i;
        }
        return getMaximumDistance(g,bobPath,0,amount, -1,0);
    }
};