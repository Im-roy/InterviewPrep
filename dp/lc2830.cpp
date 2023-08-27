// URL: https://leetcode.com/problems/maximize-the-profit-as-the-salesman/

class Solution {
public:
    vector<vector<int>> arr;
    vector<int> t;
    int n, m;
    int dp[100005];
    int getIndex(int i, int val) {
        auto it = lower_bound(t.begin() + i + 1, t.end(), val+1) - t.begin();
        return it;
    }
    
    int solve(int i) {
        if(i >= m)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int x = getIndex(i, arr[i][1]);
        return dp[i] = max(arr[i][2] + solve(x), solve(i+1));
    } 
    
    int maximizeTheProfit(int _n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), [](vector<int> &a, vector<int> &b){
           return a[0] < b[0]; 
        });
        n = _n, m = offers.size();
        arr = offers;
        for(auto x: offers) {
            t.push_back(x[0]);
        }

        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};
