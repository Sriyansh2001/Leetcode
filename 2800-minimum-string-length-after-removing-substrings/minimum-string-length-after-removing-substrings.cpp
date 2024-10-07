class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.length(),ans=0;
        for(int i=0 ; i<n ; ++i) {
            if(st.empty()) {
                st.push(s[i]);
            } else {
                char top = st.top();
                if(top == 'A' && s[i] == 'B') {
                    st.pop();
                    ans += 2;
                } else if(top == 'C' && s[i] == 'D') {
                    st.pop();
                    ans += 2;
                } else {
                    st.push(s[i]);
                }
            }
        }
        return n - ans;
    }
};