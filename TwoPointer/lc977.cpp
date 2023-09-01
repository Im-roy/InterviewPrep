// URL: https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int low = 0, high = nums.size() - 1, lastIndex = nums.size() - 1;
        vector<int> result(nums.size());
        while(low <= high) {
            
            int squareLow = nums[low] * nums[low];
            int squareHigh = nums[high] * nums[high];
            if(squareLow >= squareHigh){
                result[lastIndex--] = squareLow;
                low += 1;
            } else {
                result[lastIndex--] = squareHigh;
                high -= 1;
            }
        }
        return result;
    }
};