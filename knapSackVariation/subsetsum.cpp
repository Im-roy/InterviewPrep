// URL: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
class Solution{
public:

    int dp[105][10005];
    int helper(int i, int sum, int n, int arr[]) {
        if(i == n) 
            return sum == 0;
            
        if(dp[i][sum] != -1)
            return dp[i][sum] == 1;
        
        if(sum >= arr[i])
            return dp[i][sum] = (helper(i+1, sum - arr[i], n, arr) || helper(i+1, sum, n, arr));
        else
            return dp[i][sum] = helper(i+1, sum, n, arr);
    }

    int equalPartition(int n, int arr[]) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        if(sum&1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return helper(0, sum/2, n, arr);
    }
};