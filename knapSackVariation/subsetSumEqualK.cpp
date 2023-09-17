// URL: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
class Solution{   
public:
    
    int dp[105][105];
    bool helper(int i, int sum, vector<int> &arr) {
        if(i == arr.size() or sum == 0) {
            return sum == 0;
        }
        
        if(dp[i][sum] != -1)
            return dp[i][sum] == 1;
        
        if(sum >= arr[i])
            return dp[i][sum] = helper(i+1, sum-arr[i], arr) || helper(i+1, sum, arr);
        else
            return dp[i][sum] = helper(i+1, sum, arr);
    }

    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp, -1, sizeof(dp));
        return helper(0, sum, arr);
    }
};