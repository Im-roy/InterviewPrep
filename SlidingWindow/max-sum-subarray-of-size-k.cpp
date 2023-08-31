// URL: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        
        long long maximumSum = 0, windowSum = 0, leftPtr = 0;
        for(int i=0; i<n; i++) {
            windowSum += arr[i];
            if(i >= k-1) {
                maximumSum = max(maximumSum, windowSum);
                windowSum -= arr[leftPtr];
                leftPtr += 1;
            }
        }
        return maximumSum;
    }
};