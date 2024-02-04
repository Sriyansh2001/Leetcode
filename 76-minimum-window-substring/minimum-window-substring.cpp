class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp,st;
        for(auto i:t)  {
            mp[i]+=1; st[i]+=1;
        }
        int items = mp.size();
        int ans = INT_MAX,start=-1,end=-1,j=0,n=s.length();
        for(int i=0 ; i<n ; ++i) {
            if(mp.find(s[i])!=mp.end()) {
                mp[s[i]]-=1;
                if(mp[s[i]]==0) items-=1;
            }
            while(items==0) {
                if(ans>(i-j+1)) {
                    ans = i-j+1;
                    start=j;
                    end=i;
                }
                if(mp.find(s[j])!=mp.end()) {
                    if(mp[s[j]]<st[s[j]]) {
                        mp[s[j]]+=1;
                        if(mp[s[j]]==1)
                            items+=1;
                    }
                }
                j+=1;
            }
        }
        if(start==-1 || end==-1) return "";
        string res;
        for(int i=start ; i<=end ; ++i) {
            res.push_back(s[i]);
        } return res;
    }
};