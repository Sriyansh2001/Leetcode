class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> q;
        vector<vector<int>> v;
        for(int i=0 ; i<capital.size() ; ++i) {
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        int i=0,n=v.size();
        while(k!=0) {
            while(i<n && v[i][0]<=w) {
                q.push(v[i][1]);
                i+=1;
            }
            if(q.empty()) break;
            w += q.top();
            q.pop();
            k-=1;
        }int ans=w;
        return ans;
    }
};
////https://m4maths.com/16032-There-are-6-identical-oranges-and-6-distinct-apples-In-how-many-ways-can-one-choose-5-fruits-containing-atleast.html