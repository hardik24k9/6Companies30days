#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using recursion
// Time Complexity :- O(N * (4^N))
// Space Complexity :- O(N) 

class Solution
{
    public:
    vector<string> solve(int a[],int i,map<int,string> &mp,int n)
    {
        if(i == n) return {""};
        
        vector<string> temp = solve(a,i+1,mp,n);
        vector<string> ans;
        
        for(auto l : mp[a[i]])
        {
            for(auto x : temp)
            {
                ans.push_back(l+x);
            }
        }
        
        return ans;
    }
        
    vector<string> possibleWords(int a[], int N)
    {
        map<int,string> mp;
        
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        return solve(a,0,mp,N);
    }
};