class Solution {
public:
    
    vector<int> solve(vector<int> &arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1 ; i>=0 ; --i) {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            else ans[i]=n;
            st.push(i);
        }
        return ans;
    }
    const int M = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pre = solve(arr);
        int n = arr.size();
        long long int ans = 0;
        vector<long long int> com(n,0);
        for(int i=n-1 ; i>=0 ; --i) {
            int val = pre[i];
            if(val!=n) {
                com[i] = arr[i]*1LL*(val-i)+com[val];
            }
            else{
                com[i] = arr[i]*1LL*(n-i);
            }
            ans = (ans + com[i])%M;
        }
        return ans;
    }
};