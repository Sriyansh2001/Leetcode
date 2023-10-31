class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n,0);
        ans[0] = pref[0];
        int present = ans[0];
        for(int i=1 ; i<n ; ++i) {
            int val = pref[i];
            int curr = 0;
            for(int j=0 ; j<31 ; ++j) {
                if((val>>j)&1) {
                    if(!((present>>j)&1)) {
                        curr += pow(2,j);
                    }
                }
                else {
                    if((present>>j)&1) {
                        curr += pow(2,j);
                    }
                }
            }
            present ^= curr;
            ans[i] = curr;
        }
        return ans;
    }
};