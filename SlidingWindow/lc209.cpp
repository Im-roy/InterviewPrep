// URL: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int low = -1, high = 0, ans = INT_MAX;
        long long sum = 0;
        while(high < nums.size()) {
            sum += nums[high];
            while(sum >= target) {
                ans = min(ans, high - low);
                low += 1;
                sum -= nums[low];
            }
            high += 1;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};