#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 brute-force (for each element find max peak and valley on both sides)
// Time Complexity :- O(N*N)
// Space Complexity :- O(1)

// Approach :- 2 brute-better (for each peak element only find max peak and valley on both sides)
// Time Complexity :- O(2*N)
// Space Complexity :- O(1)

// Approach :- 3 optimal solution (just find max peak and then after max valley and handle corner case)
// Time Complexity :- O(N)
// Space Complexity :- O(1)

class Solution 
{
public:
    int longestMountain(vector<int>& arr) 
    {
        int ans = 0,i = 0;
        int n = arr.size();
        
        while(i < n)
        {
            int peak = 0,valley = 0;
            
            while(i < n-1 and arr[i] < arr[i+1]) peak++,i++;
            while(i < n-1 and arr[i] > arr[i+1]) valley++,i++;
            
            if(peak and valley) ans = max(ans,peak + valley + 1);
            else if(!peak and !valley) i++; 
        }
        
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr;

        for(int i=0;i<n;i++) cin >> arr[i];

        Solution ob;
        int ans = ob.longestMountain(arr);
        cout << ans << endl;
    }
}