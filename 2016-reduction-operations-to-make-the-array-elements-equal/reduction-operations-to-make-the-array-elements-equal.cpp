class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) {
            mp[i]+=1;
        }
        priority_queue<int> q;
        for(auto i:mp) {
            q.push(i.first);
        }
        int ans = 0;
        while(q.size() > 1) {
            int k = q.top();
            q.pop();
            ans += mp[k];
            if(q.size()) {
                mp[q.top()] += mp[k];
            }
        }
        return ans;
    }
};