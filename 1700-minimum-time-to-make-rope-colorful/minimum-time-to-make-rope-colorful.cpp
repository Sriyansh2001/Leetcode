class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = colors.size();
        int ans = 0, i = 0;
        while(i<n) {
            char color = colors[i];
            while(i<n && colors[i] == color) {
                q.push(neededTime[i]);
                i += 1;
            }
            while(q.size()>1) {
                ans += q.top();
                q.pop();
            }
            q.pop();
        }
        return ans;
    }
};