class Solution {
public:
    vector<long long> total;

    long long solve(vector<vector<int>> &g,vector<int> &value,int i,int par) {
        if(g[i].size() == 1 && i != 0) {
            return 0;
        }
        long long ans = 0;

        for(auto j:g[i]) {
            if(j != par) {
                ans += solve(g,value,j,i);
            }
        }
        ans += value[i];
        ans = max(ans,total[i]-value[i]);
    
        return ans;
    }

    long long cal_total(vector<vector<int>> &g,vector<int> &value,int i,int par) {
        total[i] = value[i];
        for(auto j:g[i]) {
            if(j != par)
                total[i] += cal_total(g,value,j,i);
        }
        return total[i];
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> g(n);
        for(int i=0 ; i<n-1 ; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        total.resize(n,0);
        cal_total(g,values,0,-1);
        return solve(g,values,0,-1);
    }
};