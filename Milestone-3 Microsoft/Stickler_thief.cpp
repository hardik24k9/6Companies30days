#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using recursion
// Time Complexity :- O(2^N)
// Space Complexity :- O(N)

// Approach :- 2 using recursion with memoization
// Time Complexity :- O(N)
// Space Complexity :- O(N)

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