class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0,f=0;
        do{
            f = nums[nums[f]];
            s = nums[s];
        }while(f!=s);
        f = 0;
        while(f!=s){
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};