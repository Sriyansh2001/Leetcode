class Solution {
public:
    void visited(vector<vector<int>> &rooms, vector<bool> &vis, int i) {
        if(vis[i]) return;
        vis[i] = true;
        for(auto j:rooms[i]) {
            visited(rooms,vis,j);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n+1,false);
        visited(rooms,vis,0);
        for(int i=0 ; i<n ; ++i) {
            if(vis[i] == false) return false;
        } return true;
    }
};