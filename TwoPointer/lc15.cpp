// URL: https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<pair<int, int>> getPairWithSum(vector<int> &nums, int low, int high, int sum) {
        
        vector<pair<int, int>> vp;
        while(low < high) {
            int currSum = nums[low] + nums[high];
            if(currSum == sum) {
                vp.push_back({nums[low], nums[high]});
                low += 1;
                high -= 1;
            }
            else if(currSum > sum)
                high -= 1;
            else
                low += 1;
        }
        return vp;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            vector<pair<int, int>> vp = getPairWithSum(nums, i+1, nums.size()-1, -1*nums[i]);
            for(auto x: vp) {
                st.insert({nums[i], x.first, x.second});
            }
        }
        vector<vector<int>> ans;
        for(auto x: st) {
            ans.push_back(x);
        }
        return ans;
    }
}; 