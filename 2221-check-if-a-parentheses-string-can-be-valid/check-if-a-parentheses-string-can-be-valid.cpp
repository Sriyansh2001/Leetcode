class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> st,t;
        int any = 0;
        int n = s.length();

        if(n%2) return false;

        for(int i=0 ; i<n ; ++i) {
            if(locked[i] == '0') {
                st.push(i);
            } else {
                if(s[i] == ')') {
                    if(t.size()) {
                        t.pop();
                    }
                    else if(st.size()) {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                } else {
                    t.push(i);
                }
            }
        }

        while(!t.empty()) {
            if(st.empty()) return false;
            int a1 = t.top();
            t.pop();
            int a2 = st.top();
            st.pop();
            if(a1 > a2) return false;
        }

        return true;

    }
};