// URL: https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        
        int low = -1, high = 0, ans = 0;
        map<int, int> mp;
        while(high < n) {
            mp[fruits[high]] += 1;
            while(mp.size() > 2) {
                low += 1;
                mp[fruits[low]] -= 1;
                if(mp[fruits[low]] == 0) {
                    mp.erase(fruits[low]);
                }
            }
            ans = max(ans, high - low);
            high += 1;
        }
        return ans;
    }
};
