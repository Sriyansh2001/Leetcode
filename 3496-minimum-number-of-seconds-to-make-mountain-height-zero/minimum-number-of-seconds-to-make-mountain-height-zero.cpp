class Solution {
public:
    bool isPossible(int mountainHeight, vector<int> &workerTimes, long long maxLimit) {
        long long maxHeight = 0;
        int n = workerTimes.size();
        for(int i=0 ; i<n ; ++i) {
            long long b = workerTimes[i];
            long long heightGet = (sqrt( 1 + (8 * maxLimit / b)) - 1) / 2; 
            maxHeight += heightGet;
        }
        return maxHeight >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long start = 0, end = 1e17, res = 1e10;
        while(start <= end) {
            long long mid = (start + end) / 2;
            if(isPossible(mountainHeight, workerTimes, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                start = mid+1;
            }
        }
        return res;
    }
};