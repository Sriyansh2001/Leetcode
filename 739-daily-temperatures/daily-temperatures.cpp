class Solution {
public:
    vector<int> solve(vector<int> &temp) {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1 ; i>=0 ; --i) {
            if(!st.empty())
            while(!st.empty() && temp[st.top()]<=temp[i]) {
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            else ans[i]=i;
            st.push(i);
        }
        return ans;
    }

    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans = solve(temp);
        vector<int> res;
        for(int i=0 ; i<ans.size() ; ++i) {
            res.push_back(ans[i]-i);
        }
        return res;
    }
};