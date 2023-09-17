// URL: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1005][1005];
    int helper(int i, int w, int wt[], int val[], int n) {
        if(i == n) 
            return 0;
            
        if(dp[i][w] != -1)
            return dp[i][w];
            
        if(wt[i] <= w) 
            return dp[i][w] = max(val[i] + helper(i+1, w-wt[i], wt, val, n), helper(i+1, w, wt, val, n));
        else
            return dp[i][w] = helper(i+1, w, wt, val, n);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp, -1, sizeof(dp));
       return helper(0, W, wt, val, n);
    }
};