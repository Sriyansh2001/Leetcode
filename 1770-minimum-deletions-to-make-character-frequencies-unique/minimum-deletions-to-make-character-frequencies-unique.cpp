class Solution {
    int compute_result(vector<int> &fre) {
        stack<int> st;
        int n = fre.size(), j = 0, mx = fre[n-1], answer = 0;
        for(int i=1 ; i<=mx && j<n ; ++i) {
            if(fre[j] != i) {
                st.push(i);
            } else {
                int val = fre[j], count = 0;
                while(j<n && fre[j] == val) {
                    j+=1;
                    count += 1;
                } count-=1;
                while(count > 0) {
                    if(st.size()) {
                        answer += (i-st.top());
                        st.pop();
                    }
                    else answer += i;
                    count-=1;
                }
            }
        }
        return answer;
    }

public:
    int minDeletions(string s) {
        map<char,int> freq;
        for(auto i:s) freq[i]+=1;
        vector<int> fre;
        for(auto i:freq) fre.push_back(i.second); 
        sort(fre.begin(),fre.end());
        int answer = compute_result(fre);
        return answer;
    }
};