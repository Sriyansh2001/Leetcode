class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<string> st(nums.begin(),nums.end());
        
        string t;
        for(int i=0 ; i<n ; ++i) {
            t.push_back('0');
        }

        for(int i=0 ; i<n ; ++i) {
            t[i] = '1';
            if(st.find(t)==st.end()) {
                return t;
            }
            t[i] = '0';
        }

        return t;
    }
};