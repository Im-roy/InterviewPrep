// URL: https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> vp;
        for(int i=0; i<nums.size(); i++) {
            vp.push_back({nums[i], i});
        }
        sort(vp.begin(), vp.end());
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int currentSum = vp[low].first + vp[high].first;
            if(currentSum == target)
                return {vp[low].second, vp[high].second};
            else if(currentSum > target)
                high -= 1;
            else
                low += 1;
        }
        return {-1, -1};
    }
};