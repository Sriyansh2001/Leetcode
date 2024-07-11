class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.length();
        string res = "";
        for(int i=0 ; i<n ;++i) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                string temp = "";
                int j = i-1;
                s[i]='.';
                while(s[j] != '(') {
                    temp.push_back(s[j]);
                    j-=1;
                }
                s[j] = '.';
                j+=1;
                int k = 0;
                while(j<i) {
                    s[j] = temp[k];
                    j+=1;
                    k+=1;
                }
            }
        }
        for(int i=0 ; i<n ;++i) {
            if(s[i] != '.') {
                res.push_back(s[i]);
            }
        } return res;
    }
};