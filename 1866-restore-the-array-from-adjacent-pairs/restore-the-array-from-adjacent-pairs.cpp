class Solution {
    map<int,vector<int>> creategraph(vector<vector<int>> &adjpairs) {
        int size = adjpairs.size()+1;
        map<int,vector<int>> g;

        for(auto node:adjpairs) {
            g[node[0]].push_back(node[1]);
            g[node[1]].push_back(node[0]);
        }

        return g;
    }

    int findstart(map<int,vector<int>> &g) {
        int size = g.size();

        for(auto node: g) {
            if(g[node.first].size() == 1) {
                return node.first;
            }
        }

        return -1;
    }

    void createArray(map<int,vector<int>> &g,int curr,vector<int> &result,int prev) {
        result.push_back(curr);

        for(auto node: g[curr]) {
            if(node != prev) {
                createArray(g,node,result,curr);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> graph = creategraph(adjacentPairs);
        int start = findstart(graph);
        vector<int> result;
        createArray(graph,start,result,-1);
        return result;
    }
};