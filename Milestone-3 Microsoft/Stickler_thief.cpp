#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using recursion
// Time Complexity :- O(2^N)
// Space Complexity :- O(N)

// Approach :- 2 using recursion with memoization
// Time Complexity :- O(N)
// Space Complexity :- O(N)
class Solution
{
    public:
    int dp[10001];
    
    int solve(int arr[],int i)
    {
        if(i <= -1) return 0;
        if(dp[i] != -1) return dp[i];
        
        int op1 = arr[i] + solve(arr,i-2);
        int op2 = solve(arr,i-1);
        return dp[i] = max(op1,op2);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        memset(dp,-1, sizeof dp);
        int ans = solve(arr,n-1);
        return ans;
    }
};

// Approach :- 3 using tabulation DP
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0],arr[1]);
        
        int dp[n];
        
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1],arr[i] + dp[i-2]);
        }
        
        return dp[n-1];
    }
};

// Approach :- 4 using DP optimized approach
// Time Complexity :- O(N)
// Space Complexity :- O(1)

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0],arr[1]);
        
        int prev_ans2 = arr[0];
        int prev_ans1 = max(arr[0],arr[1]);
        int curr_ans;
        
        for(int i=2;i<n;i++)
        {
            curr_ans = max(prev_ans1,prev_ans2 + arr[i]);
            prev_ans2 = prev_ans1;
            prev_ans1 = curr_ans;
        }
        
        return curr_ans;
    }
};