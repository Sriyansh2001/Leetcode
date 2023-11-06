class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> q;
        int curr = arr[0];
        int n = arr.size();
        if(k>(n-1)) return *max_element(arr.begin(),arr.end());
        for(int i=1 ; i<n ; ++i) {
            q.push_back(arr[i]);
        }
        int ans = -1,wincount=0;

        while(true) {
            int frt = q.front();
            if(curr < frt) {
                q.pop_front();
                q.push_back(curr);
                curr = frt;
                wincount = 1;
            }
            else {
                wincount+=1;
                q.pop_front();
                q.push_back(frt);
            }
            if(wincount >= k) {
                ans = curr; break;
            }
        }
        return ans;
    }
};