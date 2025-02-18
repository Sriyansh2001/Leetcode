class Solution {
public:
    string smallestNumber(string s) {
        int n = s.length();
        string t;
        int start = 1;
        for(int i=0 ; i<n ; ++i) {
            if(s[i] == 'D') {
                int ind = i;
                while(i<n && s[i] == 'D') {
                    start++;
                    i++;
                }
                if(i == n - 1 && s[i] == 'D') {
                    start++;
                    i++;
                } 
                int end = start;
                for(int j=i ; j>=ind ; --j) {
                    t.push_back(start+'0');
                    start--;
                }
                start = end+1;
                if(i == n - 1 && s[i] != 'D') {
                    t.push_back(start+'0');
                } 
            }
            else {
                t.push_back(start+'0');
                start++;
                if(i == n-1) {
                    t.push_back(start+'0');
                }
            }
        } 
        return t;
    } 
};