// URL: https://leetcode.com/problems/check-if-it-is-possible-to-split-array/

class Solution {
public:
    
    int m, dp[105][10005];
    vector<int> arr, psum;
    
    int getRequiredSum(int l, int h) {
        return psum[h] - (l-1 >= 0 ? psum[l - 1] : 0);
    }
    
    bool solve(int low, int high) {
        if(high - low == 1)
            return true;
        
        if(dp[low][high] != -1)
            return dp[low][high];
        
        bool ans = false;
        int sum = getRequiredSum(low, high);
        cout<<sum<<endl;
        if(sum - arr[low] >= m) 
            ans |= solve(low + 1, high);
        
        if(sum - arr[high] >= m) 
            ans |= solve(low, high - 1);
        
        return dp[low][high] = ans;
    }
    
    bool canSplitArray(vector<int>& nums, int _m) {
        arr = nums;
        m = _m;
        int sum = 0;
        if(nums.size() == 1) return true;
        
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<nums.size(); i++) {
            if(i == 0) {
                psum.push_back(nums[i]);
                continue;
            }
            psum.push_back(psum.back() + nums[i]);
        }
        
        return solve(0, nums.size() - 1);
    }
};