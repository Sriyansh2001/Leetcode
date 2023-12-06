class Solution1 {
public:
    long long get(vector<vector<int>> &v,int i,int ni)
    {
        if(i==v.size())
        return ni==-1?INT_MIN:0;
        long long ans=INT_MIN;
        ans=get(v,i+1,ni);
        if(v[i][2]>ni)
        ans=max(ans,v[i][1]+get(v,i+1,v[i][2]));
        return ans;
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        vector<vector<int>> v;
        for(int i=0 ; i<nums.size() ; ++i) {
            v.push_back({nums[i]-i,nums[i],i});
        }
        sort(v.begin(),v.end());
        return get(v,0,-1);
    }
};

class Solution {
public:
    vector<long long> seg;
    vector<vector<long long>> v;
    void update(int i,int left,int right,int ind,long long value) {
        if(left == right) {
            seg[i] = value;
            return ;
        }
        int mid = (left+right)/2;
        if(ind <= mid) {
            update(2*i+1,left,mid,ind,value);
        }
        else {
            update(2*i+2,mid+1,right,ind,value);
        }
        seg[i] = max(seg[2*i+1],seg[2*i+2]);
    }

    long long range(int i,int left,int right,int qleft,int qright) {
        if(qleft <= left && qright >= right) {
            return seg[i];
        }
        if(qleft > right || qright < left) {
            return INT_MIN;
        }
        int mid = (left+right)/2;
        long long l=range(2*i+1,left,mid,qleft,qright);
        long long r=range(2*i+2,mid+1,right,qleft,qright);
        return max(l,r);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<nums.size() ; ++i) {
            v.push_back({nums[i]-i,nums[i],i});
        }
        sort(v.begin(),v.end());
        seg.resize(4*n,INT_MIN);
        long long res = 0;
        for(int i=n-1 ; i>=0 ; --i) {
            long long ans = range(0,0,n-1,v[i][2]+1,n-1);
            ans = max(ans+v[i][1],v[i][1]);
            update(0,0,n-1,v[i][2],ans);
        }
        return seg[0];
    }
};