class Solution {
public:
    int checkwithstart(string &s,bool start) {
        int n = s.length();
        bool flag = start;
        int count = 0;
        for(int i=0 ; i<n ; ++i) {
            if(flag) {
                if(s[i] == '0') count += 1;
            }
            else {
                if(s[i] == '1') count += 1;
            }
            flag = !flag;
        }
        return count;
    }

    int minOperations(string s) {
        return min(checkwithstart(s,false),checkwithstart(s,true));
    }
};