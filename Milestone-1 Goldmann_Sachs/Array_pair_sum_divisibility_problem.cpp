#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 brute force (make current val and remaining val -1 , at the end if all are -1 then true else false)
// Time Complexity :- O(N*N)
// Space Complexity :- O(N)

// Approach :- 2 using maps
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution 
{
  public:
    bool canPair(vector<int> nums, int k) 
    {
        int n = nums.size();
        if(n%2) return false;
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]%k]++;
        }
        
        for(auto l : mp)
        {
            int v1 = l.first;
            int v2 = k - l.first;
            
            if(v1 == 0) // corner case
            {
                if(mp[v1]%2) return false;
            }
            else if(v1 == v2)
            {
                if(mp[v1]%2) return false;
            }
            else
            {
                if(mp[v1] != mp[v2]) return false;
            }
        }
        
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin >> nums[i];

        Solution ob;
        bool ans = ob.canPair(nums,k);

        if(ans)
        cout << "True" << endl;
        else
        cout << "False" << endl;
    }
}