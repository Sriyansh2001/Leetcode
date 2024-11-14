class Solution {
public:
    bool checkPossible(int quat,int n, vector<int> &v) {
        int size = v.size();
        int amount = 0;
        for(int i=0 ; i<size ; ++i) {
            int times = ceil(v[i]/((float)quat));
            amount += times;
        }
        return amount <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1, end = 1e5+1;
        int ans = INT_MAX;
        while(start <= end) {
            int mid = (start+end)/2;
            if(checkPossible(mid, n, quantities)) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }
};