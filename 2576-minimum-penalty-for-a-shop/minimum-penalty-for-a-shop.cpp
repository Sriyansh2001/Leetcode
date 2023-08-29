class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> close(n,0);
        vector<int> open(n,0);
        if(customers[n-1] == 'Y') open[n-1]=1;
        if(customers[0] == 'N') close[0]=1;
        for(int i=1 ; i<n ; ++i) {
            if(customers[i] == 'N') close[i] = close[i-1]+1;
            else close[i] = close[i-1];
        }
        for(int i=n-2 ; i>=0 ; --i) {
            if(customers[i] == 'Y') open[i] = open[i+1]+1;
            else open[i] = open[i+1];
        }
        int ans = 0;
        int penalty = open[0];
        for(int i=0 ; i<n-1 ; ++i) {
            if(close[i]+open[i+1] < penalty) {
                ans = i+1;
                penalty = close[i]+open[i+1];
            }
        }
        if(penalty > close[n-1]) {
            return n;
        }
        return ans;
    }
};