class Solution {
public:
    int solve(vector<string> &arr,int i,string s) {
        if(i==arr.size()) {
            // cout << "here" << s << endl;
            int a[26];
            for(int i=0 ; i<26 ; ++i) a[i]=0;
            for(int i=0 ; i<s.length() ; ++i) {
                a[s[i]-'a']+=1;
            }
            for(int i=0 ; i<26 ; ++i) {
                if(a[i]>1) return 0;
            }
            return s.length();
        }
        int a[26];
        for(int i=0 ; i<26 ; ++i) a[i]=0;
        for(int i=0 ; i<s.length() ; ++i) {
            a[s[i]-'a']+=1;
        }
        for(int i=0 ; i<26 ; ++i) {
            if(a[i]>1) return 0;
        }
        int pick = solve(arr,i+1,s+arr[i]);
        int notpick = solve(arr,i+1,s);
        return max(pick,notpick);
    }
    
    int maxLength(vector<string>& arr) {
        return solve(arr,0,"");
    }
};