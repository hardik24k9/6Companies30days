#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 brute force
// Time Complexity :- O(N^4)
// Space Complexity :- O(1)

// Approach :- 2 using two-pointers
// Time Complexity :- O(N^3)
// Space Complexity :- O(1)

class Solution
{
    public:
    vector<vector<int>> fourSum(vector<int> &arr, int k) 
    {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> nums;
        
        if(n<4) return nums;
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int need = k - arr[i] - arr[j];
                int low = j+1;
                int high = n-1;
                
                while(low<high)
                {
                    if(arr[low]+arr[high]==need)
                    {
                        vector<int> quad(4);
                        quad[0] = arr[i];
                        quad[1] = arr[j];
                        quad[2] = arr[low];
                        quad[3] = arr[high];
                        nums.push_back(quad);
                        
                        // for duplicates of 3rd num
                        while(low<high && arr[low]==quad[2]) ++low;
                        
                        // for duplicates of 4th num
                        while(low<high && arr[high]==quad[3]) --high;
                    }
                    else if(arr[low]+arr[high]>need)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
                // for duplicates of 2nd num
                while(j<n-2 && arr[j+1]==arr[j]) ++j;
            }
            // for duplicates of 1st num
            while(i<n-3 && arr[i+1]==arr[i]) ++i;
        }
        return nums;
    }
};