class Solution {
public:
    // time/space: O(n)/O(n)
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (k >= n) return *max_element(arr.begin(), arr.end());
        
        deque<int> dq(arr.begin(), arr.end());
        unordered_map<int, int> win_count;
        while (true) {
            int arr0 = dq.front(); dq.pop_front();
            int arr1 = dq.front(); dq.pop_front();
            int winner = max(arr0, arr1);
            int loser = min(arr0, arr1);
            if ((++win_count[winner]) == k) return winner;
            dq.push_front(winner);
            dq.push_back(loser);
        }
        return -1;
    }
};