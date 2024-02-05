class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        map<char,int> mp;
        for(int i=0 ; i<s.length() ; ++i) {
            mp[s[i]] += 1;
            if(mp[s[i]] == 1) {
                q.push(i);
            }
            while(!q.empty()) {
                if(mp[s[q.front()]] > 1) {
                    q.pop();
                }
                else break;
            }
        }
        if(!q.empty()) {
            return q.front();
        }
        return -1;
    }
};