class cmp {
 public:
    bool operator()(vector<int> &a,vector<int> &b) {
        return a[0]>b[0];
    }  
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int> , vector<vector<int>> ,cmp> q;
        q.push({0,0,0,0});
        int n = heights.size(),m =heights[0].size();
        vector<vector<bool>> vis(n ,vector<bool> (m,false));
        int arr[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        int ans = INT_MAX;
        while(!q.empty()) {
            vector<int> k = q.top();
            q.pop();
            if(k[1]==n-1 && k[2]==m-1) {
                return k[3];
            }
            if(vis[k[1]][k[2]]) continue;
            vis[k[1]][k[2]]=1;
            
            for(auto j : arr) {
                if(k[1]+j[0]>=0 && k[1]+j[0]<n && k[2]+j[1]>=0 && k[2]+j[1]<m) {
                    if(vis[k[1]+j[0]][k[2]+j[1]]) continue;
                    int val = abs(heights[k[1]+j[0]][k[2]+j[1]] - heights[k[1]][k[2]]);
                    q.push({val,k[1]+j[0],k[2]+j[1],max(val,k[3])});
                }    
            }   
            
        }
        return ans;
    }
};