class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int low = -1, high = 0, ans = 0;
        int cntZero = 0;
        
        while(high < nums.size()) {
            cntZero += (nums[high] == 0 ? 1: 0);
            while(cntZero > k) {
                low += 1;
                cntZero -= (nums[low] == 0 ? 1: 0);
            }
            ans = max(ans, high - low);
            high += 1;
        }
        return ans;
    }
};