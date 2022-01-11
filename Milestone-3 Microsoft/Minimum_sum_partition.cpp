#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using tabulation DP
// Time Complexity :- O(N*sum)
// Space Complexity :- O(N*sum)

// This problem is a combination of subset sum problem and knapsack problem.
// With the use of the subset sum problem , we can find which sums are possible in knapsack
// Also at the end we only need to check last row with only half values from 0 to (sum/2)

class Solution
{
  public:
	int minDifference(int arr[], int n)  
	{ 
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        
        bool dp[n+1][sum+1];
        
        // subset sum problem
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j == 0) // sum to be formed is zero which is always possible 
                {
                    dp[i][j] = true;
                }
                else if(i == 0) // sum to be formed with no elements 
                {
                    dp[i][j] = false;
                }
                else if(arr[i-1] > j) // current value is greater than sum to be formed
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        int diff = INT_MAX;
        
        // knapsack problem 
        for(int i=0;i<=(sum/2);i++)
        {
            int first = i;
            int second = sum-i;
            if(dp[n][i] and diff>abs(first-second))
            {
                diff = abs(first-second);
            }
        }
        
        return diff;
	} 
};