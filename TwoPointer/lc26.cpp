// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int low = 0, lastValue;
        for(int i=0; i<nums.size(); i++) {
            if(i == 0) {
                nums[low] = nums[i];
                lastValue = nums[i];
                low += 1;
                continue;
            }
            if(nums[i] != lastValue) {
                nums[low] = nums[i];
                lastValue = nums[i];
                low += 1;
            }
        }
        return low;
    }
};