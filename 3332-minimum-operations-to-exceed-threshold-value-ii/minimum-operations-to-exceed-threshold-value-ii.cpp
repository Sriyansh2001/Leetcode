class Comp {
public:
    bool operator()(long a,long b) {
        return a > b;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long> , Comp> q;
        int n = nums.size();
        for(int i=0 ; i<n ; ++i) {
            q.push(nums[i]);
        }
        int ans = 0;
        while(q.top() < k) {
            long a1 = q.top();
            q.pop();
            long a2 = q.top();
            q.pop();
            ans+=1;
            q.push(a1 * 2LL + a2);
        }
        return ans;
    }
};