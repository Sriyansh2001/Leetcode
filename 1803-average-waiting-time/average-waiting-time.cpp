class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customer) {
        long long totalTime = 0;
        int n = customer.size();
        long long busyTill = 0;
        for(int i=0 ; i<n ; ++i) {
            int actualTime = customer[i][1] + customer[i][0];
            if(busyTill <= customer[i][0]) {
                busyTill = actualTime;
                totalTime += customer[i][1];
            } else {
                totalTime += customer[i][1] + busyTill - customer[i][0];
                busyTill = busyTill + customer[i][1];
            }
        }
        return (double)totalTime/n;
    }
};