/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {
    nums.sort((a,b) => {return a-b})
    let ans = 0,sum = nums[0]+nums[1];
    let n = nums.length
    for(let i=2 ; i<n ; ++i) {
        if(sum > nums[i]) {
            ans = Math.max(ans,sum+nums[i]);
        }
        sum += nums[i]
    }
    if(ans == 0) return -1;
    return ans
};