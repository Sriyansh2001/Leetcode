class Solution {
public:
    vector<int> insertInto(vector<int> &v,int val) {
        vector<int> res;
        for(int i=0 ; i<v.size() ; ++i) {
            if(val == -1) {
                res.push_back(v[i]);
            } else {
                if(val == v[i]) {
                    val = -1;
                }
                else if(val < v[i]) {
                    res.push_back(val);
                    val = -1;
                }
                res.push_back(v[i]);
            }
        } 
        if(val != -1) res.push_back(val);
        return res;
    }

    vector<int> mergeSortedArray(vector<int> &v1, vector<int> &v2) {
        vector<int> res;
        int n = v1.size(),m = v2.size();
        int i=0,j=0;
        while(i<n && j<m) {
            if(v1[i] < v2[j]) {
                res.push_back(v1[i]);
                i+=1;
            } else if(v1[i] > v2[j]){
                res.push_back(v2[j]);
                j+=1;
            } else {
                res.push_back(v2[j]);
                j+=1;
                i+=1;
            }
        }
        while(i<n) {
            res.push_back(v1[i]); i+=1;
        }
        while(j<m) {
            res.push_back(v2[j]); j+=1;
        }
        return res;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n),ans(n);
        vector<int> ind(n,0),temp;
        queue<int> q;

        for(auto i:edges) {
            g[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }

        for(int i=0 ; i<n ; ++i) {
            if(ind[i] == 0) {
                ans[i] = {};
                q.push(i);
            }
        }

        while(!q.empty()) {
            int k = q.front();
            q.pop();
            for(auto j:g[k]) {
                ind[j]-=1;
                temp = insertInto(ans[k],k);
                ans[j] = mergeSortedArray(temp,ans[j]);
                if(ind[j] == 0) {
                    q.push(j);
                }
            }
        }
        
        return ans;
    }
};