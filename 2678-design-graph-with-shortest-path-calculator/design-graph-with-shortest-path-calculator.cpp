class cmp{
    public:
    bool operator()(vector<int> &a,vector<int> &b) {
        return a[0]>b[0];
    }
};

class Graph {
public:
    vector<vector<vector<int>>> g;
    int size=0;
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        size=n;
        for(auto i:edges) {
            g[i[0]].push_back({i[1],i[2]});
        }
    }
    
    void addEdge(vector<int> i) {
        g[i[0]].push_back({i[1],i[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<vector<int>,vector<vector<int>> , cmp> q;
        q.push({0,node1});
        vector<int> temp(size,INT_MAX);
        while(!q.empty()) {
            vector<int> k = q.top(); q.pop();
            if(k[1]==node2) {
                return k[0];
            }
            if(temp[k[1]]>k[0]) {
                temp[k[1]] = k[0];
                for(auto j:g[k[1]]) {
                    q.push({k[0]+j[1],j[0]});
                }
            }
            else continue;
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */