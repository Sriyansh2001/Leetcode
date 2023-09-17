class cmp {
public:
    bool operator()(int a,int b) {
        return a>b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , cmp> q;
        int n = nums.size();
        for(int i=0 ; i<k ; ++i) {
            q.push(nums[i]);
        }
        for(int i=k ; i<n ; ++i) {
            if(nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};