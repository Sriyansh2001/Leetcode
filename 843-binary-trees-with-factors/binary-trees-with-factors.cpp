class Solution {
public:
    int M = 1e9+7;
    map<int,int> dp;
    set<int> st;

    int solve(vector<int> &arr,int tar) {
        int res = 1;
        int n = arr.size();

        if(dp.find(tar) != dp.end()) {
            return dp[tar];
        }
        
        for(int i=0 ; i<n ; ++i) {
            if(tar%arr[i] == 0) {
                if(st.find(tar/arr[i]) != st.end()) {
                    res = (res + ((solve(arr,tar/arr[i]))*1LL*(solve(arr,arr[i])))%M)%M;
                }
            }
        }

        return dp[tar] = (res)%M;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        for(auto i:arr) {
            st.insert(i);
        }
        int res = 0;
        for(auto i:arr) {
            res = (res+0LL+solve(arr,i))%M;
        }
        return res;
    }
};